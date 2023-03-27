#include "link.h"

static LinkList tail = NULL;	//�������һ����� �ĵ�ַ 

void print(LinkList L)
{
	L = L->next;
	while(L)						//��L��Ϊ��ʱ����� 
	{
		printf("%c ",L->data);
		L = L->next;
	}
}

LinkList CreateLink(void)	//�������� 
{
	LinkList p1,p2,head;	//���ڰ��½ڵ�����������p2���ڴ����½�� 
	p1 = head = (LinkList)malloc(sizeof(Node));	//����ͷ��� 
	char a; 					//a���ڴ洢��������� 
	printf("���������Ա���Ҫ�洢�����ݣ��ÿո��������Ϊ������������#Ϊֹͣ���룩\n");
	do
	{
		scanf("%c",&a);
		if(a == ' ') continue;
		else if(a == '#') break;		//�ж�������Ƿ�Ϊ����������Ǹ������˳�ѭ�� 
		else if(a > '9' || a < '0')
			{
				printf("%c���ڹ涨��Χ�����Բ����������У�\n",a);
				continue;
			}
		p2 = (LinkList)malloc(sizeof(Node));	//�����½ڵ� 
		p1->next = p2;		//���½ڵ����������� 
		p2->data = a;		//����������ݴ����½�� 
		p1 = p2;			//p1��������ĩβ 
	}while(1);
	p1->next = NULL;		//ѭ������������ĩβ����nextָ��NULL 
	printf("���������������ǣ�\n");
	print(head);
	return head;
}

int main(void)
{
	LinkList head = CreateLink();		//����
	printf("���س��Լ�����\n");
	fflush(stdin);
	getchar();
	char c;
	do									//��һ��whileѭ��ʵ�ֹ��ܶ��ʹ�� 
	{
		system("cls");
		printf("��ѡ����Ҫ�Ĺ���:\n1����������ż����\n2���ҵ��������е�\n3���ж������Ƿ�ɻ�\n4����ת����\n5���˳�\n");	//��������б� 
		scanf("%c",&c);
		switch(c)						//��������ѡ����ö�Ӧ�ĺ��� 
		{
			case '1':
				{
					printf("\n��תǰ������Ϊ��\n");
					print(head);
					ParitySwap(head);					//��ת 
					printf("��ת�������Ϊ��\n");
					print(head);
					break;
				}
			case '2':
				{
					ElemType e = FindMid(head);		//ȡֵ 
					printf("\n����Ϊ��\n");
					print(head);
					printf("\n�м�����Ϊ��\n%c",e);
					break;
				}
			case '3':
				{
					int a = IfCycle(head);				//�ý�� 
					if(a)printf("\n��������ѭ������");
					else printf("\n��������ѭ������");
					break;
				}
			case '4':
				{
					printf("\n��תǰ��\n");
					print(head);
					printf("\n��ת��\n");
					RevertList_2(head);
					print(head);
					break;
				}
			case '5':break;
			default:
				{
					printf("�����������������\n");		//���벻��1-5ʱ����ʾ������� 
					break;
				}
		}
		printf("\n���س��Լ���");
		fflush(stdin);
		getchar();
		if(c == '5')break; 			//������5ʱ����ʾ�˳�ѭ�������˳����� 
	}while(1);
	return 0;
}
