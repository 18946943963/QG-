#include "SuToIn.h" 
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

//�ж��Ƿ�Ϊ��������Լ�����������ȼ� 
int priority(char c)
{
	if(c == '+' || c == '-')return 1;
	else if(c == '*' || c == '/')return 2;
	else return 0;
}

//������Ķ�λ���ַ�����ת��Ϊ���� 
int number(LinkStack *s, char c)
{
	int i = 0,n = 1,nums = 0;
	char a[10];
	a[0] = c;
	while(1)
	{
		scanf("%c",&c);
		if(c == ' ')
		{
			break;//0��#��ʾ���� 
		}
		else if(c >= '0' && c <= '9')
		{
			i += 1;
			a[i] = c;	//�����ַ��������� 
			if(i > 5)
			
				return -1; 
		}
		else return -1; //����������ַ���ֱ���˳� 
	}
	for(i;i >=0;i--)	//���ַ�����ת�������� 
	{
		nums += (a[i] - '0')*n;
		n *= 10;
	}
	return nums;
}
