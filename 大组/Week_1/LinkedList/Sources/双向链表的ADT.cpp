#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DuLNode
{
	ElemType data;
	struct DuLNode *prior;	//指向前一个结点的指针 
	struct DuLNode *next;	//指向后一个结点的指针 
}DuLNode, *DuLinkList;

DuLinkList CreateLink(void)		//与前面的函数一致 
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

int DuListLength(DuLinkList L)	//求双向链表的长度 
{
	DuLinkList P = L->next;
	int i = 1;					//i统计遍历的次数，即链表的长度 
	while(P!=L)					//当p又指向头结点时说明已经遍历完了 
	{
		P = P->next;
		++i;
	}
	return i;
}

void DuListInsert(DuLinkList *L, int i, ElemType e)	//插入函数 //定义插入位置的原结点为第二个结点，其前一个结点为第一个结点 
{
	if(i<1 || i>DuListLength(*L) + 1)				//若i小于1或者大于链表末尾+1时，超出插入范围，直接退出函数 
		return;
	DuLinkList P = (DuLinkList)malloc(sizeof(DuLNode));
	DuLinkList Pr = (*L)->next;	//Pr指向插入位置的前一个结点 
	P->data = e;				//将数据赋值给结点 
	int j;
	for(j=1; j<i-1; j++)		//Pr找位置 
		Pr = Pr->next;
	P->next = Pr->next;			//插入结点的next指向第二个结点 
	Pr->next->prior = P;		//第二个结点prior指回插入结点 
	Pr->next = P;				//第一个结点next指向插入结点 
	P->prior = Pr;				//插入结点prior指向第一个结点 
}

void DuListDelete(DuLinkList *L, int i, ElemType *e)	//删除函数 //删除结点为第二个结点，前一个结点为第一个结点，后一个为第三个 
{
	if(i<1 || i>DuListLength(*L))	//如果i小于1或者大于链表个数，则直接结束函数 
		return;
	DuLinkList P, Pr = (*L)->next;	//P指向要删除的结点，Pr指向要删除结点的前一个结点 
	int j;
	for(j=1; j<i-1; j++)	//找到位置 
		Pr = Pr->next;
	P = Pr->next;			//连接上删除结点的前后两个结点 
	Pr->next = P->next;		//第一个结点连接第三个结点 
	P->next->prior = P;		//第三个结点prior指回第一个结点 
	*e = P->data;			//用*e储存要删除的数据 
	free(P);				// 删除结点 
	P = NULL;
}

void RevertPrint(DuLinkList L)	//逆向输出 
{
	DuLinkList p = L->prior;
	while(p!=L)					//当p指向头结点时，表示遍历完了 
	{
		printf("%d ",p->data);	//用prior反向遍历 
		p = p->prior;
	}
}
