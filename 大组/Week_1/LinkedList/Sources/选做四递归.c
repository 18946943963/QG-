#include "link.h"

LinkList RevertList_1(LinkList p)
{
	if(p->next == NULL)	//�����Ѿ������һ����� 
	{
		tail = p;		//�������һ����� 
		return p;
	}
	LinkList new_p = RevertList_1(p->next);	//����ݹ� ��������һ����� 
	
	p->next->next = p;				//��һ�����ָ��ǰ�� 
	p->next = NULL;					//ָ��� 
	
	return  new_p;
}

