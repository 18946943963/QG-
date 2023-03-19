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

void print(LinkList L)
{
	L = L->next;
	while(L)
	{
		printf("%d ",L->data);
		L = L->next;
	}
}

void RevertList(LinkList head)
{
	LinkList p1,p2;
	p1 = p2 = head->next->next;
	head->next->next = NULL;
	while(p2)
	{
		p2 = p2->next;
		p1->next = head->next;
		head->next = p1;
		p1 = p2;
	}
}

int main()
{
	LinkList head = CreateLink();
	printf("\n��תǰ��\n");
	print(head);
	printf("\n��ת��\n");
	RevertList(head);
	print(head);
	
	fflush(stdin);
	getchar();
	return 0;
}
