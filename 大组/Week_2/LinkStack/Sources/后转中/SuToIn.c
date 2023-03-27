#include "SuToIn.h" 
//链栈

//初始化栈
Status initLStack(LinkStack *s)
{
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s)
{
	if(s->count == 0)
		return SUCCESS;
	return ERROR;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));	//申请新节点 
	p->next = s->top;		//连接上原来的栈顶元素 
	p->data = data;			//数据放进去 
	s->count += 1;			//长度+1 
	s->top = p;				//栈顶置为新节点 
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data)
{
	if(s->top == NULL)
	{
		return ERROR;
	}
	LinkStackPtr p = s->top;
	*data = p->data;
	s->count -= 1;
	s->top = p->next;		//让栈顶元素变动 
	free(p);				//free原来的栈顶元素 
	p = NULL;
	return SUCCESS;
}

//判断是否为运算符，以及运算符的优先级 
int priority(char c)
{
	if(c == '+' || c == '-')return 1;
	else if(c == '*' || c == '/')return 2;
	else return 0;
}

//将输入的多位数字符数字转换为整型 
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
			break;//0与#表示结束 
		}
		else if(c >= '0' && c <= '9')
		{
			i += 1;
			a[i] = c;	//将数字放入数组中 
			if(i > 5)
			
				return -1; 
		}
		else return -1; //如果是其他字符则直接退出 
	}
	for(i;i >=0;i--)	//把字符数组转换成整数 
	{
		nums += (a[i] - '0')*n;
		n *= 10;
	}
	return nums;
}
