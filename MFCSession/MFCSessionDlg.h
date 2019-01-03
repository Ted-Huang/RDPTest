
// MFCSessionDlg.h : 標頭檔
//

#pragma once
#include "CRDPSRAPISharingSession.h"
#include "CRDPSRAPIInvitation.h"
#include "CRDPSRAPIInvitationManager.h"
#include "CIRDPSessionEvents.h"
#include "CRDPSRAPIAttendee.h"
// CMFCSessionDlg 對話方塊
class CMFCSessionDlg : public CDialogEx
{
private:
	enum{
		ITEM_START = 0,
		ITEM_BTNCREATE,
		ITEM_EDSESSTION,
		ITEM_END,
	};
// 建構
public:
	CMFCSessionDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
	enum { IDD = IDD_MFCSESSION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援

private:
	void Init();

	void OnAttendeeConnected(COleDispatchDriver *pAttendee);
// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnCreateSession();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CButton* m_pBtnCreateSession;
	CEdit* m_pEdConnectString;
	CRDPSRAPISharingSession* m_pSession;
};
