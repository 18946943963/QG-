#include "link.h"

ElemType FindMid(LinkList L)
{
	LinkList slow = L->next;		//��ָ��һ����һ����� 
	LinkList fast = slow->next;		//��ָ��һ����������� 
	while(fast->next && fast)		//�����ָ�����һ�����������Լ�ΪNULL�����Ѿ����������� 
	{
		slow = slow->next;
		if(fast->next->next == NULL)	//����ָ�����һ��λ��Ϊ�գ�ֱ������ѭ������ָֹ��λ������ 
		{
			break;
		}
		fast = fast->next->next;
	}
	return slow->data;
}
