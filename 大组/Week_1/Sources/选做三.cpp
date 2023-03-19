#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	Node *next;
}Node, *LinkList;

LinkList CreateCycleLink(void)
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
	printf("����Ҫ����ѭ�������𣿣�1/0��\n");
	scanf("%d",&a);
	if(a==1) 
		p1->next = head->next;
	else if(a==0)
		p1->next = NULL;
	else printf("\n�������"); 
	return head;
}

int IfCycle(LinkList L)
{
	LinkList slow = L->next;
	LinkList fast = slow->next;
	while(fast->next && fast->next->next)
	{
		if(slow->data == fast->data)return 1;
		slow = slow->next;
		fast = fast->next->next;
	}
	return 0;
}

int main(void)
{
	LinkList head = CreateCycleLink();
	int a = IfCycle(head);
	if(a)printf("\n��������ѭ������");
	else printf("\n��������ѭ������");
	
	fflush(stdin);
	getchar();
	return 0; 
}
