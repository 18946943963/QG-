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



//��ջ
Status initLStack(LinkStack *s);//��ʼ��ջ
Status pushLStack(LinkStack *s,ElemType data);//��ջ
Status popLStack(LinkStack *s,ElemType *data);//��ջ
int priority(char c);//�ж��Ƿ�Ϊ��������Լ�����������ȼ�
int number(LinkStack *s, char c);//������Ķ�λ���ַ�����ת��Ϊ����

#endif 
