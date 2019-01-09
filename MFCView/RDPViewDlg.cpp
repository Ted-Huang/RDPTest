#include "stdafx.h"
#include "RDPViewDlg.h"

CRDPViewDlg::CRDPViewDlg(CWnd* pParent) : CDialogEx()
{
	m_pParentWnd = pParent;
	Init();
	InitUiRectPos();
	InitUi(); 
}

CRDPViewDlg::~CRDPViewDlg()
{
	Finalize();
}

void CRDPViewDlg::Init()
{
	memset(m_xUi, 0, sizeof(m_xUi));
}
void CRDPViewDlg::Finalize()
{
	DestroyUi();
}
void CRDPViewDlg::InitUiRectPos()
{
	POINT ptBase = { 0, 0 };
	POINT ptSize = { 0, 0 };
	for (int i = UI_POS_ITEM_BEGIN; i < UI_POS_ITEM_END; i++){
		UINT uImgId = 0;
		UINT uLanId = 0;
		switch (i){
		case UI_POS_BTN_CONNECT:
			ptBase = { 140, 10 };
			ptSize = { 1140, 860 };
			break;
		}
		m_xUi[i].rcUi = { ptBase.x, ptBase.y, ptBase.x + ptSize.x, ptBase.y + ptSize.y };
	}
}
void CRDPViewDlg::InitUi()
{
}
void CRDPViewDlg::DestroyUi()
{

}

BOOL CRDPViewDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	return TRUE;
}

CDynDialogEx::CDynDialogEx(CWnd* pParent /*=NULL*/)
	: CDialog()
{
	m_pParentWnd = pParent;
	m_strCaption = _T("");
	//m_pFont = NULL;
	m_wFontSize = 0;
}

CDynDialogEx::~CDynDialogEx()
{
}

INT_PTR CDynDialogEx::DoModal()
{
	//
	// Get font info from mainwindow of the application
	CFont* pParentFont =  m_pParentWnd->GetFont();

	if (pParentFont == NULL && AfxGetApp()->m_pActiveWnd != NULL) {
		pParentFont = AfxGetApp()->m_pActiveWnd->GetFont();
	}
	LOGFONT LogFont;
	memset(&LogFont, 0x00, sizeof(LogFont));
	if (pParentFont != NULL) {
		pParentFont->GetLogFont(&LogFont);
	}
	else {
		_tcscpy_s(LogFont.lfFaceName, LF_FACESIZE, _T("MS Sans Serif"));
		LogFont.lfHeight = 8;
	}

	//Prework for setting font in dialog...
	int cWC = _tcslen(LogFont.lfFaceName) + 1;

	int nFontNameLen = cWC + 1;
	WCHAR *szFontName = new WCHAR[nFontNameLen];
	// Copy the string
	_tcscpy_s(szFontName, nFontNameLen, LogFont.lfFaceName);

	szFontName[cWC] = 0;
	nFontNameLen = (cWC)* sizeof(WCHAR);

	if (m_wFontSize == 0) {
		m_wFontSize = (unsigned short)LogFont.lfHeight;
	}

	//Prework for setting caption in dialog...
	cWC = _tcslen(m_strCaption) + 1;

	int szBoxLen = cWC + 1;
	WCHAR *szBoxCaption = new WCHAR[szBoxLen];
	// Copy the string
	_tcscpy_s(szBoxCaption, szBoxLen, m_strCaption);

	szBoxCaption[cWC] = 0;
	szBoxLen = (cWC)* sizeof(WCHAR);

	INT_PTR iRet = -1;
	//Here 's the stuff to build the dialog template in memory
	//without the controls being in the template
	//(Our first try, was this same template with some additional code
	//for each control placed on it, that's why this class is cold Ex :)
	//This gave some problems on WIN9x systems, where EDIT boxes
	//were not shown with 3D-look, but as flat controls)
	int nBufferSize = sizeof(DLGTEMPLATE) + (2 * sizeof(WORD)) /*menu and class*/ + szBoxLen /*size of caption*/
		+ sizeof(WORD) /*fontsize*/ + nFontNameLen /*size of fontname*/;

	HLOCAL hLocal = LocalAlloc(LHND, nBufferSize);
	if (hLocal != NULL) {
		BYTE*	pBuffer = (BYTE*)LocalLock(hLocal);
		if (pBuffer == NULL) {
			LocalFree(hLocal);
			AfxMessageBox(_T("CDynDialogEx::DoModal() : LocalLock Failed"));
		}
		BYTE *pdest = pBuffer;

		m_DialogTemplate.x = 0;
		m_DialogTemplate.y = 0;
		m_DialogTemplate.cx = 800;
		m_DialogTemplate.cy = 800;
		// transfer DLGTEMPLATE structure to the buffer
		memcpy(pdest, &m_DialogTemplate, sizeof(DLGTEMPLATE));	// DLGTemplate
		pdest += sizeof(DLGTEMPLATE);
		*(WORD*)pdest = 0;									// no menu						 -- WORD to say it is 0 bytes
		pdest += sizeof(WORD);								// Increment
		*(WORD*)(pdest + 1) = 0;							// use default window class -- WORD to say it is 0 bytes
		pdest += sizeof(WORD);								// Increment
		memcpy(pdest, szBoxCaption, szBoxLen);			// Caption
		pdest += szBoxLen;

		*(WORD*)pdest = m_wFontSize;						// font size
		pdest += sizeof(WORD);
		memcpy(pdest, szFontName, nFontNameLen);		// font name
		pdest += nFontNameLen;
	
		
		//Next lines to make sure that MFC makes no ASSERTION when PREVIOUS/NEXT is pressed:)
		if (m_lpDialogTemplate != NULL) {
			m_lpDialogTemplate = NULL;
		}
		//this->MoveWindow(0, 0, 800, 700);
		InitModalIndirect((LPDLGTEMPLATE)pBuffer, m_pParentWnd);
		iRet = CDialog::DoModal();

		LocalUnlock(hLocal);
		LocalFree(hLocal);

		delete[] szBoxCaption;
		delete[] szFontName;
		return iRet;
	}
	else {
		AfxMessageBox(_T("CDynDialogEx::DoModal() : LocalAllock Failed"));
		return -1;
	}
}
