
// RegTest.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CRegTestApp: 
// �аѾ\��@�����O�� RegTest.cpp
//

class CRegTestApp : public CWinApp
{
public:
	CRegTestApp();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CRegTestApp theApp;