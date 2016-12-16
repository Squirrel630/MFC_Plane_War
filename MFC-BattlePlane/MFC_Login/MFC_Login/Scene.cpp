// Scene.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Login.h"
#include "Scene.h"
#include "afxdialogex.h"

// CScene 对话框

IMPLEMENT_DYNAMIC(CScene, CDialogEx)

CScene::CScene(){

}

CScene::~CScene()
{
}

// CScene 消息处理程序
bool CScene::InitScene(){
	//加载开始图片
	this->images.Load(_T("res\\bk2.bmp"));
	CString str;
	if (images.IsNull())
		return false;

	//开始为真, 背景起始坐标为0
	this->isStart = true;
	this->beginY = 0;

	//播放背景音乐
	mciSendString(L"open sound\\background.mp3 alias bgm", NULL, 0, NULL);
	mciSendString(L"play bgm repeat", NULL, 0, NULL);
	return true;
}

void CScene::StickScene(CDC* pDC,int index, CRect rClient){
	//rClient.setCMyRect();
	pDC->SetStretchBltMode(COLORONCOLOR);

	//客户区高度
	int cltHeight = rClient.Height();
	int cltwidth = rClient.Width();
	rClient.bottom = cltHeight + beginY;
	rClient.top = beginY;
	rClient.right=rClient.left+cltwidth;
	this->images.StretchBlt(*pDC, rClient, SRCCOPY);
}