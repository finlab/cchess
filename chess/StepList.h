// StepList.h: interface for the CStepList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STEPLIST_H__0142BEA0_2A62_11D4_9933_938D792DE10C__INCLUDED_)
#define AFX_STEPLIST_H__0142BEA0_2A62_11D4_9933_938D792DE10C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct STEPNODE				//CStepList�Ľ��
{
	STEPNODE* left;
	STEPNODE* right;
	CStep* Data;
};

class CStepList 
{
public:
	CStepList();	
	virtual ~CStepList();	//�ջ��ڴ�
	void Remove();			//ɾ��m_pCur ������н��(������*m_pCur)
	void Go(CStep*step);	//��Remove();Ȼ������һ���
	void RemoveAll();		//ɾ�����н��(������*m_pHead)
	BOOL IsEnd();			//m_pCur�Ƿ����һ���
	BOOL IsHead();			//m_pCur�Ƿ����m_pHead
	CStep* Redo();			//m_pCur����һ���
	CStep* Undo();			//m_pCurǰ��һ���

protected:
	STEPNODE* m_pHead;		//ջ��
	STEPNODE* m_pCur;		//ջβ(����|ɾ�� ��)
};

#endif // !defined(AFX_STEPLIST_H__0142BEA0_2A62_11D4_9933_938D792DE10C__INCLUDED_)
