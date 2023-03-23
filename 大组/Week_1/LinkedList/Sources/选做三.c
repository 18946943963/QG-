#include "link.h"

int IfCycle(LinkList L)
{
	LinkList slow = L->next;			//��ָ�� 
	LinkList fast = slow->next;			//��ָ�� 
	while(fast->next && fast->next->next)	//�����ָ�����һ��������������һ��λ��ΪNULL���򲻿�����ѭ�������ˣ�ֱ�ӽ���ѭ�� 
	{
		if(slow->data == fast->data)return 1;	//���������ͬ������1��ʾ��ѭ������ 
		slow = slow->next;
		fast = fast->next->next;
	}
	return 0;
}

