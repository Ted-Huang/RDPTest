
// AOIRDPSessionDlg.h : ���Y��
//

#pragma once
#include "RDPSession.h"

// CAOIRDPSessionDlg ��ܤ��
class CAOIRDPSessionDlg : public CDialogEx
{
// �غc
public:
	CAOIRDPSessionDlg(CWnd* pParent = NULL);	// �зǫغc�禡

// ��ܤ�����
	enum { IDD = IDD_AOIRDPSESSION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩

private:
	void Init();

// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnRequest(WPARAM wp, LPARAM lp);
	DECLARE_MESSAGE_MAP()
private:
	void SendConnectionString();
private:
	CRDPSession m_xRDPSession;
};