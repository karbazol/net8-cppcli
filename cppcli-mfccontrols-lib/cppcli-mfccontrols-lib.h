#pragma once

#include <afxwin.h>

using namespace System;

namespace cppclimfccontrolslib
{
	class CWindowsFormsControlHostingView;
	class CWindowsFormsControlHostingFrame : public CFrameWnd
	{
	public:
		DLL_CPPCLI_MFCCONTROLS_LIB_API CWindowsFormsControlHostingFrame();

	protected:
		virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) override;


	private:
		CWindowsFormsControlHostingView* mView = nullptr;

	};


	class CWindowsFormsControlHostingView : public CView
	{
	};

	CWindowsFormsControlHostingView* CreateWinFormsControlHostingView();
}
