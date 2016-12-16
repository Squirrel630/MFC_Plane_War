#pragma once


// PlaneWar 对话框

class PlaneWar : public CDialogEx
{
	DECLARE_DYNAMIC(PlaneWar)

public:
	PlaneWar(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PlaneWar();

// 对话框数据
	enum { IDD = IDD_MFC_LOGIN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
