#include "InToSu.h"

int judge(char c)		//�ж�������Ƿ�Ϊ���š�Ԥ����š����֡��ո� 
{
	if(c == '(' || c == ')' || c == '*' || c == '/' || c == '#' || c == ' ' 
		|| c == '+' || c == '-' || (c > '0' && c <= '9')) return 1;
	return 0;
}

int priority(char c)	//�ж��Ƿ�Ϊ��������Լ������ȼ� 
{
	if(c == '+' || c == '-')return 1;
	else if(c == '*' || c == '/')return 2;
	else return 0;
}

int main()
{
	LinkStack s;
	initLStack(&s);
	char c;
	ElemType e;
	int left_paren = 0;				//�����ų��ֵĴ��� 
	int right_paren = 0;			//�����ų��ֵĴ���
	printf("��������׺���ʽ��\n");
	do
	{
		char num[50] = {'\0'}; 
		int j = 0;
		int i = 0;					//i��j���ڴ����λ���� 
		scanf("%c",&c);				//�����ַ� 
		if(!judge(c))				//����ַ����������������˳� 
		{
			system("cls"); 
			printf("�����ʽ����\n");
			break;
		}
		if(c > '0' && c <= '9')
		{
			do
			{
				if(c > '0' && c <= '9')	//�ж������ַ�����һλ�ǲ������� 
				{
					num[i] = c;			//���뵽�ַ������� 
					++i;
					scanf("%c", &c);
				}else break;
			}while(1);
			for(j;j <= i; j++)			//������յ� 
				printf("%c", num[j]);
		}
		switch(c)
		{ 
			case '(':
					left_paren += 1;
			case '*':
			case '/':
				{
					pushLStack(&s, c);	//(��*��/��ֱ������� 
					break;
				}
			case ')':
				{
					right_paren += 1;
					if(left_paren != right_paren)	//���������Ų�ƥ��ʱ���˳� 
					{
						system("cls");
						printf("����ԭ����������������ƥ�䣡\n");
						return 0;
					}
					do
					{
						popLStack(&s, &e);
						if(e != '(') printf("%c",e);	//��û��������ʱ��һֱ��� 
						else break;
					}while(1);
					break;
				}
			case '+':
			case '-':
				{
					if(s.top == NULL || priority(s.top->data) == 1 || s.top->data == '(')
						pushLStack(&s, c);				//����ջΪ�գ�����ջ������+��-����ʱ 
					else if(priority(s.top->data) == 2)	//��Ϊ*��/ʱ 
						{
							do
							{
								if(getTopLStack(&s, &e))	//��ջ����Ԫ��ʱ 
								{
									if(priority(e))			//��ջ��Ԫ��Ϊ�������ʱ���ջ 
									{
										popLStack(&s, &e);
										printf("%c",e);
									}else break;
								}else break;
							}while(1);
							pushLStack(&s, c);				//�ó�ջ�ķ��ų���󣬽���ǰ������ջ 
						}
					break; 
				}
			case '#':										//����#��������ʱ������ջ���ȫ��Ԫ����� 
				{
					do
					{
						if(popLStack(&s, &e))
						{
							printf("%c",e);
						}else break;
					}while(1);
				}
		}
		if(c == '#')break;
	}while(1);
	fflush(stdin);
	getchar();
}
