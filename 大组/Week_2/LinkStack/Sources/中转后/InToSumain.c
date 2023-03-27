#include "InToSu.h"

int judge(char c)		//判断输入的是否为括号、预算符号、数字、空格 
{
	if(c == '(' || c == ')' || c == '*' || c == '/' || c == '#' || c == ' ' 
		|| c == '+' || c == '-' || (c > '0' && c <= '9')) return 1;
	return 0;
}

int priority(char c)	//判断是否为运算符号以及其优先级 
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
	int left_paren = 0;				//左括号出现的次数 
	int right_paren = 0;			//右括号出现的次数
	printf("请输入中缀表达式：\n");
	do
	{
		char num[50] = {'\0'}; 
		int j = 0;
		int i = 0;					//i，j用于处理多位数字 
		scanf("%c",&c);				//接收字符 
		if(!judge(c))				//如果字符不包括在里面则退出 
		{
			system("cls"); 
			printf("输入格式有误！\n");
			break;
		}
		if(c > '0' && c <= '9')
		{
			do
			{
				if(c > '0' && c <= '9')	//判断数字字符的下一位是不是数字 
				{
					num[i] = c;			//加入到字符数组中 
					++i;
					scanf("%c", &c);
				}else break;
			}while(1);
			for(j;j <= i; j++)			//输出接收到 
				printf("%c", num[j]);
		}
		switch(c)
		{ 
			case '(':
					left_paren += 1;
			case '*':
			case '/':
				{
					pushLStack(&s, c);	//(、*、/是直接输出的 
					break;
				}
			case ')':
				{
					right_paren += 1;
					if(left_paren != right_paren)	//当左右括号不匹配时，退出 
					{
						system("cls");
						printf("错误！原因：左右括号数量不匹配！\n");
						return 0;
					}
					do
					{
						popLStack(&s, &e);
						if(e != '(') printf("%c",e);	//当没有遇到（时，一直输出 
						else break;
					}while(1);
					break;
				}
			case '+':
			case '-':
				{
					if(s.top == NULL || priority(s.top->data) == 1 || s.top->data == '(')
						pushLStack(&s, c);				//当链栈为空，或者栈顶还是+、-、（时 
					else if(priority(s.top->data) == 2)	//当为*、/时 
						{
							do
							{
								if(getTopLStack(&s, &e))	//当栈顶有元素时 
								{
									if(priority(e))			//当栈顶元素为运算符号时则出栈 
									{
										popLStack(&s, &e);
										printf("%c",e);
									}else break;
								}else break;
							}while(1);
							pushLStack(&s, c);				//该出栈的符号出完后，将当前符号入栈 
						}
					break; 
				}
			case '#':										//遇到#结束符号时，将链栈里的全部元素输出 
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
