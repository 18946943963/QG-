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
	printf("请输入线性表所要存储的数据（用空格隔开，均为正整数，输入-1为停止输入）\n");
	do
	{
		scanf("%d",&a);
		if(a<0) break;
		p2 = (LinkList)malloc(sizeof(Node));
		p1->next = p2;
		p2->data = a;
		p1 = p2;
	}while(1);
	printf("你想要创建循环链表吗？（1/0）\n");
	scanf("%d",&a);
	if(a==1) 
		p1->next = head->next;
	else if(a==0)
		p1->next = NULL;
	else printf("\n输入错误！"); 
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
	if(a)printf("\n该链表是循环链表。");
	else printf("\n该链表不是循环链表");
	
	fflush(stdin);
	getchar();
	return 0; 
}
