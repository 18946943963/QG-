#ifndef SuToIn_H_INCLUDED
#define SuToIn_H_INCLUDED

#include<stdio.h>
#include<stdlib.h> 

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//链栈
Status initLStack(LinkStack *s);//初始化栈
Status pushLStack(LinkStack *s,ElemType data);//入栈
Status popLStack(LinkStack *s,ElemType *data);//出栈
int priority(char c);//判断是否为运算符，以及运算符的优先级
int number(LinkStack *s, char c);//将输入的多位数字符数字转换为整型

#endif 
