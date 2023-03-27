#include "LinkStack.h"

int main()
{
	LinkStack s;		//创建
	initLStack(&s);
	char c;
	ElemType e;			
	int length;			//接收长度 
	do									//用一个while循环实现功能多次使用 
	{
		system("cls");
		printf("        链栈\n");
	    printf("     (栈已初始化)\n\n");
	    printf("     0.往链栈输入你想要的数据\n"); 
	    printf("     1.判断栈是否为空\n");
	    printf("     2.得到栈顶元素\n");
	    printf("     3.清空栈\n");
	    printf("     4.销毁栈\n");
	    printf("     5.检测栈的长度\n");
	    printf("     6.入栈\n");
	    printf("     7.出栈\n");
	    printf("     8.退出\n\n");
	    printf("请输入对应的数字(0-8)：");
		scanf("%c",&c);					//接收选择的序号 
		fflush(stdin);
		switch(c)						//根据输入选择调用对应的函数 
		{
			case '0'://创建 
				{
					CreateLStack(&s);
					printf("你所创建的链栈为:\n");
					printLStack(&s);
					break;
				}
			case '1'://判断是否为空 
				{
					if(isEmptyLStack(&s))
						printf("当前链栈为空");
					else
					{
						printf("当前链栈不为空，储存了以下数据:\n");
						printLStack(&s);
					}
					break;
				}
			case '2'://取栈顶元素 
				{
					if(getTopLStack(&s, &e)) 
						printf("链栈的顶元素是%c",e);
					else printf("该链栈为空。\n");
					break;
				}
			case '3'://清除 
				{
					clearLStack(&s);
					break;
				}
			case '4'://销毁 
				{
					destroyLStack(&s);
					break;
				}
			case '5'://查看长度 
				{
					LStackLength(&s, &length);
					printf("储存的数据为：\n");
					printLStack(&s);
					break;
				}
			case '6'://入栈 
				{
					printf("\n请输入你要入栈的数据（输入多个时只写入第一个）\n");		//输入不是1-5时，提示输入错误 
					do{
						scanf("%c",&e);
						if(e != '\n') break;	//如果什么都没有输入则循环继续 
						else continue;
					}while(1);
					fflush(stdin);
					printf("入栈前的数据为：\n");
					printLStack(&s);
					pushLStack(&s, e);
					printf("入栈后的数据为：\n");
					printLStack(&s);
					break;
				}
			case '7'://出栈 
				{
					if(popLStack(&s, &e))
					{
						printf("%c 是出栈的数据\n",e);
						printf("出栈后的数据为：\n");
						printLStack(&s);
					}
					else printf("该链栈为空，出栈失败\n");
					break;
				}
			case '8':
					break;
			default :
				{
					printf("输入错误请重新输入!\n");
				}
			 
		}
		printf("\n按回车以继续");
		fflush(stdin);
		getchar();
		if(c == '8')break; 			//当输入5时，表示退出循环，即退出程序 
	}while(1);
	return 0;
}
