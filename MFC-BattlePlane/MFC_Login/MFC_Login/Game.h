#pragma once
#include "MyPlane.h"
#include "Scene.h"


// CGame 对话框

class CGame : public CDialogEx
{
	DECLARE_DYNAMIC(CGame)
public:
	CMyPlane *myplane;
	BOOL isProtect;//标记是否开启防护罩
	CMyRect rect;
public:
	CGame(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGame();
	void draw();
	void play();
// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

};
