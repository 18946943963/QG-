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
	LinkList slow = L->next;		//��ָ��һ����һ����� 
	LinkList fast = slow->next;		//��ָ��һ����������� 
	while(fast->next && fast)		//�����ָ�����һ�����������Լ�ΪNULL�����Ѿ����������� 
	{
		slow = slow->next;
		if(fast->next->next == NULL)	//����ָ�����һ��λ��Ϊ�գ�ֱ������ѭ������ָֹ��λ������ 
		{
			break;
		}
		fast = fast->next->next;
	}
	return slow->data;
}

int main(void)
{
	LinkList head = CreateLink();	//���� 
	ElemType e = FindMid(head);		//ȡֵ 
	printf("\n����Ϊ��\n");
	print(head);
	printf("\n�м�����Ϊ��\n%d",e);
	
	fflush(stdin);
	getchar();
	return 0;
}
