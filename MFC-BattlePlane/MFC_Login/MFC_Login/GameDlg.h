#pragma once
#include "afxwin.h"
#include "MyPlane.h"
#include "Scene.h"
#include "MyRect.h"
#include "Bomb.h"
#include "Game.h"
#include "Enemy.h"
#include "Boss.h"
#include "Explosion.h"
#include "Ball.h"
#include "stdafx.h"

// CGameDlg 对话框

struct ClienSize{
	int Width;
	int Height;
};


class CGameDlg : public CDialogEx{
	DECLARE_DYNAMIC(CGameDlg)
private:
	bool begin; 
	bool isBoss;
	//bool isBOO
	bool over;
	int bossBlood;
	bool isPause;
	bool isUpdate;
	int speed;
	int enemycreat;
	int ballcreat;
	bool bossLoaded;
public:
	CMyPlane *myplane;
	CBall *ball;
	CRect rect;
	CGame game;
	CBoss *boss;
	CBomb * bomb;
	CEnemy *enemy;
	CExplosion *explosion;

	CObList enemyList;
	CObList bombList;
	CObList ballList;
	CObList explosionList;
	ClienSize clientsize;
	CScene	scene;//场景
	BOOL isProtect;//标记是否开启防护罩
public:
	CGameDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGameDlg();
	void gameOver(CDC* pDC,CDC& cdc,CBitmap* cacheBitmap);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void OnCreat();
	void GetClientSize();
	// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	int m_FlyTime;
	int m_Grade;
	int m_Blood;
	CString m_Honor;
	CStatic m_PlanePic;
	afx_msg void OnStnClickedGameSize();
	afx_msg void OnBnClickedCancel();
	//afx_msg void OnBnClickedCheck2();
	//afx_msg void OnBnClickedCheck4();
	//CButton m_isUpdate;
	//CButton m_isProtect;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedOk();
};
