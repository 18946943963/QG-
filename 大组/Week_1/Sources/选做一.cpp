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
	printf("���������Ա���Ҫ�洢�����ݣ��ÿո��������Ϊ������������-1Ϊֹͣ���룩\n");
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

int parity(ElemType e)
{
	if(e%2 == 0)return 1;
	else return 0;
}

void ParitySwap(LinkList L)
{
	LinkList pr= L;
	LinkList p= pr->next;
	LinkList p3;
	while(p->next)
	{
		if(parity(p->data) + parity(p->next->data) == 1)
		{
			pr->next = p->next;
			p3 = p->next;
			p->next = p3->next;
			p3->next = p;
			
			pr = p3;
		}
		else
		{
			
			pr = p;
			p = pr->next;
		}
	}
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

int main(void)
{
	LinkList head = CreateLink();
	printf("\n��תǰ������Ϊ��\n");
	print(head);
	ParitySwap(head);
	printf("��ת�������Ϊ��\n");
	print(head);
	
	fflush(stdin);
	getchar();
	return 0;
}
