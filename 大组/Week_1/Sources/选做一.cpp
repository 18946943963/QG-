#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;		//����洢�����ݵ����� 

typedef struct Node			//��������Ľṹ 
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

int parity(ElemType e)		//�ú��������ж�һ�����Ƿ�Ϊż�� 
{
	if(e%2 == 0)return 1;
	else return 0;			//ż������1����������0 
}

void ParitySwap(LinkList L)	//������ż�ĺ��� 
{
	LinkList pr= L;			//prָ��Ҫ�����������ĵ�һ������ǰһ�� 
	LinkList p= pr->next;	//pָ��Ҫ�����������ĵ�һ���� 
	LinkList p3;			//p3���ڽ������м�ָ�� 
	while(p->next)
	{
		if(parity(p->data) + parity(p->next->data) == 1)	//������������ֵ�ĺ�Ϊ1����˵����������Ϊһ��һż 
		{
			pr->next = p->next;								 //��pr����һ�����Ϊ�ڶ������ 
			p3 = p->next;									//p3�����ڶ������ 
			p->next = p3->next;								//pָ���������� 
			p3->next = p;									//�õڶ������ӵ���һ�������� 
			
			pr = p3;										//pr��ǰ��p�������Ѿ���ǰ�� 
		}
		else
		{
			
			pr = p;											//���ǵĻ�������ָ����ǰ�ƶ� 
			p = pr->next;
		}
	}
}

void print(LinkList L)
{
	L = L->next;
	while(L)						//��L��Ϊ��ʱ����� 
	{
		printf("%d ",L->data);
		L = L->next;
	}
}

int main(void)
{
	LinkList head = CreateLink();		//���� 
	printf("\n��תǰ������Ϊ��\n");
	print(head);
	ParitySwap(head);					//��ת 
	printf("��ת�������Ϊ��\n");
	print(head);
	
	fflush(stdin);
	getchar();
	return 0;
}
