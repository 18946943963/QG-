#include"LQueue.h" 

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	Node *p = (Node*)malloc(sizeof(Node));	//申请头节点 
	p->next = NULL;
	Q->rear = p;							//头尾都指向头结点 
	Q->front = p;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	while(Q->front != Q->rear)	//当头不等于尾时，出列 
		DeLQueue(Q);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->front == Q->rear)	//头等于尾为空 
		return TRUE;
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(IsEmptyLQueue(Q) == TRUE)	//判断是否为空 
		return FALSE;
	e = Q->front->next->data;				//获取顶元素 
	LPrint(e);
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	if(IsEmptyLQueue(Q) == TRUE)	//判断是否为空 
		return 0;
	Node *p = Q->front;
	int i = 0;
	while(p != Q->rear)			//当p没有直到尾巴时，一直遍历 
	{
		p = p->next;
		i++;
	}
	return i;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data)
{
	Node *p = (Node*)malloc(sizeof(Node));	//申请空间 
	if(p == NULL) return FALSE;
	p->data = data;
	p->next = Q->rear->next;				//p的next置为NULL 
	Q->rear->next = p;						//接上尾节点 
	Q->rear = p;							// 尾节点置为p 
	Q->length +=1;							//长度加一 
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)\
{
	if(IsEmptyLQueue(Q) == TRUE)
		return FALSE;
	Node *p = Q->front->next;	//p指向队列头部 
	Q->front->next = p->next;	//头指针指向原头部的下一个节点 
	Q->length -= 1;				//长度减一 
	free(p);
	p = NULL;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	while(Q->front != Q->rear)	//当头尾指针不重合时，就调用出栈函数 
		DeLQueue(Q);
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	if(IsEmptyLQueue(Q) == TRUE)
		return FALSE;
	Node *p = Q->front;		//p指向头节点 
	p = p->next;			//p指向第一个节点 
	while(p != NULL)		//当p不为空时 
		{
			(*foo)(p->data);//传入打印函数 
			p = p->next;
		}
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q)
{
	if(type == 'i')				//根据type的类型将无类型指针转为对应类型的数据类型再输出 
	{
		int *a = (int*)q;
		printf("%d ",*a);
	}
	else if(type == 'f')
	{
		float *a = (float*)q;
		printf("%f ",*a);
	}
	else if(type == 'c')
	{
		char *a = (char*)q;
		printf("%c ",*a);
	}
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
