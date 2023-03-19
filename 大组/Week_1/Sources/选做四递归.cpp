#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	Node *next;
}Node, *LinkList;

static LinkList tail = NULL;

LinkList CreateLink(void)
{
	LinkList p1,p2,head;
	p1 = head = (LinkList)malloc(sizeof(Node));
	int a; 
	printf("请输入线性表所要存储的数据（用空格隔开，均为正整数，输入-1为停止输入）\n");
	do
	{
		scanf("%d",&a);
		if(a<0) break;
		p2 = (LinkList)malloc(sizeof(Node));
		p1->next = p2;
		p2->data = a;
		if(head == p1)
			head->next = p2;
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

LinkList RevertList(LinkList p)
{
	if(p->next == NULL)
	{
		tail = p;
		return p;
	}
	LinkList new_p = RevertList(p->next);
	
	p->next->next = p;
	p->next = NULL;
	
	return  new_p;
}

int main()
{
	LinkList head = CreateLink();
	printf("\n反转前：\n");
	print(head);
	printf("\n反转后：\n");
	RevertList(head->next);
	head->next = tail;
	print(head);
	
	fflush(stdin);
	getchar();
	return 0;
}
