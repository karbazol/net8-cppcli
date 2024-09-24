#include "pch.h"

#include "cppcli-mfccontrols-lib.h"

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



  class CWindowsFormsControlHostingViewImpl : public CWindowsFormsControlHostingView
  {
  public:
    CWindowsFormsControlHostingViewImpl() = default;

  protected:

    // mfc overrides
    virtual void OnDraw(CDC* pDC) override {}
  };

  CWindowsFormsControlHostingView* CreateWinFormsControlHostingView()
  {
    return new CWindowsFormsControlHostingViewImpl();
  }


}
