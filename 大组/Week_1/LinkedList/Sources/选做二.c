#include "link.h"

ElemType FindMid(LinkList L)
{
	LinkList slow = L->next;		//慢指针一次走一个结点 
	LinkList fast = slow->next;		//快指针一次走三个结点 
	while(fast->next && fast)		//如果快指针的下一个结点或者它自己为NULL，则已经满足条件了 
	{
		slow = slow->next;
		if(fast->next->next == NULL)	//当快指针的下一个位置为空，直接跳出循环，防止指向位置区域 
		{
			break;
		}
		fast = fast->next->next;
	}
	return slow->data;
}
