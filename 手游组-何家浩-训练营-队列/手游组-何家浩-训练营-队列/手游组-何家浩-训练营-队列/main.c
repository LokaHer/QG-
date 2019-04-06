#include"main.h"

int isCSH = 0;


void AQUEUE()
{
	int switcher = 0;
	AQueue q;
	AQueue* Q = &q;

	while (1) {
		system("cls");
		printf("NICEDAY!!!\n����1��ʼ����2���٣�3������4��գ�5��ͷ��6�鳤�ȣ�7��ӣ�8���ӣ�9��գ�0����\n");
		while (1 != scanf_s("%d", &switcher) || switcher < 0 || switcher > 11) { printf("������������!\n"); while (getchar() != '\n'); }
		switch (switcher)
		{
		case 1:
			InitAQueue(Q);
			break;

		case 2:
			DestoryAQueue(Q);
			 break;

		case 3:
			if (IsFullAQueue(Q))printf("���ˣ�����");
			else printf("û��������");
			_getch();
			break;

		case 4:
			if (IsEmptyAQueue(Q))printf("����Ϊ��\n");
			else printf("���в�Ϊ��\n");
			_getch();
			break;

		case 5:
			void *e;
			if (GetHeadAQueue(Q, &e))APrint(&e);
			else printf("ջΪ��\n");
			break;

		case 6:
			printf("����Ϊ %d\n", LengthAQueue(Q));
			_getch();
			break;

		case 7:
			printf("����int����\n");
			int en;
			scanf_s("%d", &en);
			EnAQueue(Q, &en);
			break;

		case 8:
			DeAQueue(Q);
		
			 break;

		case 9:
			if (Q->length==0)printf("�ն��У�����\n");
			else printf("�ɹ�");
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
		printf("NICEDAY!!!\n����1��ʼ����2���٣�3��գ�4��ͷ��5�鳤�ȣ�6��ӣ�7���ӣ�8��գ�9����\n");
		while (1 != scanf_s("%d", &switcher) || switcher < 1 || switcher > 9) { printf("������������!\n"); while (getchar() != '\n'); }
		switch (switcher)
		{
		case 1:
			InitLQueue(Q);
			printf("��ʼ���ɹ�������");
			isCSH = 1;
			_getch();
			break;
		case 2:
			if (isCSH) 
			{
				DestoryLQueue(Q);
				isCSH = 0;
				printf("�����٣�����");
					_getch();
			}else printf("���ʼ��������");
			break;
		case 3:
			IsEmptyLQueue(Q);
			_getch();
			break;
		case 4:
			void *e = NULL;
			printf("��ͷԪ��Ϊ��%d", GetHeadLQueue(Q, e));
			_getch();
			break;
		case 5:
			printf("����Ϊ:%d", LengthLQueue(Q));
			_getch();
			break;
		case 6:if (isCSH) 
		{
			int *data=(int*)malloc(sizeof(int));
			printf("�����롣������\n");
			scanf_s("%d", data);
			EnLQueue(Q, data);
			
		}
			   else printf("���ʼ��������");
			break;
		case 7:if (isCSH) 
		{
			DeLQueue(Q);
			_getch();
		}
			   else printf("���ʼ��������");
			break;
		case 8:if (isCSH)
		{
			ClearLQueue(Q);
			printf("�����\n");
			_getch();
		}
			   else printf("���ʼ��������");
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
	printf("NICEDAY!!!\n����1ת��ѭ�����У�����2ת����ʽ����");
	while (1 != scanf_s("%d", &switcher) || switcher < 1 || switcher > 2) { printf("������������!\n"); while (getchar() != '\n'); }
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