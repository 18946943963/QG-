#include "LinkStack.h"

int main()
{
	LinkStack s;		//����
	initLStack(&s);
	char c;
	ElemType e;			
	int length;			//���ճ��� 
	do									//��һ��whileѭ��ʵ�ֹ��ܶ��ʹ�� 
	{
		system("cls");
		printf("        ��ջ\n");
	    printf("     (ջ�ѳ�ʼ��)\n\n");
	    printf("     0.����ջ��������Ҫ������\n"); 
	    printf("     1.�ж�ջ�Ƿ�Ϊ��\n");
	    printf("     2.�õ�ջ��Ԫ��\n");
	    printf("     3.���ջ\n");
	    printf("     4.����ջ\n");
	    printf("     5.���ջ�ĳ���\n");
	    printf("     6.��ջ\n");
	    printf("     7.��ջ\n");
	    printf("     8.�˳�\n\n");
	    printf("�������Ӧ������(0-8)��");
		scanf("%c",&c);					//����ѡ������ 
		fflush(stdin);
		switch(c)						//��������ѡ����ö�Ӧ�ĺ��� 
		{
			case '0'://���� 
				{
					CreateLStack(&s);
					printf("������������ջΪ:\n");
					printLStack(&s);
					break;
				}
			case '1'://�ж��Ƿ�Ϊ�� 
				{
					if(isEmptyLStack(&s))
						printf("��ǰ��ջΪ��");
					else
					{
						printf("��ǰ��ջ��Ϊ�գ���������������:\n");
						printLStack(&s);
					}
					break;
				}
			case '2'://ȡջ��Ԫ�� 
				{
					if(getTopLStack(&s, &e)) 
						printf("��ջ�Ķ�Ԫ����%c",e);
					else printf("����ջΪ�ա�\n");
					break;
				}
			case '3'://��� 
				{
					clearLStack(&s);
					break;
				}
			case '4'://���� 
				{
					destroyLStack(&s);
					break;
				}
			case '5'://�鿴���� 
				{
					LStackLength(&s, &length);
					printf("���������Ϊ��\n");
					printLStack(&s);
					break;
				}
			case '6'://��ջ 
				{
					printf("\n��������Ҫ��ջ�����ݣ�������ʱֻд���һ����\n");		//���벻��1-5ʱ����ʾ������� 
					do{
						scanf("%c",&e);
						if(e != '\n') break;	//���ʲô��û��������ѭ������ 
						else continue;
					}while(1);
					fflush(stdin);
					printf("��ջǰ������Ϊ��\n");
					printLStack(&s);
					pushLStack(&s, e);
					printf("��ջ�������Ϊ��\n");
					printLStack(&s);
					break;
				}
			case '7'://��ջ 
				{
					if(popLStack(&s, &e))
					{
						printf("%c �ǳ�ջ������\n",e);
						printf("��ջ�������Ϊ��\n");
						printLStack(&s);
					}
					else printf("����ջΪ�գ���ջʧ��\n");
					break;
				}
			case '8':
					break;
			default :
				{
					printf("�����������������!\n");
				}
			 
		}
		printf("\n���س��Լ���");
		fflush(stdin);
		getchar();
		if(c == '8')break; 			//������5ʱ����ʾ�˳�ѭ�������˳����� 
	}while(1);
	return 0;
}
