#include "link.h"

int parity(ElemType e)		//�ú��������ж�һ�����Ƿ�Ϊż�� 
{
	if((e - '0')%2 == 0)return 1;
	else return 0;			//ż������1����������0 
}

void ParitySwap(LinkList L)	//������ż�ĺ��� 	//prָ���һ����㣬pΪ�ڶ�����p��nextΪ������ 
{
	LinkList pr= L;			//prָ��Ҫ�����������ĵ�һ������ǰһ�� 
	LinkList p= pr->next;	//pָ��Ҫ�����������ĵ�һ���� 
	LinkList p3;			//p3���ڽ������м�ָ�� 
	while(p->next)
	{
		if(parity(p->data) + parity(p->next->data) == 1)	//������������ֵ�ĺ�Ϊ1����˵����������Ϊһ��һż 
		{
			pr->next = p->next;								 //��pr��nextָ��ڶ������ 
			p3 = p->next;									//p3�����ڶ������ 
			p->next = p3->next;								//pָ���������� 
			p3->next = p;									//�õڶ������ӵ���һ�������� 
			
			pr = p3;										//pr��ǰ��p�������Ѿ���ǰ�� 
		}
		else
		{
			
			pr = p;											//���ǵĻ�������ָ����ǰ�ƶ� 
			p = pr->next;
		}
	}
}
