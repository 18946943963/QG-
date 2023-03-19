#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DuLNode
{
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode, *DuLinkList;

DuLinkList CreateLink(void)
{
	DuLinkList p1,p2,head;
	p1 = head = (DuLinkList)malloc(sizeof(DuLNode));
	int a; 
	printf("请输入线性表所要存储的数据（用空格隔开，均为正整数，输入-1为停止输入）\n");
	do
	{
		scanf("%d",&a);
		if(a<0) break;
		p2 = (DuLinkList)malloc(sizeof(DuLNode));
		p2->prior = p1;
		p1->next = p2;
		p2->data = a;
		p1 = p2;
	}while(1);
	p1->next = head;
	head->prior = p1;
	return head;
}

int DuListLength(DuLinkList L)
{
	DuLinkList P = L->next;
	int i = 1;
	while(P!=L)
	{
		P = P->next;
		++i;
	}
	return i;
}

void DuListInsert(DuLinkList *L, int i, ElemType e)
{
	if(i<1 || i>DuListLength(*L) + 1)
		return;
	DuLinkList P = (DuLinkList)malloc(sizeof(DuLNode));
	DuLinkList Pr = (*L)->next;
	P->data = e;
	int j;
	for(j=1; j<i-1; j++)
		Pr = Pr->next;
	P->next = Pr->next;
	Pr->next->prior = P;
	Pr->next = P;
	P->prior = Pr;
}

void DuListDelete(DuLinkList *L, int i, ElemType *e)
{
	if(i<1 || i>DuListLength(*L))
		return;
	DuLinkList P, Pr = (*L)->next;
	int j;
	for(j=1; j<i-1; j++)
		Pr = Pr->next;
	P = Pr->next;
	Pr->next = P->next;
	P->next->prior = P;
	*e = P->data;
	free(P);
	P = NULL;
}

void RevertPrint(DuLinkList L)
{
	DuLinkList p = L->prior;
	while(p!=L)
	{
		printf("%d ",p->data);
		p = p->prior;
	}
}
