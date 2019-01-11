
// MFCSessionDlg.h : ���Y��
//

#pragma once

#include "RdpEncomAPI.h"
#include "RDPSession.h"
// CMFCSessionDlg ��ܤ��
class CMFCSessionDlg : public CDialogEx
{
private:
	enum{
		ITEM_START = 0,
		ITEM_BTNCREATE,
		ITEM_EDSESSTION,
		ITEM_END,
	};
// �غc
public:
	CMFCSessionDlg(CWnd* pParent = NULL);	// �зǫغc�禡
	~CMFCSessionDlg();
// ��ܤ�����
	enum { IDD = IDD_MFCSESSION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩
	virtual BOOL PreTranslateMessage(MSG* pMsg);
private:
	void Init();
// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
	virtual BOOL OnInitDialog();
	afx_msg void OnCreateSession();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CButton* m_pBtnCreateSession;
	CEdit* m_pEdConnectString;

	CRDPSession xSession;
};
