#pragma once 

// CWinFormsControlSite throws an exception when its GetProperty method is asked for DISPID_BORDERSTYLE. 
// this is triggered by changes of the windows configuration, e.g. changing the current theme.
// we provide some helpers here to avoid this behavior. throwing this exception may cause unwanted / unexpected behavior, especially in COM scenarios.

// NOTE: this hpp is duplicated in project "ControlUtils", because we don't have a 
// common project with both mfc and c++/cli dependency, used by both "ControlUtils" and "VisDotNetControls".
// please keep it synchronized with its sibling.

#include <memory>
#include <assert.h>
#include <afxwinforms.h>
#include <type_traits>
#include <afxwin.h>
extern const IID GUID_NULL;

#pragma region CWinFormsControlSite_NoOleException

/// <summary>
/// a drop-in replacement for CWinFormsControlSite not throwing in the aforementioned scenario.
/// </summary>
class CWinFormsControlSite_NoOleException : public CWinFormsControlSite
{
public:
  CWinFormsControlSite_NoOleException(COleControlContainer* pCtrlCont)
    : CWinFormsControlSite(pCtrlCont)
  {}

  void GetProperty(DISPID dwDispID, VARTYPE vtProp, void* pvProp) const override
  {
    if (dwDispID == DISPID_BORDERSTYLE)
    {
      *(short*)pvProp = 0;
      return;
    }
    CWinFormsControlSite::GetProperty(dwDispID, vtProp, pvProp);
  }

  virtual HRESULT CreateOrLoad(const CControlCreationInfo& creationInfo) override
  {
    // taken from CWinFormsControlSite::CreateOrLoad(creationInfo) without changes
    // calling the base class directly or removing this method causes application to hang / crash

    typedef System::Runtime::InteropServices::GCHandle GCHandle;
    HRESULT hr = E_FAIL;
    //Create an instance of the managed object and set the m_gcEventHelper
    //to reference it and hook HWND related events.
    ASSERT(creationInfo.IsManaged());
    System::Windows::Forms::Control^ pControl = nullptr;
    if (creationInfo.m_hk == CControlCreationInfo::ReflectionType)
    {
      System::Type^ pType = safe_cast<System::Type^>((GCHandle::operator GCHandle(System::IntPtr(creationInfo.m_nHandle))).Target);
      System::Object^ pObj = System::Activator::CreateInstance(pType);
      pControl = safe_cast<System::Windows::Forms::Control^>(pObj);

    }
    else if (creationInfo.m_hk == CControlCreationInfo::ControlInstance)
    {
      pControl = safe_cast<System::Windows::Forms::Control^>((GCHandle::operator GCHandle(System::IntPtr(creationInfo.m_nHandle))).Target);
    }

    if (pControl != nullptr)
    {
      m_gcEventHelper->Control::set(pControl);
      //Marshal the control into IUnknown for usage of MFC Native ActiveX code.
      System::IntPtr pUnknAsInt = System::Runtime::InteropServices::Marshal::GetIUnknownForObject(get_Control());
      IUnknown* pUnkn = static_cast<IUnknown*>(pUnknAsInt.ToPointer());
      if (pUnkn != NULL)
      {
        hr = pUnkn->QueryInterface(IID_IOleObject, (void**)&m_pObject);
        System::Runtime::InteropServices::Marshal::Release(pUnknAsInt);
      }
      if (SUCCEEDED(hr))
      {   //Now that m_pObject is set, call the original CreateOrLoad method.
        hr = COleControlSite::CreateOrLoad(GUID_NULL, NULL, FALSE, NULL);
      }
    }
    return hr; 
  }

};

#pragma endregion

template <typename T>
concept IsCWnd = std::is_base_of<CWnd, T>::value;

/// <summary>
/// when your CWnd-derived class hosts windows forms control, derive it from CWinFormsHostWnd_NoOleException<T> instead of deriving it from T.
/// this ensures that all contained windows forms controls will use CWinFormsControlSite_NoOleException. 
/// </summary>
template <IsCWnd BaseWnd>
class CWinFormsHostWnd_NoOleException : public BaseWnd
{
public:
  template <typename... Args>
  CWinFormsHostWnd_NoOleException(Args&&... args)
    : BaseWnd(args...)
  {}
protected:
  BOOL CreateControlSite(COleControlContainer* pContainer, COleControlSite** ppSite, UINT nID, REFCLSID clsid) override
  {
    if (clsid == CLSID_WinFormsControl)
    {
      *ppSite = new CWinFormsControlSite_NoOleException(pContainer);
      return TRUE;
    }
    return BaseWnd::CreateControlSite(pContainer, ppSite, nID, clsid);
  };
};

/// <summary>
/// a factory creating a CWinFormsControlSite_NoOleException when asked for a control site for windows forms controls
/// </summary>
class CWinFormsControlSite_NoOleException_Factory : public IControlSiteFactory
{
public:
  CWinFormsControlSite_NoOleException_Factory() { }
  COleControlSite* CreateSite(COleControlContainer* pCtrlCont, const CControlCreationInfo& creationInfo)
  {
    COleControlSite* pSite = NULL;
    if (InlineIsEqualGUID(creationInfo.m_clsid, CLSID_WinFormsControl))
    {
      pSite = new CWinFormsControlSite_NoOleException(pCtrlCont);
    }
    return pSite;
  }
};


/// <summary>
/// Used in scenarios where CWinFormsHostWnd_NoOleException cannot be used.
/// Registers CWinFormsControlSite_NoOleException_Factory while in scope.
/// As long as no other factory registrations take place while in scope, created managed controls will use a CWinFormsControlSite_NoOleException instead of a CWinFormsControlSite.
/// </summary>
class CWinFormsControlSite_NoOleException_Scope
{
public:
  CWinFormsControlSite_NoOleException_Scope()
  {
    mTheFactory = std::make_unique< CWinFormsControlSite_NoOleException_Factory>();
    AfxRegisterSiteFactory(mTheFactory.get());
  }

  ~CWinFormsControlSite_NoOleException_Scope()
  {
    AfxUnregisterSiteFactory(mTheFactory.get());
  }

  std::unique_ptr< CWinFormsControlSite_NoOleException_Factory> mTheFactory;
};
