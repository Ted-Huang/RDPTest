
// MFCView.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CMFCViewApp: 
// �аѾ\��@�����O�� MFCView.cpp
//

class CMFCViewApp : public CWinApp
{
public:
	CMFCViewApp();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CMFCViewApp theApp;