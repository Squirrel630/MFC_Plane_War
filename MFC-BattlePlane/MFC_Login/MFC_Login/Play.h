#pragma once


// Play �Ի���

class Play : public CDialogEx
{
	DECLARE_DYNAMIC(Play)

public:
	Play(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Play();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
