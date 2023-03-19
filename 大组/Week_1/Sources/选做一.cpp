#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;		//链表存储的数据的类型 

typedef struct Node			//定义链表的结构 
{
	ElemType data;
	Node *next;
}Node, *LinkList;

LinkList CreateLink(void)	//创建链表 
{
	LinkList p1,p2,head;	//用于把新节点连接上链表，p2用于创建新结点 
	p1 = head = (LinkList)malloc(sizeof(Node));	//创建头结点 
	int a; 					//a用于存储输入的数据 
	printf("请输入线性表所要存储的数据（用空格隔开，均为正整数，输入-1为停止输入）\n");
	do
	{
		scanf("%d",&a);
		if(a<0) break;		//判断输入的是否为负数，如果是负数则退出循环 
		p2 = (LinkList)malloc(sizeof(Node));	//创建新节点 
		p1->next = p2;		//把新节点连接上链表 
		p2->data = a;		//将输入的数据存入新结点 
		p1 = p2;			//p1到达链表末尾 
	}while(1);
	p1->next = NULL;		//循环结束，并让末尾结点的next指向NULL 
	return head;
}

int parity(ElemType e)		//该函数用于判断一个数是否为偶数 
{
	if(e%2 == 0)return 1;
	else return 0;			//偶数返回1，奇数返回0 
}

void ParitySwap(LinkList L)	//交换奇偶的函数 
{
	LinkList pr= L;			//pr指向要交换的两数的第一个数的前一个 
	LinkList p= pr->next;	//p指向要交换的两数的第一个数 
	LinkList p3;			//p3用于交换的中间指针 
	while(p->next)
	{
		if(parity(p->data) + parity(p->next->data) == 1)	//若两函数返回值的和为1，则说明这两个数为一奇一偶 
		{
			pr->next = p->next;								 //让pr的下一个结点为第二个结点 
			p3 = p->next;									//p3跳到第二个结点 
			p->next = p3->next;								//p指向第三个结点 
			p3->next = p;									//让第二个结点接到第一个结点后面 
			
			pr = p3;										//pr向前，p交换后已经向前了 
		}
		else
		{
			
			pr = p;											//不是的话，两个指针向前移动 
			p = pr->next;
		}
	}
}

void print(LinkList L)
{
	L = L->next;
	while(L)						//当L不为空时就输出 
	{
		printf("%d ",L->data);
		L = L->next;
	}
}

int main(void)
{
	LinkList head = CreateLink();		//创建 
	printf("\n调转前的链表为：\n");
	print(head);
	ParitySwap(head);					//调转 
	printf("调转后的链表为：\n");
	print(head);
	
	fflush(stdin);
	getchar();
	return 0;
}
