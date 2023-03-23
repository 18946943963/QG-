#include "link.h"

LinkList RevertList_1(LinkList p)
{
	if(p->next == NULL)	//链表已经到最后一个结点 
	{
		tail = p;		//储存最后一个结点 
		return p;
	}
	LinkList new_p = RevertList_1(p->next);	//往后递归 ，储存下一个结点 
	
	p->next->next = p;				//下一个结点指向当前的 
	p->next = NULL;					//指向空 
	
	return  new_p;
}

