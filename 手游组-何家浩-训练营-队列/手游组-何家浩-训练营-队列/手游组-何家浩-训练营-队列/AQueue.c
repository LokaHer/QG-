#include"AQueue.h"


void InitAQueue(AQueue *Q)//1
{
	Q->front = 0;
	Q->rear = 0;
	Q->length = 0;
	printf("初始化成功！！！");
	_getch();
}

void DestoryAQueue(AQueue *Q)//2
{
	Q->front = Q->rear;
	//free(Q->data);
	Q->front = 0;
	Q->rear = 0;
	Q->length = 0;
	printf("已销毁!\n");
	_getch();
}

Status IsFullAQueue(const AQueue *Q)//3
{
	if (Q->length == MAXQUEUE - 1)return TRUE;
	else return FALSE;
}

Status IsEmptyAQueue(const AQueue *Q)//4
{
	if (Q->length==0)return TRUE;
	else return FALSE;
}

Status GetHeadAQueue(AQueue *Q, void *e)//5
{
	if (IsEmptyAQueue(Q)) {
		printf("队列已空");
		_getch();
		return FALSE;
	};
	memcpy(e, Q->data + Q->front, 4);
	return TRUE;
}

int LengthAQueue(AQueue *Q)//6
{
	return Q->length;
}

Status EnAQueue(AQueue *Q, void *data)//7
{
	if (Q->length == 10) { printf("队列已经满了！！！\n"); return FALSE; }
	
	memcpy(Q->data + Q->rear,data, 4);
	Q->rear = (Q->rear + 1) % MAXQUEUE;
	Q->length ++;
	return TRUE;
}

Status DeAQueue(AQueue *Q)//8
{
	if (IsEmptyAQueue(Q)) { printf("队列已空"); _getch(); return FALSE; }
	Q->front = (Q->front + 1) % MAXQUEUE;
	Q->length -= 1;
	printf("已删除队头\n");
	_getch();
	return TRUE;
}


void ClearAQueue(AQueue *Q)//9
{
	Q->front = Q->rear; 
	Q->length = 0;

}

Status TraverseAQueue(const AQueue *Q, void(*foo)(void *q))//0
{
	int num = Q->front;
	while (num != Q->rear)
	{
		foo(Q->data + num);
		num = (num + 1) % MAXQUEUE;
	}
	return TRUE;
}

void APrint(void *q)
{
	printf("队列成员：%d\n", *(int*)q);
}
