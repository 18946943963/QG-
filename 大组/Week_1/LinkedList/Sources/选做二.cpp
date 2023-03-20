#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	Node *next;
}Node, *LinkList;

LinkList CreateLink(void)	//创建链表 
{
	LinkList p1,p2,head;	//用于把新节点连接上链表，p2用于创建新结点 
	p1 = head = (LinkList)malloc(sizeof(Node));	//创建头结点 
	int a; 					//a用于存储输入的数据 
	printf("请输入线性表所要存储的数据（用空格隔开，均为正整数，输入-1为停止输入）\n");
	do
	{
		scanf("%d",&a);
		if(a<0) break;		//判断输入的是否为负数，如果是负数则退出循环 
		p2 = (LinkList)malloc(sizeof(Node));	//创建新节点 
		p1->next = p2;		//把新节点连接上链表 
		p2->data = a;		//将输入的数据存入新结点 
		p1 = p2;			//p1到达链表末尾 
	}while(1);
	p1->next = NULL;		//循环结束，并让末尾结点的next指向NULL 
	return head;
}

void print(LinkList L)
{
	L = L->next;
	while(L)
	{
		printf("%d ",L->data);
		L = L->next;
	}
}

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

int main(void)
{
	LinkList head = CreateLink();	//创建 
	ElemType e = FindMid(head);		//取值 
	printf("\n链表为：\n");
	print(head);
	printf("\n中间数据为：\n%d",e);
	
	fflush(stdin);
	getchar();
	return 0;
}
