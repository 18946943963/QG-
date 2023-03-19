#include <stdio.h>
#include <stdlib.h>
 
typedef int ElemType;

typedef struct Node
{
	ElemType data;
	Node *next;
}Node, *LinkList;

LinkList CreateLink(void)
{
	LinkList p1,p2,head;
	p1 = head = (LinkList)malloc(sizeof(Node));
	head->next = p1;
	int a; 
	printf("请输入线性表所要存储的数据（用空格隔开，均为正整数，输入-1为停止输入）\n");
	do
	{
		scanf("%d",&a);
		if(a<0) break;
		p2 = (LinkList)malloc(sizeof(Node));
		p1->next = p2;
		p2->data = a;
		p1 = p2;
	}while(1);
	p1->next = NULL;
	return head;
}

int ListEmpty(LinkList L)
{
	if(L->next == NULL)
		return 1;
	return 0;
}

void ClearList(LinkList *L)
{
	LinkList p;
	while((*L)->next != NULL)
	{
		p = (*L)->next;
		(*L)->next = p->next;
		free(p);
	}
	p = NULL;
}

int ListLength(LinkList L)
{
	LinkList P = L->next;
	int i = 1;
	while(P!=NULL)
	{
		P = P->next;
		++i;
	}
	return i;
}

void GetElem(LinkList L, int i, ElemType *e)
{
	if(i<1 || i>ListLength(L))
		return;
	LinkList p = L->next;
	int j;
	for(j=1; j<i; j++)
		p = p->next;
	*e = p->data;
}

int LocateElem(LinkList L, ElemType e)
{
	LinkList p = L->next;
	int i=1;
	while(p!=NULL)
	{
		if(p->data == e)
			return i;
		p = p->next;
		i++;
	}
	return 0;
}

void ListInsert(LinkList *L, int i, ElemType e)
{
	if(i<1 || i>ListLength(*L) + 1)
		return;
	LinkList Pr = (LinkList)malloc(sizeof(Node));
	LinkList P = (*L)->next;
	Pr->data = e;
	int j;
	for(j=1; j<i-1; j++)
		P = P->next;
	Pr->next = P->next;
	P->next = Pr;
}

void ListDelete(LinkList *L, int i, ElemType *e)
{
	if(i<1 || i>ListLength(*L))
		return;
	LinkList Pr, P = (*L)->next;
	int j;
	for(j=1; j<i-1; j++)
		P = P->next;
	Pr = P->next;
	P->next = Pr->next;
	*e = Pr->data;
	free(Pr);
	Pr = NULL;
}

