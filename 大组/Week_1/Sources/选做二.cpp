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

ElemType FindMid(LinkList L)
{
	LinkList slow = L->next;
	LinkList fast = slow->next;
	while(fast->next && fast)
	{
		slow = slow->next;
		if(fast->next->next == NULL)
		{
			break;
		}
		fast = fast->next->next;
	}
	return slow->data;
}

int main(void)
{
	LinkList head = CreateLink();
	ElemType e = FindMid(head);
	printf("\n����Ϊ��\n");
	print(head);
	printf("\n�м�����Ϊ��\n%d",e);
	
	fflush(stdin);
	getchar();
	return 0;
}
