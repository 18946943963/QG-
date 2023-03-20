#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DuLNode
{
	ElemType data;
	struct DuLNode *prior;	//ָ��ǰһ������ָ�� 
	struct DuLNode *next;	//ָ���һ������ָ�� 
}DuLNode, *DuLinkList;

DuLinkList CreateLink(void)		//��ǰ��ĺ���һ�� 
{
	DuLinkList p1,p2,head;
	p1 = head = (DuLinkList)malloc(sizeof(DuLNode));
	int a; 
	printf("���������Ա���Ҫ�洢�����ݣ��ÿո��������Ϊ������������-1Ϊֹͣ���룩\n");
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

int DuListLength(DuLinkList L)	//��˫������ĳ��� 
{
	DuLinkList P = L->next;
	int i = 1;					//iͳ�Ʊ����Ĵ�����������ĳ��� 
	while(P!=L)					//��p��ָ��ͷ���ʱ˵���Ѿ��������� 
	{
		P = P->next;
		++i;
	}
	return i;
}

void DuListInsert(DuLinkList *L, int i, ElemType e)	//���뺯�� //�������λ�õ�ԭ���Ϊ�ڶ�����㣬��ǰһ�����Ϊ��һ����� 
{
	if(i<1 || i>DuListLength(*L) + 1)				//��iС��1���ߴ�������ĩβ+1ʱ���������뷶Χ��ֱ���˳����� 
		return;
	DuLinkList P = (DuLinkList)malloc(sizeof(DuLNode));
	DuLinkList Pr = (*L)->next;	//Prָ�����λ�õ�ǰһ����� 
	P->data = e;				//�����ݸ�ֵ����� 
	int j;
	for(j=1; j<i-1; j++)		//Pr��λ�� 
		Pr = Pr->next;
	P->next = Pr->next;			//�������nextָ��ڶ������ 
	Pr->next->prior = P;		//�ڶ������priorָ�ز����� 
	Pr->next = P;				//��һ�����nextָ������� 
	P->prior = Pr;				//������priorָ���һ����� 
}

void DuListDelete(DuLinkList *L, int i, ElemType *e)	//ɾ������ //ɾ�����Ϊ�ڶ�����㣬ǰһ�����Ϊ��һ����㣬��һ��Ϊ������ 
{
	if(i<1 || i>DuListLength(*L))	//���iС��1���ߴ��������������ֱ�ӽ������� 
		return;
	DuLinkList P, Pr = (*L)->next;	//Pָ��Ҫɾ���Ľ�㣬Prָ��Ҫɾ������ǰһ����� 
	int j;
	for(j=1; j<i-1; j++)	//�ҵ�λ�� 
		Pr = Pr->next;
	P = Pr->next;			//������ɾ������ǰ��������� 
	Pr->next = P->next;		//��һ��������ӵ�������� 
	P->next->prior = P;		//���������priorָ�ص�һ����� 
	*e = P->data;			//��*e����Ҫɾ�������� 
	free(P);				// ɾ����� 
	P = NULL;
}

void RevertPrint(DuLinkList L)	//������� 
{
	DuLinkList p = L->prior;
	while(p!=L)					//��pָ��ͷ���ʱ����ʾ�������� 
	{
		printf("%d ",p->data);	//��prior������� 
		p = p->prior;
	}
}
