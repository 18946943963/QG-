#include "link.h"

int IfCycle(LinkList L)
{
	LinkList slow = L->next;			//慢指针 
	LinkList fast = slow->next;			//快指针 
	while(fast->next && fast->next->next)	//如果快指针的下一个结点或者他的下一个位置为NULL，则不可能是循环链表了，直接结束循环 
	{
		if(slow->data == fast->data)return 1;	//两个结点相同，返回1表示是循环链表 
		slow = slow->next;
		fast = fast->next->next;
	}
	return 0;
}

