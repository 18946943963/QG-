#include"LQueue.h" 

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	Node *p = (Node*)malloc(sizeof(Node));	//����ͷ�ڵ� 
	p->next = NULL;
	Q->rear = p;							//ͷβ��ָ��ͷ��� 
	Q->front = p;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	while(Q->front != Q->rear)	//��ͷ������βʱ������ 
		DeLQueue(Q);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->front == Q->rear)	//ͷ����βΪ�� 
		return TRUE;
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(IsEmptyLQueue(Q) == TRUE)	//�ж��Ƿ�Ϊ�� 
		return FALSE;
	e = Q->front->next->data;				//��ȡ��Ԫ�� 
	LPrint(e);
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	if(IsEmptyLQueue(Q) == TRUE)	//�ж��Ƿ�Ϊ�� 
		return 0;
	Node *p = Q->front;
	int i = 0;
	while(p != Q->rear)			//��pû��ֱ��β��ʱ��һֱ���� 
	{
		p = p->next;
		i++;
	}
	return i;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data)
{
	Node *p = (Node*)malloc(sizeof(Node));	//����ռ� 
	if(p == NULL) return FALSE;
	p->data = data;
	p->next = Q->rear->next;				//p��next��ΪNULL 
	Q->rear->next = p;						//����β�ڵ� 
	Q->rear = p;							// β�ڵ���Ϊp 
	Q->length +=1;							//���ȼ�һ 
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)\
{
	if(IsEmptyLQueue(Q) == TRUE)
		return FALSE;
	Node *p = Q->front->next;	//pָ�����ͷ�� 
	Q->front->next = p->next;	//ͷָ��ָ��ԭͷ������һ���ڵ� 
	Q->length -= 1;				//���ȼ�һ 
	free(p);
	p = NULL;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	while(Q->front != Q->rear)	//��ͷβָ�벻�غ�ʱ���͵��ó�ջ���� 
		DeLQueue(Q);
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	if(IsEmptyLQueue(Q) == TRUE)
		return FALSE;
	Node *p = Q->front;		//pָ��ͷ�ڵ� 
	p = p->next;			//pָ���һ���ڵ� 
	while(p != NULL)		//��p��Ϊ��ʱ 
		{
			(*foo)(p->data);//�����ӡ���� 
			p = p->next;
		}
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q)
{
	if(type == 'i')				//����type�����ͽ�������ָ��תΪ��Ӧ���͵�������������� 
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
