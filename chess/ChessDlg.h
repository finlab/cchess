// ChessDlg.h : header file
//
#include "CoolButton.h"
#include "BaseClasses.h"
#include "StepList.h"
#include "Thinker.h"

#if !defined(AFX_CHESSDLG_H__AA41CA9E_A877_11D4_9A6C_973E5A1E3F59__INCLUDED_)
#define AFX_CHESSDLG_H__AA41CA9E_A877_11D4_9A6C_973E5A1E3F59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChessDlg dialog

class CChessDlg : public CDialog
{
// Construction
public:
	void TestCheck();
	CSetting m_Setting;
	BOOL OpenWeb();
	BOOL OpenEmail(void);
	BOOL OpenURL(const char * LinkName);
	CChessDlg(CWnd* pParent = NULL);	// standard constructor
	~CChessDlg();

// Dialog Data
	//{{AFX_DATA(CChessDlg)
	enum { IDD = IDD_CHESS_DIALOG };
	CCoolButton	m_btCut;
	CProgressCtrl	m_progressStep;
	CListBox	m_listStep;
	CCoolButton	m_btUndo;
	CCoolButton	m_btRedo;
	CCoolButton	m_btHelp;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:	
	BOOL m_bCheck[2];
	void New(void);			//�����:
	void New(CFace face);	//�����
	void Think();			//�õ��Լ��㲢��һ��
	void ShowStatus();		//���±�����(��ʾ��ǰ״̬)
	void Move(int man,int x,int y);	//�������ƶ���Ŀ������		
	void MB_DrawStar(int x,int y,int i);	//���ǵ�(MakeBoard �е���)
	void MakeBoard();		//������(*m_pdcBoard)
	void FixManMap();		//ÿ�θ���m_Faceʱ����,����m_nManMap
	void UpdateFace(CRect& rc);	//ˢ������ָ������
	void PickUp(int man);		//��������
	void PutDown(int x,int y);	//��������
	void EnableCommand(int n,BOOL benable=TRUE);//������ֹĳ������
	BOOL FaceToPoint(CPoint& point);	//����ת������λ����
	BOOL CanGo(int man,int x,int y);	//�ж��ܲ�����ĳ����
	BOOL CanGo(const CMove& move );		//�ж��ܲ�����ĳ����
	BOOL CanGo();						//�жϵ�ǰ�ܲ�����
	BOOL Go(int man,int x,int y);		//��ĳ����
	BOOL Go(CMove move);				//��ĳ����
	CRect MakeUpdateRect(CPoint p1,CPoint p2);	//ͨ�������������õ���������
	CString GetStepName(int man,int x,int y);	//ȡ���߷���

	CStepList m_StepList;		//�߷�ջ
	CPoint m_pointBeforePickUp;	//��������ӵ�ԭ������λ
	CPoint m_pointPickUp;		//��������ӵ���Ļλ��
	int m_nTimer;				//��ʱ��
	int m_nManPickUp;			//������������
	int m_nManMap[11][12];		//��¼���̸���λ��״̬(��������/�������)
	int m_nStepCount;			//��ǰ����
	HICON m_hIcon;				//����ͼ��
	HICON m_hIconUndo;			//���ͷ
	HICON m_hIconRedo;			//�Ҽ�ͷ
	HICON m_hIconHelp;			//�����ͷ
	HICON m_hIconCut;			//ȡ��
	HICON m_hIconMan[14];		//����ͼ��
	CBitmap m_Bitmap1;			//�� m_pdcBoard ����λͼ
	CBitmap m_Bitmap2;			//�� m_pdcBack ����λͼ
	BOOL m_bThinking;			//�����Ƿ����ڼ���
	CFace m_Face;				//�������
	CThinker m_Thinker;			//***
	CDC* m_pdcBoard;			//��������ͼ���� DC
	CDC* m_pdcBack;				//���� DC

	// Generated message map functions
	//{{AFX_MSG(CChessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAboutbox();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	afx_msg void OnFileBai();
	afx_msg void OnFileNew();
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
	afx_msg void OnFileOption();
	afx_msg void OnEditUndo();
	afx_msg void OnEditRedo();
	afx_msg void OnEditHelp();
	afx_msg void OnEditCut();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDblclkSteplist();
	afx_msg void OnHelpEmail();
	afx_msg void OnHelpWeb();
	afx_msg void OnFileThinkOption();
	afx_msg void OnHelpUse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	friend class CBaiDlg;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHESSDLG_H__AA41CA9E_A877_11D4_9A6C_973E5A1E3F59__INCLUDED_)
