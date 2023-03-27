#include "InToSu.h" 
//Á´Õ»

//³õÊ¼»¯Õ»
Status initLStack(LinkStack *s)
{
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
Status isEmptyLStack(LinkStack *s)
{
	if(s->count == 0)
		return SUCCESS;
	return ERROR;
}

//µÃµ½Õ»¶¥ÔªËØ
Status getTopLStack(LinkStack *s,ElemType *e)
{
	if(s->top == NULL)
	{
		return ERROR;
	}
	*e = s->top->data;
	return SUCCESS;
}

//ÈëÕ»
Status pushLStack(LinkStack *s,ElemType data)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->next = s->top;
	p->data = data;
	s->count += 1;
	s->top = p;
	return SUCCESS;
}

//³öÕ»
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
