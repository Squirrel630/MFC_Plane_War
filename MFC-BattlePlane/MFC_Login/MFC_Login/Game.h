#pragma once
#include "MyPlane.h"
#include "Scene.h"


// CGame �Ի���

class CGame : public CDialogEx
{
	DECLARE_DYNAMIC(CGame)
public:
	CMyPlane *myplane;
	BOOL isProtect;//����Ƿ���������
	CMyRect rect;
public:
	CGame(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGame();
	void draw();
	void play();
// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

};
