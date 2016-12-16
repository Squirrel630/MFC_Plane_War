// Scene.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_Login.h"
#include "Scene.h"
#include "afxdialogex.h"

// CScene �Ի���

IMPLEMENT_DYNAMIC(CScene, CDialogEx)

CScene::CScene(){

}

CScene::~CScene()
{
}

// CScene ��Ϣ�������
bool CScene::InitScene(){
	//���ؿ�ʼͼƬ
	this->images.Load(_T("res\\bk2.bmp"));
	CString str;
	if (images.IsNull())
		return false;

	//��ʼΪ��, ������ʼ����Ϊ0
	this->isStart = true;
	this->beginY = 0;

	//���ű�������
	mciSendString(L"open sound\\background.mp3 alias bgm", NULL, 0, NULL);
	mciSendString(L"play bgm repeat", NULL, 0, NULL);
	return true;
}

void CScene::StickScene(CDC* pDC,int index, CRect rClient){
	//rClient.setCMyRect();
	pDC->SetStretchBltMode(COLORONCOLOR);

	//�ͻ����߶�
	int cltHeight = rClient.Height();
	int cltwidth = rClient.Width();
	rClient.bottom = cltHeight + beginY;
	rClient.top = beginY;
	rClient.right=rClient.left+cltwidth;
	this->images.StretchBlt(*pDC, rClient, SRCCOPY);
}