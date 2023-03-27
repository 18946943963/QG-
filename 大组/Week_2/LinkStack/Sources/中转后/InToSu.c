#include "InToSu.h" 
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s)
{
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s)
{
	if(s->count == 0)
		return SUCCESS;
	return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e)
{
	if(s->top == NULL)
	{
		return ERROR;
	}
	*e = s->top->data;
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->next = s->top;
	p->data = data;
	s->count += 1;
	s->top = p;
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data)
{
	if(s->top == NULL)
	{
		return ERROR;
	}
	LinkStackPtr p = s->top;
	*data = p->data;
	s->count -= 1;
	s->top = p->next;
	free(p);
	p = NULL;
	return SUCCESS;
}
