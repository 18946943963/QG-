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
	if(a==1) 						//创建循环链表则让p1指向第一个结点 
		p1->next = head->next;
	else if(a==0)					//不创建则指向NULL 
		p1->next = NULL;
	else printf("\n输入错误！"); 
	return head;
}

int IfCycle(LinkList L)
{
	LinkList slow = L->next;			//慢指针 
	LinkList fast = slow->next;			//快指针 
	while(fast->next && fast->next->next)	//如果快指针的下一个结点或者他的下一个位置为NULL，则不可能是循环链表了，直接结束循环 
	{
		if(slow->data == fast->data)return 1;	//两个结点相同，返回1表示是循环链表 
		slow = slow->next;
		fast = fast->next->next;
	}
	return 0;
}

int main(void)
{
	LinkList head = CreateCycleLink();	//创建 
	int a = IfCycle(head);				//得结果 
	if(a)printf("\n该链表是循环链表。");
	else printf("\n该链表不是循环链表");
	
	fflush(stdin);
	getchar();
	return 0; 
}
