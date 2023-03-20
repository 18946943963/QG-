#include <stdio.h>
#include <stdlib.h>
 
typedef int ElemType;

typedef struct Node
{
	ElemType data;
	Node *next;
}Node, *LinkList;

LinkList CreateLink(void)	//�������� 
{
	LinkList p1,p2,head;	//���ڰ��½ڵ�����������p2���ڴ����½�� 
	p1 = head = (LinkList)malloc(sizeof(Node));	//����ͷ��� 
	int a; 					//a���ڴ洢��������� 
	printf("���������Ա���Ҫ�洢�����ݣ��ÿո��������Ϊ������������-1Ϊֹͣ���룩\n");
	do
	{
		scanf("%d",&a);
		if(a<0) break;		//�ж�������Ƿ�Ϊ����������Ǹ������˳�ѭ�� 
		p2 = (LinkList)malloc(sizeof(Node));	//�����½ڵ� 
		p1->next = p2;		//���½ڵ����������� 
		p2->data = a;		//����������ݴ����½�� 
		p1 = p2;			//p1��������ĩβ 
	}while(1);
	p1->next = NULL;		//ѭ������������ĩβ����nextָ��NULL 
	return head;
}

int ListEmpty(LinkList L)	//�ж������Ƿ�Ϊ�� 
{
	if(L->next == NULL)	//ͷ����nextΪ�գ�������Ϊ�� 
		return 1;
	return 0;
}

void ClearList(LinkList *L)	//������� 
{
	LinkList p;				//p����ָ��Ҫfree�Ľ�� 
	while((*L)->next != NULL)	//��ͷ���û����һ�����ʱֹͣ 
	{
		p = (*L)->next;		//Ҫfree�Ľ�㸳��p 
		(*L)->next = p->next;	//*L��nextָ����һ����� 
		free(p);
	}
	p = NULL;
}

int ListLength(LinkList L)	//�������� 
{
	LinkList P = L->next;	//P���ڱ������� 
	int i = 1;			//i���ڼ�¼����� 
	while(P!=NULL)		//��Pָ��NULLʱ˵���������� 
	{
		P = P->next;
		++i;
	}
	return i;
}

void GetElem(LinkList L, int i, ElemType *e)	//��ȡ�����i������ 
{
	if(i<1 || i>ListLength(L))	//���iС��1���ߴ��������������ֱ�ӽ������� 
		return;
	LinkList p = L->next;	//p����ָ��Ҫ�ҵ��Ǹ�λ�õĽ�� 
	int j;
	for(j=1; j<i; j++)	//�ҵ�λ��
		p = p->next;
	*e = p->data;		//��ֵ 
}

int LocateElem(LinkList L, ElemType e)	//������e������ڼ���λ�� 
{
	LinkList p = L->next;	//p�������� 
	int i=1;				//��¼�ڼ���λ�� 
	while(p!=NULL)			//��p������ʱ��û�ҵķ���0 
	{
		if(p->data == e)	//�ҵ���ֱ�ӷ���i 
			return i;
		p = p->next;
		i++;
	}
	return 0;
}

void ListInsert(LinkList *L, int i, ElemType e)	//���������� 
{
	if(i<1 || i>ListLength(*L) + 1)	//��iС��1���ߴ�������ĩβ+1ʱ���������뷶Χ��ֱ���˳����� 
		return;
	LinkList Pr = (LinkList)malloc(sizeof(Node));	//�����½�� 
	LinkList P = (*L)->next;	//p�����ҵ������λ�õ�ǰһ��λ�� 
	Pr->data = e;
	int j;
	for(j=1; j<i-1; j++)		//��λ�� 
		P = P->next;
	Pr->next = P->next;			//���� 
	P->next = Pr;
}

void ListDelete(LinkList *L, int i, ElemType *e)	//����ɾ������ 
{
	if(i<1 || i>ListLength(*L))		//���iС��1���ߴ��������������ֱ�ӽ������� 
		return;
	LinkList Pr, P = (*L)->next;	//prΪɾ���Ľ���ǰһ����� 
	int j;
	for(j=1; j<i-1; j++)		//��λ�� 
		P = P->next;
	Pr = P->next;			//ɾ����PrΪǰ��ָ�� 
	P->next = Pr->next;
	*e = Pr->data;			//ɾ��ǰ�����ݴ浽*e 
	free(Pr);
	Pr = NULL;
}

