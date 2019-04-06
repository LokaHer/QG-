#include"main.h"

int isCSH = 0;


void AQUEUE()
{
	int switcher = 0;
	AQueue q;
	AQueue* Q = &q;

	while (1) {
		system("cls");
		printf("NICEDAY!!!\n输入1初始化，2销毁，3查满，4查空，5查头，6查长度，7入队，8出队，9清空，0遍历\n");
		while (1 != scanf_s("%d", &switcher) || switcher < 0 || switcher > 11) { printf("错误！重新输入!\n"); while (getchar() != '\n'); }
		switch (switcher)
		{
		case 1:
			InitAQueue(Q);
			break;

		case 2:
			DestoryAQueue(Q);
			 break;

		case 3:
			if (IsFullAQueue(Q))printf("满了！！！");
			else printf("没满！！！");
			_getch();
			break;

		case 4:
			if (IsEmptyAQueue(Q))printf("队列为空\n");
			else printf("队列不为空\n");
			_getch();
			break;

		case 5:
			void *e;
			if (GetHeadAQueue(Q, &e))APrint(&e);
			else printf("栈为空\n");
			break;

		case 6:
			printf("长度为 %d\n", LengthAQueue(Q));
			_getch();
			break;

		case 7:
			printf("输入int数据\n");
			int en;
			scanf_s("%d", &en);
			EnAQueue(Q, &en);
			break;

		case 8:
			DeAQueue(Q);
		
			 break;

		case 9:
			if (Q->length==0)printf("空队列！！！\n");
			else printf("成功");
			break;

		case 0:
			TraverseAQueue(Q, APrint);
			_getch();
			break;
		}
		
	}
}


void LQUEUE()
{
	int switcher = 0;
	LQueue q;
	LQueue* Q = &q;

	while (1) {
		system("cls");
		printf("NICEDAY!!!\n输入1初始化，2销毁，3查空，4查头，5查长度，6入队，7出队，8清空，9遍历\n");
		while (1 != scanf_s("%d", &switcher) || switcher < 1 || switcher > 9) { printf("错误！重新输入!\n"); while (getchar() != '\n'); }
		switch (switcher)
		{
		case 1:
			InitLQueue(Q);
			printf("初始化成功！！！");
			isCSH = 1;
			_getch();
			break;
		case 2:
			if (isCSH) 
			{
				DestoryLQueue(Q);
				isCSH = 0;
				printf("已销毁！！！");
					_getch();
			}else printf("请初始化！！！");
			break;
		case 3:
			IsEmptyLQueue(Q);
			_getch();
			break;
		case 4:
			void *e = NULL;
			printf("队头元素为：%d", GetHeadLQueue(Q, e));
			_getch();
			break;
		case 5:
			printf("长度为:%d", LengthLQueue(Q));
			_getch();
			break;
		case 6:if (isCSH) 
		{
			int *data=(int*)malloc(sizeof(int));
			printf("请输入。。。。\n");
			scanf_s("%d", data);
			EnLQueue(Q, data);
			
		}
			   else printf("请初始化！！！");
			break;
		case 7:if (isCSH) 
		{
			DeLQueue(Q);
			_getch();
		}
			   else printf("请初始化！！！");
			break;
		case 8:if (isCSH)
		{
			ClearLQueue(Q);
			printf("已清空\n");
			_getch();
		}
			   else printf("请初始化！！！");
		case 9:
			TraverseLQueue(Q, LPrint);
			_getch();
			break;
		}
	}
}

int main()
{
	system("color F0");
	int switcher = 0;
	printf("NICEDAY!!!\n输入1转到循环队列，输入2转到链式队列");
	while (1 != scanf_s("%d", &switcher) || switcher < 1 || switcher > 2) { printf("错误！重新输入!\n"); while (getchar() != '\n'); }
	switch (switcher)
	{
	case 1:
		AQUEUE(); break;
	case 2:
		LQUEUE(); break;
	};
	system("pause");

	return 0;
}