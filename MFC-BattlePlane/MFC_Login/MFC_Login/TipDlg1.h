#pragma once


// CTipDlg1 �Ի���

class CTipDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTipDlg1)

public:
	CTipDlg1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTipDlg1();

// �Ի�������
	enum { IDD = IDD_TIP_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
