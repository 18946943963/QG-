#include"SuToIn.h"

int main()
{
	LinkStack s;
	initLStack(&s);
	char c;
	int num, num1, num2;
	num = num1 = num2 = 0;
	printf("�������׺���ʽ�����������֣������������Ҫ�ÿո����:\n");
	do
	{
		scanf("%c",&c);
		if(c >= '0' && c <= '9')				//��⵽����ʱ 
		{
			if((num = number(&s, c)) == -1)		//������ص���-1�������� 
			{
				printf("��������ֲ����Ϲ涨");
				return;
				fflush(stdin);
				getchar(); 
			}
			pushLStack(&s, num);				//д����ջ 
		}
		else if(priority(c))					//���������� 
		{
			if(popLStack(&s, &num1) && popLStack(&s, &num2))	//ȡֵ 
			{
				switch(c)
				{
					case '+':
						{
							num = num2  + num1;
							break;
						}
					case '-':
						{
							num = num2 - num1;
							break;
						}
					case '*':
						{
							num = num2 * num1;
							break;
						}
					case '/':
						{
							num = num2 / num1;
							break;
						}
				}
				pushLStack(&s, num);				//������д����ջ 
			}
			else 									//���ȡֵʧ�ܣ���������벻���� 
			{
				printf("�����ʽ�����޷��ó������\n");
				fflush(stdin);
				getchar();
				return;
			}
		}
		else if(c == '#')break;	//���������#���˳� 
	}while(1);
	if(s.count == 1)			//����ջ����Ϊ1ʱ��������ȷ�Ľ�� 
		printf("���ս��Ϊ%d",num);
	else printf("�����ʽ����û�еó���ȷ���");
	fflush(stdin);
	getchar();
}
