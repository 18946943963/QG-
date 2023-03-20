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

int ListEmpty(LinkList L)	//判断链表是否为空 
{
	if(L->next == NULL)	//头结点的next为空，则链表为空 
		return 1;
	return 0;
}

void ClearList(LinkList *L)	//清空链表 
{
	LinkList p;				//p用于指向要free的结点 
	while((*L)->next != NULL)	//当头结点没有下一个结点时停止 
	{
		p = (*L)->next;		//要free的结点赋给p 
		(*L)->next = p->next;	//*L的next指向下一个结点 
		free(p);
	}
	p = NULL;
}

int ListLength(LinkList L)	//求链表长度 
{
	LinkList P = L->next;	//P用于遍历链表 
	int i = 1;			//i用于记录结点数 
	while(P!=NULL)		//当P指向NULL时说明遍历完了 
	{
		P = P->next;
		++i;
	}
	return i;
}

void GetElem(LinkList L, int i, ElemType *e)	//获取链表第i个数据 
{
	if(i<1 || i>ListLength(L))	//如果i小于1或者大于链表个数，则直接结束函数 
		return;
	LinkList p = L->next;	//p用于指向要找的那个位置的结点 
	int j;
	for(j=1; j<i; j++)	//找到位置
		p = p->next;
	*e = p->data;		//赋值 
}

int LocateElem(LinkList L, ElemType e)	//求数据e在链表第几个位置 
{
	LinkList p = L->next;	//p遍历链表 
	int i=1;				//记录第几个位置 
	while(p!=NULL)			//当p遍历完时还没找的返回0 
	{
		if(p->data == e)	//找到了直接返回i 
			return i;
		p = p->next;
		i++;
	}
	return 0;
}

void ListInsert(LinkList *L, int i, ElemType e)	//链表插入操作 
{
	if(i<1 || i>ListLength(*L) + 1)	//若i小于1或者大于链表末尾+1时，超出插入范围，直接退出函数 
		return;
	LinkList Pr = (LinkList)malloc(sizeof(Node));	//建立新结点 
	LinkList P = (*L)->next;	//p用于找到插入的位置的前一个位置 
	Pr->data = e;
	int j;
	for(j=1; j<i-1; j++)		//找位置 
		P = P->next;
	Pr->next = P->next;			//插入 
	P->next = Pr;
}

void ListDelete(LinkList *L, int i, ElemType *e)	//链表删除操作 
{
	if(i<1 || i>ListLength(*L))		//如果i小于1或者大于链表个数，则直接结束函数 
		return;
	LinkList Pr, P = (*L)->next;	//pr为删除的结点的前一个结点 
	int j;
	for(j=1; j<i-1; j++)		//找位置 
		P = P->next;
	Pr = P->next;			//删除，Pr为前置指针 
	P->next = Pr->next;
	*e = Pr->data;			//删除前将数据存到*e 
	free(Pr);
	Pr = NULL;
}

