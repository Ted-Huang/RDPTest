
// MFCViewDlg.h : ���Y��
//

#pragma once
#include "CRDPSRAPIViewer.h"

// CMFCViewDlg ��ܤ��
class CMFCViewDlg : public CDialogEx
{
private:
	enum{
		ITEM_START = 0, 
		ITEM_BTNCONNECT,
		ITEM_EDSESSTION,
		ITEM_VIEW,
		ITEM_END,
	};
// �غc
public:
	CMFCViewDlg(CWnd* pParent = NULL);	// �зǫغc�禡

// ��ܤ�����
	enum { IDD = IDD_MFCVIEW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩
private:
	void Init();

// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
	virtual BOOL OnInitDialog();
	afx_msg void OnConnect();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CButton* m_pBtnCreate;
	CEdit* m_pEdSession;
	CRDPSRAPIViewer* m_pViewer;
};
