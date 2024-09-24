
// cpp-mfcapp.h : main header file for the cpp-mfcapp application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCApp:
// See cpp-mfcapp.cpp for the implementation of this class
//

class CMFCApp : public CWinApp
{
public:
	CMFCApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	afx_msg void OnOpenWinformsControlEmbeddingView();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApp theApp;
