#include "link.h"

void RevertList_2(LinkList head)	//��ͷ���������Ȼ����ͷ�巨һ�������� 
{
	LinkList p1,p2;
	p1 = p2 = head->next->next;
	head->next->next = NULL;
	while(p2)
	{
		p2 = p2->next;
		p1->next = head->next;
		head->next = p1;
		p1 = p2;
	}
}
