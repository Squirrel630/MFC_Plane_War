// Game.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_Login.h"
#include "Game.h"
#include "afxdialogex.h"


// CGame �Ի���

IMPLEMENT_DYNAMIC(CGame, CDialogEx)

CGame::CGame(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGame::IDD, pParent)
{

}

CGame::~CGame()
{
}

void CGame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGame, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CGame ��Ϣ�������


//void CGame::OnTimer(UINT_PTR nIDEvent)
//{
//
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//
//	//˫����
//	CDC *pDC = GetDC();
//
//	//��ÿͻ�����������
//	GetClientRect(&rect);
//	//�ڴ滺��CDC
//	CDC cdc;
//
//	//�ڴ��г�����ʱͼ��Ļ���λͼ
//	CBitmap* cacheBitmap = new CBitmap;
//	//�õ�ǰ�豸CDC��ʼ������CDC
//	cdc.CreateCompatibleDC(pDC);
//	//��pDC�ͻ���λͼ�Ĺ�ϵ��cdc�����������λͼ�У�������֮����һ���Խ�����λͼ�������Ļ
//	cacheBitmap->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
//	//�滻cdcԭ���Ļ�����Ϊ����λͼ������cdc��������ݾ�д���˻���λͼ��
//	CBitmap *pOldBit = cdc.SelectObject(cacheBitmap);
//	
//	//scene.StickScene(&cdc, 0, rect);
//	//ˢ����ʾս��
//	if (myplane != NULL) {
//		myplane->Draw(&cdc,FALSE,isProtect);
//	}
//
//
//	//����������cdc�е��������͵�һ��������pDC�У����������Ļ��
//	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &cdc, 0, 0, SRCCOPY);
//	//�ͷŶ���cdc
//	cdc.DeleteDC();
//	//�ͷŻ���λͼ
//	cacheBitmap->DeleteObject();
//	//�ͷ�һ��pDC
//	ReleaseDC(pDC);
//	CDialogEx::OnTimer(nIDEvent);
//}
//
//void CGame::play(){
//	SetTimer(2,1000,NULL); 
//}

void CGame::draw()
{

	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//˫����
	CDC *pDC = GetDC();

	//��ÿͻ�����������
	//GetClientRect(&rect);
	CRect rect;
	CWnd *pWnd = GetDlgItem(IDC_STATIC);//����Ϊ�ؼ�ID��
	pWnd->GetClientRect(&rect);
	//�ڴ滺��CDC
	CDC cdc;

	//�ڴ��г�����ʱͼ��Ļ���λͼ
	CBitmap* cacheBitmap = new CBitmap;
	//�õ�ǰ�豸CDC��ʼ������CDC
	cdc.CreateCompatibleDC(pDC);
	//��pDC�ͻ���λͼ�Ĺ�ϵ��cdc�����������λͼ�У�������֮����һ���Խ�����λͼ�������Ļ
	cacheBitmap->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	//�滻cdcԭ���Ļ�����Ϊ����λͼ������cdc��������ݾ�д���˻���λͼ��
	CBitmap *pOldBit = cdc.SelectObject(cacheBitmap);
	
	//scene.StickScene(&cdc, 0, rect);
	//ˢ����ʾս��
	if (myplane != NULL) {
		myplane->Draw(&cdc,FALSE,isProtect);
	}


	//����������cdc�е��������͵�һ��������pDC�У����������Ļ��
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &cdc, 0, 0, SRCCOPY);
	//�ͷŶ���cdc
	cdc.DeleteDC();
	//�ͷŻ���λͼ
	cacheBitmap->DeleteObject();
	//�ͷ�һ��pDC
	ReleaseDC(pDC);
}