
// AOIRDPSession.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CAOIRDPSessionApp: 
// �аѾ\��@�����O�� AOIRDPSession.cpp
//

class CAOIRDPSessionApp : public CWinApp
{
public:
	CAOIRDPSessionApp();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CAOIRDPSessionApp theApp;