#include"LQueue.h"


void InitLQueue(LQueue *Q)
{
	Q->front = NULL;
	Q->rear = Q->front;
	Q->length = 0;
}
void DestoryLQueue(LQueue *Q)
{
	
	free(Q->front);
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
	Q = NULL;
	//LQueue *p;
}
int IsEmptyLQueue(const LQueue *Q)
{
	if (Q->length == 0)
	{
		printf("空队列！！！");
			return 1;
	}
	return 0;
}
int GetHeadLQueue(LQueue *Q, void *e)
{
	if (Q->length==0)
	{
		printf("空的哦\n");
		_getch();
		return 0;
	}
	e = Q->front->data;
	return *(int*)e;
}
int LengthLQueue(LQueue *Q)
{
	return Q->length;
}
int EnLQueue(LQueue *Q, void *data)
{
	if (Q->length == 0)
	{
		Node *p = (Node*)malloc(sizeof(Node));

		p->data = data;
		p->next = NULL;

		Q->front = p;
		Q->rear = p;
		Q->length++;
		p = NULL;
	}
	else
	{
		Node *pp = (Node*)malloc(sizeof(Node));
		
		Q->rear->next = pp;

		pp->data = data;
		pp->next = NULL;

		Q->rear = pp;
		Q->length++;
		pp = NULL;
	}
	return 1;
}
int DeLQueue(LQueue *Q)
{
	if (Q->length == 0) { printf("空队列！！！"); return 0; }

	if (Q->front == Q->rear)Q->front = Q->rear = NULL;
	else Q->front = Q->front->next;

	Q->length--;
	printf("已出队\n");
	return 1;
}
void ClearLQueue(LQueue *Q)
{
	while (Q->front == Q->rear)
	{
		Node*p = Q->front;
		Q->front = Q->front->next;
		free(p);
	}
	Q->length = 0;
}
int TraverseLQueue(const LQueue *Q, void(*foo)(void *q))
{
	Node *p=Q->front;
	while (p != NULL)
	{
		foo(p->data);
		p = p->next;
	}
	return 0;
}
void LPrint(void *q)
{
	printf("队列成员：%d\n", *(int*)q);
}