
// MFCSession.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CMFCSessionApp: 
// �аѾ\��@�����O�� MFCSession.cpp
//

class CMFCSessionApp : public CWinApp
{
public:
	CMFCSessionApp();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CMFCSessionApp theApp;