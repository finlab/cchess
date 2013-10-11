#include "StdAfx.h"
#include "BaseDef.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//������ȫ�ֺ���ʵ��:

int rnd(const int& n)
   {
	static int seed=0,c1=29,c2=217,c3=1024;

	if (seed==0)seed=(UINT)::GetTickCount();

	seed=(seed*c1+c2)%c3;
	
	return seed*n/c3;
   }

BOOL  CanGo(int manmap[11][12],
		   const int & man,
		   const int & xfrom,
		   const int & yfrom,
		   const int & xto,
		   const int & yto)
{
	static int i,j;

	if(!IsNormal(ManToType[man],xto,yto))	//������Ӳ��ܷ���Ŀ��λ��
	{
		//������ǽ�|˧ (��|˧����"����")
		if(ManToType[man]!=RED_K&& ManToType[man]!=BLACK_K)return FALSE;

		else if(ManToType[man]==RED_K &&			//�ߵ���˧
			ManToType[manmap[xto][yto]]==BLACK_K)	//Ŀ���ǽ�
		{
			BOOL flag=FALSE;
			for(j= yfrom-1;j>0;j--)
			{
				if (manmap[xfrom][j]!=32)
				{
					if(ManToType[manmap[xfrom][j]]==BLACK_K)	//����
						flag=TRUE;
					break;				
				}
			}
			if(flag)return TRUE;
			else return FALSE;
		}
		else if(ManToType[manmap[xto][yto]]==RED_K)	//�ߵ��ǽ�,Ŀ����˧							
		{
			BOOL flag=FALSE;
			for(j= yfrom+1;j<11;j++)
			{
				if (manmap[xfrom][j]!=32)
				{
					if(ManToType[manmap[xfrom][j]]==RED_K)	//����
						flag=TRUE;	
					break;
				}
			}
			if(flag)return TRUE;
			else return FALSE;
		}
		else return FALSE;
	}

	//���漸���ж�Ŀ����Ƿ񼺷�������:
	if(SideOfMan[man]==0)
	{
		if(manmap[xto][yto]!=32&& SideOfMan[manmap[xto][yto]]==0)return FALSE;		
	}
	else if(SideOfMan[man]==1)
	{
		if(manmap[xto][yto]!=32&& SideOfMan[manmap[xto][yto]]==1)return FALSE;		
	}
	//--------------------------------

	//�����Ǹ����ӵĹ���:
	switch(ManToType[man])	
		{
		case RED_B:
			//������ͷ:
			if(yto > yfrom)return FALSE;
			//��ֻ��һ��ֱ��:
			if(yfrom-yto+abs(xto-xfrom)>1)return FALSE;	
			break;

		case BLACK_B:
			//�䲻��ͷ:
			if(yto < yfrom)return FALSE;
			//��ֻ��һ��ֱ��:
			if(yto-yfrom+abs(xto-xfrom)>1)return FALSE;	
			break;

		case RED_S:
		case BLACK_S:
			//ʿ��б��һ��:
			if(abs(yfrom-yto)>1||abs(xto-xfrom)>1)return FALSE;	
			break;

		case RED_X:
		case BLACK_X:
			//������:
			if(abs(xfrom-xto)!=2||abs(yfrom-yto)!=2)return FALSE;
			//����:
			if(manmap[(xfrom+xto)/2][(yfrom+yto)/2]!=32)return FALSE;
			break;

		case RED_K:
		case BLACK_K:
			//��˧ֻ��һ��ֱ��:
			if(abs(yfrom-yto)+abs(xto-xfrom)>1)return FALSE;
			break;

		case RED_J:
		case BLACK_J:
			//��ֻ����ֱ��:
			if(yfrom!=yto&&xfrom!=xto)return FALSE;	
			//��������·���в���������: -----------
			if(yfrom==yto)
			{
				if(xfrom<xto)
				{
					for(i=xfrom+1;i<xto;i++)
						if(manmap[i][yfrom]!=32)return FALSE;
				}
				else
				{
					for(i=xto+1;i<xfrom;i++)
						if(manmap[i][yfrom]!=32)return FALSE;
				}
			}
			else
			{
				if(yfrom<yto)
				{
					for(j=yfrom+1;j<yto;j++)
						if(manmap[xfrom][j]!=32)return FALSE;
				}
				else
				{
					for(j=yto+1;j<yfrom;j++)
						if(manmap[xfrom][j]!=32)return FALSE;
				}
			}
			//�����ǳ�---------------------------------
			break;

		case RED_P:
		case BLACK_P:
			//��ֻ����ֱ��:
			if(yfrom!=yto&&xfrom!=xto)return FALSE;	
			//�ڲ�����ʱ������·���в���������:------------------
			if(manmap[xto][yto]==32)
			{
				if(yfrom==yto)
				{
					if(xfrom<xto)
					{
						for(i=xfrom+1;i<xto;i++)
							if(manmap[i][yfrom]!=32)return FALSE;
					}
					else
					{
						for(i=xto+1;i<xfrom;i++)
							if(manmap[i][yfrom]!=32)return FALSE;
					}
				}
				else
				{
					if(yfrom<yto)
					{
						for(j=yfrom+1;j<yto;j++)
							if(manmap[xfrom][j]!=32)return FALSE;
					}
					else
					{
						for(j=yto+1;j<yfrom;j++)
							if(manmap[xfrom][j]!=32)return FALSE;
					}
				}
			}
			//�������ڲ�����-------------------------------------
			//����ʱ:=======================================
			else	
			{
				int count=0;
				if(yfrom==yto)
				{
					if(xfrom<xto)
					{
						for(i=xfrom+1;i<xto;i++)
							if(manmap[i][yfrom]!=32)count++;
						if(count!=1)return FALSE;
					}
					else
					{
						for(i=xto+1;i<xfrom;i++)
							if(manmap[i][yfrom]!=32)count++;
						if(count!=1)return FALSE;
					}
				}
				else
				{
					if(yfrom<yto)
					{
						for(j=yfrom+1;j<yto;j++)
							if(manmap[xfrom][j]!=32)count++;
						if(count!=1)return FALSE;
					}
					else
					{
						for(j=yto+1;j<yfrom;j++)
							if(manmap[xfrom][j]!=32)count++;
						if(count!=1)return FALSE;
					}
				}
			}
			//�������ڳ���ʱ================================
			break;	

		case RED_M:
		case BLACK_M:
			//������:
			if(!(
				(abs(xto-xfrom)==1&&abs(yto-yfrom)==2)
				||(abs(xto-xfrom)==2&&abs(yto-yfrom)==1)
				))return FALSE;
			
			//�����:
			if		(xto-xfrom==2){i=xfrom+1;j=yfrom;}
			else if	(xfrom-xto==2){i=xfrom-1;j=yfrom;}
			else if	(yto-yfrom==2){i=xfrom;j=yfrom+1;}
			else if	(yfrom-yto==2){i=xfrom;j=yfrom-1;}
			
			//�����:
			if(manmap[i][j]!=32)return FALSE;
			break;

		default:	
			break;
		}

	return TRUE;	//����Ĺ���ȫͨ��!
}

BOOL  IsNormal(const int & mantype,const int & x,const int & y)
{
	if(x<1||x>9||y<1||y>10)return FALSE;
	switch(mantype)
	{
	case RED_K:	
		//˧�����ں췽����:
		if( x>6|| x<4|| y<8)return FALSE;
		break;

	case RED_S:	
		//��ֻ���ڹ����ض���:
		if(!(
			( x==4&& y==10)||
			( x==4&& y==8)||
			( x==5&& y==9)||
			( x==6&& y==10)||
			( x==6&& y==8)
			))return FALSE;
		break;

	case RED_X:
		//�߸���λ:
		if(!(
			( x==1&& y==8)||
			( x==3&& y==10)||
			( x==3&& y==6)||
			( x==5&& y==8)||
			( x==7&& y==10)||
			( x==7&& y==6)||
			( x==9&& y==8)
			))return FALSE;
		break;

	case RED_B:
		//�������ڱ�λ��:
		if( y>7)return FALSE;
		//������ǰ���������ƶ�:
		if( y>5&& x%2==0)return FALSE;
		break;

	case BLACK_K:
		//˧�����ں췽����:
		if( x>6|| x<4|| y>3)return FALSE;
		break;

	case BLACK_S:
		//��ֻ���ڹ����ض���:
		if(!(
			( x==4&& y==1)||
			( x==4&& y==3)||
			( x==5&& y==2)||
			( x==6&& y==1)||
			( x==6&& y==3)
			))return FALSE;
		break;

	case BLACK_X:
		//�߸���λ:
		if(!(
			( x==1&& y==3)||
			( x==3&& y==1)||
			( x==3&& y==5)||
			( x==5&& y==3)||
			( x==7&& y==1)||
			( x==7&& y==5)||
			( x==9&& y==3)
			))return FALSE;
		break;

	case BLACK_B:
		//�������ڱ�λ��:
		if( y<4)return FALSE;
		//������ǰ���������ƶ�:
		if( y<6&& x%2==0)return FALSE;
		break;

	default:
		break;
	}
	return TRUE;
}

void  FixManMap(CFace & face, int map[11][12])
{
	memcpy(map,_defaultmap,132*sizeof(int));

	static CXY * pman;
	static int i;
	for(i=0;i<32;i++)
	{
		pman = & face.man[i];
		if(pman->x)
			map[pman->x][pman->y]=i;
	}
		
}



