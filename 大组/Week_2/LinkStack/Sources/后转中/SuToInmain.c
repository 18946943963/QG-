#include"SuToIn.h"

int main()
{
	LinkStack s;
	initLStack(&s);
	char c;
	int num, num1, num2;
	num = num1 = num2 = 0;
	printf("请输入后缀表达式，数字与数字，数字与运算符要用空格隔开:\n");
	do
	{
		scanf("%c",&c);
		if(c >= '0' && c <= '9')				//检测到数字时 
		{
			if((num = number(&s, c)) == -1)		//如果返回的是-1则程序结束 
			{
				printf("输入的数字不符合规定");
				return;
				fflush(stdin);
				getchar(); 
			}
			pushLStack(&s, num);				//写入链栈 
		}
		else if(priority(c))					//如果是运算符 
		{
			if(popLStack(&s, &num1) && popLStack(&s, &num2))	//取值 
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
				pushLStack(&s, num);				//运算结果写入链栈 
			}
			else 									//如果取值失败，则表明输入不符合 
			{
				printf("输入格式有误，无法得出结果！\n");
				fflush(stdin);
				getchar();
				return;
			}
		}
		else if(c == '#')break;	//当输入的是#则退出 
	}while(1);
	if(s.count == 1)			//当链栈长度为1时，才是正确的结果 
		printf("最终结果为%d",num);
	else printf("输入格式有误，没有得出正确结果");
	fflush(stdin);
	getchar();
}
