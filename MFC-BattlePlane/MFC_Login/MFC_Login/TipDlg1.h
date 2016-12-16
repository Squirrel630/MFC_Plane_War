#pragma once


// CTipDlg1 对话框

class CTipDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTipDlg1)

public:
	CTipDlg1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTipDlg1();

// 对话框数据
	enum { IDD = IDD_TIP_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
