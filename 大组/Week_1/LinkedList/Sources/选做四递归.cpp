#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	Node *next;
}Node, *LinkList;

static LinkList tail = NULL;	//储存最后一个结点 的地址 

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

LinkList RevertList(LinkList p)
{
	if(p->next == NULL)	//表面已经到最后一个结点 
	{
		tail = p;		//储存最后一个结点 
		return p;
	}
	LinkList new_p = RevertList(p->next);	//往后递归 ，储存下一个结点 
	
	p->next->next = p;				//下一个结点指向当前的 
	p->next = NULL;					//指向空 
	
	return  new_p;
}

int main()
{
	LinkList head = CreateLink();
	printf("\n反转前：\n");
	print(head);
	printf("\n反转后：\n");
	RevertList(head->next);
	head->next = tail;		//头结点指向第一个结点 
	print(head);
	
	fflush(stdin);
	getchar();
	return 0;
}
