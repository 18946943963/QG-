#include "LinkStack.h" 
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

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e)
{
	if(s->top == NULL)
	{
		return ERROR;
	}
	*e = s->top->data;
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack *s)
{
	StackNode *p = s->top;	//p用来free 
	while (p)				//当p不为空时，一直free 
	{
		s->top = p->next;
		free(p);
		p = s->top;
	}
	s->count = 0;			//最后长度置为0 
	printf("成功清空链栈\n");
	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack *s)
{
	StackNode *p = s->top;	//p用来free 
	while (p)				//当p不为空时，一直free  
	{
		s->top = p->next;
		free(p);
		p = s->top;
	}
	s->count = 0;			//最后长度置为0  
	printf("成功销毁链栈\n");
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length)
{
	*length = s->count;
	printf("链栈的长度为%d\n",*length);
	return SUCCESS;
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

//输出链栈 
void printLStack(LinkStack *s)
{
	LinkStackPtr p = s->top;
	if(p == NULL)
	{
		printf("该链栈暂无数据\n");
		return;
	}
	while(p)			//当p不为空时，输出 
	{ 
		printf("%c ",p->data);
		p = p->next;
	}
}

//创建一个链栈 
void CreateLStack(LinkStack *s)
{
	if(s->top != NULL)
	{
		printf("失败，该链表已经被创建\n");
		return;
	}
	LinkStackPtr p;					//用于创建新节点 
	ElemType a; 					//a用于存储输入的数据 
	printf("请输入线性表所要存储的数据（输入#为停止输入）\n");
	do
	{
		scanf("%c",&a);
		if(a == '\n') continue;	//换行符跳过 
		if(a == '#') break;		//判断输入的是否为#，如果是#则退出循环 
		p = (LinkStackPtr)malloc(sizeof(StackNode));	//创建新节点 
		p->data = a;		//将输入的数据存入新结点 
		p->next = s->top;	// 新节点连接上原来的链栈 
		s->top = p;			//换栈顶 
		s->count++;
	}while(1);
}
