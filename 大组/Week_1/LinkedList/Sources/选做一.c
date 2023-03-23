#include "link.h"

int parity(ElemType e)		//该函数用于判断一个数是否为偶数 
{
	if((e - '0')%2 == 0)return 1;
	else return 0;			//偶数返回1，奇数返回0 
}

void ParitySwap(LinkList L)	//交换奇偶的函数 	//pr指向第一个结点，p为第二个，p的next为第三个 
{
	LinkList pr= L;			//pr指向要交换的两数的第一个数的前一个 
	LinkList p= pr->next;	//p指向要交换的两数的第一个数 
	LinkList p3;			//p3用于交换的中间指针 
	while(p->next)
	{
		if(parity(p->data) + parity(p->next->data) == 1)	//若两函数返回值的和为1，则说明这两个数为一奇一偶 
		{
			pr->next = p->next;								 //让pr的next指向第二个结点 
			p3 = p->next;									//p3跳到第二个结点 
			p->next = p3->next;								//p指向第三个结点 
			p3->next = p;									//让第二个结点接到第一个结点后面 
			
			pr = p3;										//pr向前，p交换后已经向前了 
		}
		else
		{
			
			pr = p;											//不是的话，两个指针向前移动 
			p = pr->next;
		}
	}
}
