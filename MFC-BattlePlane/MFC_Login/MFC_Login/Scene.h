#pragma once
#include <atlimage.h>
#include <Mmsystem.h>
#include "MyRect.h"

#pragma comment(lib, "Winmm.lib")
//
//struct ClienSize{
//	int Width;
//	int Height;
//};

class CScene{
	DECLARE_DYNAMIC(CScene)
public:
	int Width;
	int Height;
		CImage images;

private:
	int		beginY;//������Y����
	bool	isStart;//�Ƿ�ʼ
public:
	CScene();  // ��׼���캯��
	virtual ~CScene();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

	bool InitScene();//��ʼ������
	void StickScene(CDC* pDC, int index, CRect rClient);//����index-1��ʾ�����ʼͼƬ
	void ReleaseScene();//�ͷ��ڴ���Դ
protected:
	//virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	//DECLARE_MESSAGE_MAP()
};
