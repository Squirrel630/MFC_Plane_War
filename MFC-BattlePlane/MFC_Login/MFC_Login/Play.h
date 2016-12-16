#pragma once


// Play 对话框

class Play : public CDialogEx
{
	DECLARE_DYNAMIC(Play)

public:
	Play(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Play();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
