#pragma once

#include "CRDPSRAPIViewer.h"

class CRDPViewDlg : public CDialogEx
{
	// Construction
public:
	CRDPViewDlg(CWnd* pParent);   // standard constructor
	~CRDPViewDlg();
private:
	void Init();
	void Finalize();
	void InitUiRectPos();
	void InitUi();
	void DestroyUi();

protected:
	virtual BOOL OnInitDialog();
	afx_msg void OnConnect();
	DECLARE_MESSAGE_MAP()

public:
	virtual INT_PTR DoModal();
							
protected:
	CWnd *m_pParentWnd;
	CString m_strCaption;
	DLGTEMPLATE m_DialogTemplate;
private:
	typedef struct UI_ITEM_{
		RECT rcUi;
		void *pCtrl;
	}UI_ITEM;
	enum{
		UI_POS_ITEM_BEGIN = 0,
		//BTN
		UI_POS_BTN_BEGIN,
		UI_POS_BTN_CONNECT = UI_POS_BTN_BEGIN,
		UI_POS_BTN_DISCONNECT,
		UI_POS_BTN_END,

		//CB
		UI_POS_CB_BEGIN,
		UI_POS_CB_SLAVES = UI_POS_CB_BEGIN,
		UI_POS_CB_END,

		//EDIT
		UI_POS_EDIT_BEGIN,
		UI_POS_EDIT_CONNTIONSTRING = UI_POS_EDIT_BEGIN,
		UI_POS_EDIT_END,

		//RDPVIEW
		UI_POS_RDPVIEW_BEGIN,
		UI_POS_RDPVIEW_RDPVIEW = UI_POS_RDPVIEW_BEGIN,
		UI_POS_RDPVIEW_END,
		UI_POS_ITEM_END,
	};
	UI_ITEM m_xUi[UI_POS_ITEM_END];
};