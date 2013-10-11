// BaseClasses.h: interface for the CFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASECLASSES_H__23936A45_A884_11D4_9A6C_973E5A1E3F59__INCLUDED_)
#define AFX_BASECLASSES_H__23936A45_A884_11D4_9A6C_973E5A1E3F59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CXY 	//X,Y��ռһ�ֽڵĵ���
{
public:
	CXY();
	CXY(int xx,int yy);
	CXY(CXY& xy);

	BOOL operator==(CXY& xy)const;
	BOOL operator!=(CXY& xy)const;
	CXY& operator=(CXY& xy);

	char x;
	char y;
};

class CMove	//�߷�
{
public:
	CMove(CMove& move);
	CMove();
	CMove& operator=(CMove& move);
	char man;				//���ߵ���
	char x;
	char y;					//�ߵ���λ��
};

class CStep	//�岽
{
public:
	CStep();

	char man;				//���ߵ���
	char eaten;				//���Ե���
	CXY from;				//�� from ��
	CXY to;					//�ߵ� to ��
};

class CFace 			//���
{
public:
	CFace();
	CFace(CFace& face);

	BOOL operator==(CFace& face)const;
	BOOL operator!=(CFace& face)const;
	CFace& operator=(CFace& face);

	BOOL Open(LPCSTR filename);			//���ļ���ȡ
	BOOL Save(LPCSTR filename);			//���浽�ļ�
	BOOL IsNormal();					//�Ƿ�Ϸ�
	void Reset();						//��Ϊ��׼���

	CXY man [32];						//32���ӵ�λ��(man[*].x==0����������)
	int side;							//�ߵ�һ�� RED|0-��;BLACK|1-��
};

class CSetting
{
public:
	BOOL IsNormal();
	void Reset();
	CSetting();
	BOOL Load();
	BOOL Save();
	UINT m_nCOrM[2];			//����[player]�õ��Ƿ����
	UINT m_nPlayer[2];			//����[color/side]�õ����ֺ�
	UINT m_nLevel;				//������ĵȼ�
	UINT m_nMode;				//�ֻ���ʽ(˭ִʲô��)
	
};

#endif // !defined(AFX_BASECLASSES_H__23936A45_A884_11D4_9A6C_973E5A1E3F59__INCLUDED_)
