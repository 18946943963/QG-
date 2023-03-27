#include "LinkStack.h" 
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

//���ջ
Status clearLStack(LinkStack *s)
{
	StackNode *p = s->top;	//p����free 
	while (p)				//��p��Ϊ��ʱ��һֱfree 
	{
		s->top = p->next;
		free(p);
		p = s->top;
	}
	s->count = 0;			//��󳤶���Ϊ0 
	printf("�ɹ������ջ\n");
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s)
{
	StackNode *p = s->top;	//p����free 
	while (p)				//��p��Ϊ��ʱ��һֱfree  
	{
		s->top = p->next;
		free(p);
		p = s->top;
	}
	s->count = 0;			//��󳤶���Ϊ0  
	printf("�ɹ�������ջ\n");
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int *length)
{
	*length = s->count;
	printf("��ջ�ĳ���Ϊ%d\n",*length);
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));	//�����½ڵ� 
	p->next = s->top;		//������ԭ����ջ��Ԫ�� 
	p->data = data;			//���ݷŽ�ȥ 
	s->count += 1;			//����+1 
	s->top = p;				//ջ����Ϊ�½ڵ� 
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
	s->top = p->next;		//��ջ��Ԫ�ر䶯 
	free(p);				//freeԭ����ջ��Ԫ�� 
	p = NULL;
	return SUCCESS;
}

//�����ջ 
void printLStack(LinkStack *s)
{
	LinkStackPtr p = s->top;
	if(p == NULL)
	{
		printf("����ջ��������\n");
		return;
	}
	while(p)			//��p��Ϊ��ʱ����� 
	{ 
		printf("%c ",p->data);
		p = p->next;
	}
}

//����һ����ջ 
void CreateLStack(LinkStack *s)
{
	if(s->top != NULL)
	{
		printf("ʧ�ܣ��������Ѿ�������\n");
		return;
	}
	LinkStackPtr p;					//���ڴ����½ڵ� 
	ElemType a; 					//a���ڴ洢��������� 
	printf("���������Ա���Ҫ�洢�����ݣ�����#Ϊֹͣ���룩\n");
	do
	{
		scanf("%c",&a);
		if(a == '\n') continue;	//���з����� 
		if(a == '#') break;		//�ж�������Ƿ�Ϊ#�������#���˳�ѭ�� 
		p = (LinkStackPtr)malloc(sizeof(StackNode));	//�����½ڵ� 
		p->data = a;		//����������ݴ����½�� 
		p->next = s->top;	// �½ڵ�������ԭ������ջ 
		s->top = p;			//��ջ�� 
		s->count++;
	}while(1);
}
