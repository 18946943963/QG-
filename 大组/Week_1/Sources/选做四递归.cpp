#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	Node *next;
}Node, *LinkList;

static LinkList tail = NULL;	//�������һ����� �ĵ�ַ 

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

LinkList RevertList(LinkList p)
{
	if(p->next == NULL)	//�����Ѿ������һ����� 
	{
		tail = p;		//�������һ����� 
		return p;
	}
	LinkList new_p = RevertList(p->next);	//����ݹ� ��������һ����� 
	
	p->next->next = p;				//��һ�����ָ��ǰ�� 
	p->next = NULL;					//ָ��� 
	
	return  new_p;
}

int main()
{
	LinkList head = CreateLink();
	printf("\n��תǰ��\n");
	print(head);
	printf("\n��ת��\n");
	RevertList(head->next);
	head->next = tail;		//ͷ���ָ���һ����� 
	print(head);
	
	fflush(stdin);
	getchar();
	return 0;
}
