// MapFace.h: interface for the CMapFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAPFACE_H__069DD2EE_ADD6_11D4_9A6C_A237F78F8253__INCLUDED_)
#define AFX_MAPFACE_H__069DD2EE_ADD6_11D4_9A6C_A237F78F8253__INCLUDED_

#include "BaseClasses.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMapFace  
{
public:
	int m_nManMap[11][12];		//��¼���̸���λ��״̬(��������/�������)
	void FixManMap();		//ÿ�θ���m_Faceʱ����,����m_nManMap
	CFace m_Face;
	CMapFace();
	virtual ~CMapFace();

};

#endif // !defined(AFX_MAPFACE_H__069DD2EE_ADD6_11D4_9A6C_A237F78F8253__INCLUDED_)
