#pragma once


// PlaneWar �Ի���

class PlaneWar : public CDialogEx
{
	DECLARE_DYNAMIC(PlaneWar)

public:
	PlaneWar(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PlaneWar();

// �Ի�������
	enum { IDD = IDD_MFC_LOGIN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
