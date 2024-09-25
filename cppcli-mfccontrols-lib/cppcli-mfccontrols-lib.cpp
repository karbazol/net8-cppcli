#include "pch.h"

#include "cppcli-mfccontrols-lib.h"

#include <afxwinforms.h>
#include "WinFormsControlSiteSafe.hpp"

using winforms_lib::UserControl1;
namespace cppclimfccontrolslib
{
  CWindowsFormsControlHostingFrame::CWindowsFormsControlHostingFrame()
  {
    mView = CreateWinFormsControlHostingView();
  }

  BOOL CWindowsFormsControlHostingFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
  {
    CRect rect;
    GetClientRect(&rect);
    // Create the view.
    if (!mView->Create(nullptr, nullptr, AFX_WS_DEFAULT_VIEW, rect, this, AFX_IDW_PANE_FIRST, pContext))
    {
      return FALSE;
    }

    // Notify the view.
    //  mView->SendMessage(WM_INITIALUPDATE);
    SetActiveView(mView, FALSE);

    return TRUE;

  }



  class CWindowsFormsControlHostingViewImpl : public CWinFormsHostWnd_NoOleException<CWindowsFormsControlHostingView>
  {
  public:
    CWindowsFormsControlHostingViewImpl() = default;

  protected:

    // mfc overrides
    virtual void OnDraw(CDC* pDC) override {}

    // mfc callbacks
    DECLARE_MESSAGE_MAP()
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg int OnCreate(LPCREATESTRUCT lpcs);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);

    CWinFormsControl<UserControl1> mWinFormsControl;

  };

  BEGIN_MESSAGE_MAP(CWindowsFormsControlHostingViewImpl, CWindowsFormsControlHostingView)
    ON_WM_SIZE()
    ON_WM_CREATE()
    ON_WM_ERASEBKGND()
  END_MESSAGE_MAP()

  static const UINT ctrlID = 27120;


  int CWindowsFormsControlHostingViewImpl::OnCreate(LPCREATESTRUCT lpcs)
  {
    int const res = CWindowsFormsControlHostingView::OnCreate(lpcs);
    CRect clientRect;
    GetClientRect(&clientRect);

    mWinFormsControl.CreateManagedControl(WS_CHILD | WS_VISIBLE, clientRect, this, ctrlID);
    return res;
  }

  BOOL CWindowsFormsControlHostingViewImpl::OnEraseBkgnd(CDC* pDC)
  {
    return TRUE;
  }

  void CWindowsFormsControlHostingViewImpl::OnSize(UINT nType, int cx, int cy)
  {
    RECT rect;
    GetClientRect(&rect);
    if (mWinFormsControl.GetSafeHwnd())
    {
      mWinFormsControl.MoveWindow(&rect);
    }
  }

  CWindowsFormsControlHostingView* CreateWinFormsControlHostingView()
  {
    return new CWindowsFormsControlHostingViewImpl();
  }



}
