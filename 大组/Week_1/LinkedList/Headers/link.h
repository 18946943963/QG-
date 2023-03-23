#ifndef LINK_H
#define LINK_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;		//����洢�����ݵ����� 

typedef struct Node				//��������Ľṹ 
{
	ElemType data;
	struct Node *next;
}Node, *LinkList;

void ParitySwap(LinkList L);
int parity(ElemType e);
ElemType FindMid(LinkList L);
int IfCycle(LinkList L);
void RevertList_2(LinkList head); 

#endif 
