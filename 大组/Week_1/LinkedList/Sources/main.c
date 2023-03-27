#include "link.h"

static LinkList tail = NULL;	//储存最后一个结点 的地址 

void print(LinkList L)
{
	L = L->next;
	while(L)						//当L不为空时就输出 
	{
		printf("%c ",L->data);
		L = L->next;
	}
}

LinkList CreateLink(void)	//创建链表 
{
	LinkList p1,p2,head;	//用于把新节点连接上链表，p2用于创建新结点 
	p1 = head = (LinkList)malloc(sizeof(Node));	//创建头结点 
	char a; 					//a用于存储输入的数据 
	printf("请输入线性表所要存储的数据（用空格隔开，均为正整数，输入#为停止输入）\n");
	do
	{
		scanf("%c",&a);
		if(a == ' ') continue;
		else if(a == '#') break;		//判断输入的是否为负数，如果是负数则退出循环 
		else if(a > '9' || a < '0')
			{
				printf("%c不在规定范围，所以不计入链表中！\n",a);
				continue;
			}
		p2 = (LinkList)malloc(sizeof(Node));	//创建新节点 
		p1->next = p2;		//把新节点连接上链表 
		p2->data = a;		//将输入的数据存入新结点 
		p1 = p2;			//p1到达链表末尾 
	}while(1);
	p1->next = NULL;		//循环结束，并让末尾结点的next指向NULL 
	printf("你所创建的链表是：\n");
	print(head);
	return head;
}

int main(void)
{
	LinkList head = CreateLink();		//创建
	printf("按回车以继续！\n");
	fflush(stdin);
	getchar();
	char c;
	do									//用一个while循环实现功能多次使用 
	{
		system("cls");
		printf("请选择你要的功能:\n1、单链表奇偶调换\n2、找到单链表中点\n3、判断链表是否成环\n4、反转链表\n5、退出\n");	//输出功能列表 
		scanf("%c",&c);
		switch(c)						//根据输入选择调用对应的函数 
		{
			case '1':
				{
					printf("\n调转前的链表为：\n");
					print(head);
					ParitySwap(head);					//调转 
					printf("调转后的链表为：\n");
					print(head);
					break;
				}
			case '2':
				{
					ElemType e = FindMid(head);		//取值 
					printf("\n链表为：\n");
					print(head);
					printf("\n中间数据为：\n%c",e);
					break;
				}
			case '3':
				{
					int a = IfCycle(head);				//得结果 
					if(a)printf("\n该链表是循环链表。");
					else printf("\n该链表不是循环链表");
					break;
				}
			case '4':
				{
					printf("\n反转前：\n");
					print(head);
					printf("\n反转后：\n");
					RevertList_2(head);
					print(head);
					break;
				}
			case '5':break;
			default:
				{
					printf("输入错误请重新输入\n");		//输入不是1-5时，提示输入错误 
					break;
				}
		}
		printf("\n按回车以继续");
		fflush(stdin);
		getchar();
		if(c == '5')break; 			//当输入5时，表示退出循环，即退出程序 
	}while(1);
	return 0;
}
