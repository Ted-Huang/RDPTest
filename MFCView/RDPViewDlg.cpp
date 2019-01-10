#include "stdafx.h"
#include "RDPViewDlg.h"
#include "Resource.h"


IMPLEMENT_DYNCREATE(CRDPSRAPIViewer, CWnd)

void CRDPViewDlg::Init()
{
	memset(m_xUi, 0, sizeof(m_xUi));
}
void CRDPViewDlg::Finalize()
{
	DestroyUi();
}
#define CONTROL_HEIGHT	30
void CRDPViewDlg::InitUiRectPos()
{
	POINT ptBase = { 0, 0 };
	POINT ptSize = { 0, 0 };
	CRect rcClient;
	GetClientRect(rcClient);
	for (int i = UI_POS_ITEM_BEGIN; i < UI_POS_ITEM_END; i++){
		UINT uImgId = 0;
		UINT uLanId = 0;
		switch (i){
			//BTN
		case UI_POS_BTN_CONNECT:
			ptBase = { 0, 0 };
			ptSize = { 50, CONTROL_HEIGHT };
			break;
		case UI_POS_BTN_DISCONNECT:// no use
			ptBase = { 50, 0 };
			ptSize = { 50, CONTROL_HEIGHT };
			break;
			//CB
		case UI_POS_CB_SLAVES:
			ptBase = { 100, 0 };
			ptSize = { 50, CONTROL_HEIGHT };
			break;
			//edit
		case UI_POS_EDIT_CONNTIONSTRING: //for test
			ptBase = { 150, 0 };
			ptSize = { 1500, 30 };
			break;
			//view
		case UI_POS_RDPVIEW_RDPVIEW:
			ptBase = { 0, CONTROL_HEIGHT };
			ptSize = { rcClient.Width(), rcClient.Height() - CONTROL_HEIGHT };
			break;
		}

		m_xUi[i].rcUi = { ptBase.x, ptBase.y, ptBase.x + ptSize.x, ptBase.y + ptSize.y };
	}
}
void CRDPViewDlg::InitUi()
{
	CString strCaption;
	//BTN
	for (int i = UI_POS_BTN_BEGIN; i < UI_POS_BTN_END; i++){
		if (!m_xUi[i].pCtrl){
			m_xUi[i].pCtrl = new CButton();
			strCaption = (i == UI_POS_BTN_CONNECT) ? L"³s½u" : L"";
			((CButton*)m_xUi[i].pCtrl)->Create(strCaption, WS_CHILD | WS_TABSTOP | WS_VISIBLE, m_xUi[i].rcUi, this, i);
		}
	}
	//CB
	for (int i = UI_POS_CB_BEGIN; i < UI_POS_CB_END; i++){
		if (!m_xUi[i].pCtrl){
			m_xUi[i].pCtrl = new CComboBox();
			((CComboBox*)m_xUi[i].pCtrl)->Create(WS_CHILD | WS_TABSTOP | WS_VISIBLE | CBS_DROPDOWNLIST, m_xUi[i].rcUi, this, i);
		}
		if (m_pvConnectionString && m_xUi[UI_POS_CB_SLAVES].pCtrl){
			for (int i = 0; i < m_pvConnectionString->size(); i++){
				CString str;
				str.Format(_T("%d"), i);
				((CComboBox*)m_xUi[UI_POS_CB_SLAVES].pCtrl)->AddString(str);
			}

		}
	}
	//EDIT
	for (int i = UI_POS_EDIT_BEGIN; i < UI_POS_EDIT_END; i++){
		if (!m_xUi[i].pCtrl){
			m_xUi[i].pCtrl = new CEdit();
			((CEdit*)m_xUi[i].pCtrl)->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_LEFT | WS_BORDER, m_xUi[i].rcUi, this, i);
		}
	}
	//RDPVIEW
	for (int i = UI_POS_RDPVIEW_BEGIN; i < UI_POS_RDPVIEW_END; i++){
		if (!m_xUi[i].pCtrl){
			m_xUi[i].pCtrl = new CRDPSRAPIViewer();
			((CRDPSRAPIViewer*)m_xUi[i].pCtrl)->Create(L"", WS_CHILD | WS_VISIBLE, m_xUi[i].rcUi, this, i);
		}
	}

}
void CRDPViewDlg::DestroyUi()
{
	//BTN
	for (int i = UI_POS_BTN_BEGIN + 1; i < UI_POS_BTN_END; i++){
		if (m_xUi[i].pCtrl){
			CButton* pBtn = ((CButton*)m_xUi[i].pCtrl);
			pBtn->DestroyWindow();
			delete pBtn;
			pBtn = NULL;
		}
	}
	//CB
	for (int i = UI_POS_CB_BEGIN; i < UI_POS_CB_END; i++){
		if (m_xUi[i].pCtrl){
			CComboBox* pCB = ((CComboBox*)m_xUi[i].pCtrl);
			pCB->DestroyWindow();
			delete pCB;
			pCB = NULL;
		}
	}
	//EDIT
	for (int i = UI_POS_EDIT_BEGIN + 1; i < UI_POS_EDIT_END; i++){
		if (m_xUi[i].pCtrl){
			CEdit* pEdit = ((CEdit*)m_xUi[i].pCtrl);
			pEdit->DestroyWindow();
			delete pEdit;
			pEdit = NULL;
		}
	}

	//RDPVIEW
	for (int i = UI_POS_RDPVIEW_BEGIN + 1; i < UI_POS_RDPVIEW_END; i++){
		if (m_xUi[i].pCtrl){
			CRDPSRAPIViewer* pView = ((CRDPSRAPIViewer*)m_xUi[i].pCtrl);
			pView->DestroyWindow();
			delete pView;
			pView = NULL;
		}
	}

}


BEGIN_MESSAGE_MAP(CRDPViewDlg, CDialogEx)
	ON_BN_CLICKED(UI_POS_BTN_CONNECT, OnConnect)
END_MESSAGE_MAP()


BOOL CRDPViewDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CRect rcDesktop;
	// Get a handle to the desktop window
	HWND hDesktop = ::GetDesktopWindow();
	// Get the size of screen to the variable desktop
	::GetWindowRect(hDesktop, &rcDesktop);
	MoveWindow(0, 0, rcDesktop.Width(), rcDesktop.Height());

	Init();
	InitUiRectPos();
	InitUi();

	return TRUE;
}

void CRDPViewDlg::OnConnect()
{
	if (!m_xUi[UI_POS_RDPVIEW_RDPVIEW].pCtrl || !m_xUi[UI_POS_EDIT_CONNTIONSTRING].pCtrl){
		return;
	}

	int nSel = ((CComboBox*)m_xUi[UI_POS_CB_SLAVES].pCtrl)->GetCurSel();
	if (nSel == -1 || nSel >= m_pvConnectionString->size())
		return;

	CString strSession = m_pvConnectionString->at(nSel);
	CString strEdit;
	((CEdit*)m_xUi[UI_POS_EDIT_CONNTIONSTRING].pCtrl)->GetWindowText(strEdit);
	if (strEdit.GetLength() > 0)
		strSession = strEdit;
	try
	{
		((CRDPSRAPIViewer*)m_xUi[UI_POS_RDPVIEW_RDPVIEW].pCtrl)->Connect(strSession, L"groupName", L"");
	}
	catch (...)
	{
		AfxMessageBox(L"RDP error!");
	}
}

CRDPViewDlg::CRDPViewDlg(CWnd* pParent /*=NULL*/, vector<CString>* pvConnString)
	: CDialogEx()
{
	m_pParentWnd = pParent;
	m_strCaption = _T("");
	m_DialogTemplate.style = WS_CAPTION | WS_SYSMENU | WS_VISIBLE | DS_SETFONT;
	m_DialogTemplate.dwExtendedStyle = WS_EX_DLGMODALFRAME;
	m_pvConnectionString = pvConnString;
}

CRDPViewDlg::~CRDPViewDlg()
{
	Finalize();
}
//
INT_PTR CRDPViewDlg::DoModal()
{
	//
	// Get font info from mainwindow of the application
	CFont* pParentFont = m_pParentWnd->GetFont();

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
			AfxMessageBox(_T("CRDPViewDlg::DoModal() : LocalLock Failed"));
		}
		BYTE *pdest = pBuffer;

		// transfer DLGTEMPLATE structure to the buffer
		memcpy(pdest, &m_DialogTemplate, sizeof(DLGTEMPLATE));	// DLGTemplate
		pdest += sizeof(DLGTEMPLATE);
		*(WORD*)pdest = 0;									// no menu						 -- WORD to say it is 0 bytes
		pdest += sizeof(WORD);								// Increment
		*(WORD*)(pdest + 1) = 0;							// use default window class -- WORD to say it is 0 bytes
		pdest += sizeof(WORD);								// Increment
		memcpy(pdest, szBoxCaption, szBoxLen);			// Caption
		pdest += szBoxLen;

		*(WORD*)pdest = (unsigned short)LogFont.lfHeight;						// font size
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
		AfxMessageBox(_T("CRDPViewDlg::DoModal() : LocalAllock Failed"));
		return -1;
	}
}
