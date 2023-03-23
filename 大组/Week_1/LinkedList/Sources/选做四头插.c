#include "link.h"

void RevertList_2(LinkList head)	//把头结点拆出来，然后用头插法一个个插入 
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
