#include"main.h"


int a[200000] = {0}; 


int main(void)
{
	system("color F0");

	int num10000 = 10000, num50000 = 50000, num200000 = 200000;
	int i, ii, iii, number;

	int switcher1 = -1, switcher2 = -1;

	clock_t begintime, alltime;

	while (switcher1)
	{
		cout << "NICEDAY������" << endl;
		cout << "����1��������   2�鲢����       3�������򣨵ݹ飩   4�������򣨷ǵݹ飩\n";
		cout << "    5��������   6������������   7��ɫ����           8����            0�˳���ǰ\n";


		while (1 != scanf_s("%d", &switcher1) || switcher1 < 0 || switcher1 > 9) { cout << "������������!"; while (getchar() != '\n'); }
		switch (switcher1)
		{

		case 1:/**
*  @name        : void insertSort(int *a,int n);
*  @description : ��������
*  @param       : ����ָ�� a, ���鳤�� n
*/
			switcher2 = -1;
			cout << "1�Զ�����  2����\n";

			while (1 != scanf_s("%d", &switcher2) || switcher2 < 1 || switcher2 > 2) { cout << "������������!"; while (getchar() != '\n'); }
			if (switcher2 == 1)
			{

				for (i = 0; i < num10000; i++)a[i] = rand();
				begintime = clock();
				insertSort(a, num10000);
				alltime = clock() - begintime;
				cout << "��������1w������ʱ:" << alltime << "ms\n";

				for (i = 0; i < num50000; i++) { a[i] = rand(); }
				begintime = clock();
				insertSort(a, num50000);
				alltime = clock() - begintime;
				cout << "��������5w������ʱ:" << alltime << "ms\n";

				for (i = 0; i < num200000; i++) { a[i] = rand(); }
				begintime = clock();
				insertSort(a, num200000);
				alltime = clock() - begintime;
				cout << "��������20w������ʱ:" << alltime << "ms\n";

				alltime = 0;
				for (ii = 0; ii < 100000; ii++)
				{
					for (i = 0; i < 100; i++)a[i] = rand();
					begintime = clock();
					insertSort(a, 100);
					alltime += clock() - begintime;
				}
				cout << "��������100����*100k��������ʱ:" << alltime << "ms\n";

			}
			else if (switcher2 == 2)
			{
				iii = 0;
				cout << "����ʮ������(�ո����)��";
				for (num200000 = 0; num200000 < 10; num200000++)
				{
					std::cin >> number;
					a[iii] = number;
					++iii;
				}
				while (getchar() != '\n');
				for (i = 0; i < iii; i++)cout << a[i] << " ";
				begintime = clock();
				insertSort(a, iii);
				alltime = clock() - begintime;
				cout << "�����:";
				for (i = 0; i < iii; i++)cout << a[i] << " ";
				cout << "\n��������������ʱ:" << alltime << "ms\n";
				break;
			}
			break;

		case 2:/**
*  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
*  @description : �鲢���򣨺ϲ����飩
*  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
*/
			switcher2 = -1;
			cout << "1�Զ�����  2����\n";
			std::cin >> switcher2;
			if (switcher2 == 1)
			{

				for (i = 0; i < num10000; i++)a[i] = rand();

				begintime = clock();
				MergeSort(a, 0, num10000 - 1, a);
				alltime = clock() - begintime;
				cout << "�鲢����1w������ʱ:" << alltime << "ms\n";

				for (i = 0; i < num50000; i++)a[i] = rand();

				begintime = clock();
				MergeSort(a, 0, num50000 - 1, a);
				alltime = clock() - begintime;
				cout << "�鲢����5w������ʱ:" << alltime << "ms\n";

				for (i = 0; i < num200000; i++)a[i] = rand();

				begintime = clock();
				MergeSort(a, 0, num200000 - 1, a);
				alltime = clock() - begintime;
				cout << "�鲢����20w������ʱ:" << alltime << "ms\n";

				alltime = 0;
				for (ii = 0; ii < 100000; ii++)
				{
					for (i = 0; i < 100; i++)a[i] = rand();

					begintime = clock();
					MergeSort(a, 0, 99, a);
					alltime += clock() - begintime;
				}
				cout << "�鲢����100����*100k��������ʱ:" << alltime << "ms\n";



			}
			else if (switcher2 == 2)
			{
				iii = 0;
				cout << "����ʮ������(�ո����)��";
				for (num200000 = 0; num200000 < 10; num200000++)
				{
					std::cin >> number;
					a[iii] = number;
					++iii;
				}
				while (getchar() != '\n');
				for (i = 0; i < iii; i++)cout << a[i] << " ";
				begintime = clock();
				MergeSort(a, 0, iii - 1, a);
				alltime = clock() - begintime;
				cout << "�����:";
				for (i = 0; i < iii; i++)cout << a[i] << " ";
				cout << "\n�鲢����������ʱ:" << alltime << "ms\n";
				break;
			}
			break;
		case 3:/**
*  @name        : void QuickSort(int *a, int begin, int end);
*  @description : �������򣨵ݹ�棩
*  @param       : ����ָ��a���������begin�������յ�end
*/
			switcher2 = -1;
			cout << "1�Զ�����  2����\n";
			std::cin >> switcher2;
			if (switcher2 == 1)
			{

				for (i = 0; i < num10000; i++)a[i] = rand();

				begintime = clock();
				QuickSort_Recursion(a, 0, num10000 - 1);
				alltime = clock() - begintime;
				cout << "�ݹ����1w������ʱ:" << alltime << "ms\n";

				for (i = 0; i < num50000; i++)
				{
					a[i] = rand();
				}
				begintime = clock();
				QuickSort_Recursion(a, 0, num50000 - 1);
				alltime = clock() - begintime;
				cout << "�ݹ����5w������ʱ:" << alltime << "ms\n";

				for (i = 0; i < num200000; i++)a[i] = rand();

				begintime = clock();
				QuickSort_Recursion(a, 0, num200000 - 1);

				alltime = clock() - begintime;
				cout << "�ݹ����20w������ʱ:" << alltime << "ms\n";

				alltime = 0;
				for (ii = 0; ii < 100000; ii++)
				{
					for (i = 0; i < 100; i++)a[i] = rand();

					begintime = clock();
					QuickSort_Recursion(a, 0, 99);
					alltime += clock() - begintime;
				}
				cout << "�ݹ����100����*100k��������ʱ:" << alltime << "ms\n";


			}
			else if (switcher2 == 2)
			{
				iii = 0;
				cout << "����ʮ������(�ո����)��";
				for (num200000 = 0; num200000 < 10; num200000++)
				{
					std::cin >> number;
					a[iii] = number;
					++iii;
				}
				while (getchar() != '\n');
				for (i = 0; i < iii; i++)cout << a[i] << " ";
				begintime = clock();
				QuickSort_Recursion(a, 0, iii - 1);
				alltime = clock() - begintime;
				cout << "�����:";
				for (i = 0; i < iii; i++)cout << a[i] << " ";
				cout << "\n�ݹ����������ʱ:" << alltime << "ms\n";
				break;
			}
			break;
		case 4:/**
*  @name        : void QuickSort(int *a,int size)
*  @description : �������򣨷ǵݹ�棩
*  @param       : ����ָ��a�����鳤��size
*/
			switcher2 = -1;
			cout << "1�Զ�����  2����\n";
			std::cin >> switcher2;
			if (switcher2 == 1)
			{

				for (i = 0; i < num10000; i++)a[i] = rand();

				begintime = clock();
				QuickSort(a, num10000);
				alltime = clock() - begintime;
				cout << "�ǵݹ����1w������ʱ" << alltime << "ms\n";

				for (i = 0; i < num50000; i++)
				{
					a[i] = rand();
				}
				begintime = clock();
				QuickSort(a, num50000);
				alltime = clock() - begintime;
				cout << "�ǵݹ����5w������ʱ:" << alltime << "ms\n";

				for (i = 0; i < num200000; i++)
				{
					a[i] = rand();
				}
				begintime = clock();
				QuickSort(a, num200000);
				alltime = clock() - begintime;
				cout << "�ǵݹ����20w������ʱ:" << alltime << "ms\n";

				alltime = 0;
				for (ii = 0; ii < 100000; ii++)
				{
					for (i = 0; i < 100; i++)
					{
						a[i] = rand();
					}
					begintime = clock();
					QuickSort(a, 100);
					alltime += clock() - begintime;
				}
				cout << "�ǵݹ����100����*100k��������ʱ:" << alltime << "ms\n";

			}
			else if (switcher2 == 2)
			{
				iii = 0;
				cout << "����ʮ������(�ո����)��";
				for (num200000 = 0; num200000 < 10; num200000++)
				{
					std::cin >> number;
					a[iii] = number;
					++iii;
				}
				while (getchar() != '\n');
				for (i = 0; i < iii; i++)cout << a[i] << " ";
				begintime = clock();
				QuickSort(a, iii);
				alltime = clock() - begintime;
				cout << "�����:";
				for (i = 0; i < iii; i++)cout << a[i] << " ";
				cout << "\n�ǵݹ����������ʱ:" << alltime << "ms\n";
				break;
			}
			break;
		case 5:/**
*  @name        : void CountSort(int *a, int size , int max)
*  @description : ��������
*  @param       : ����ָ��a�����鳤��size���������ֵmax
*/
			switcher2 = -1;
			cout << "1�Զ�����  2����\n";
			std::cin >> switcher2;
			if (switcher2 == 1)
			{

				for (i = 0; i < num10000; i++)a[i] = rand();

				number = a[i - 1];
				for (i = 0; i < num10000; i++)if (a[i] > number)number = a[i];

				begintime = clock();
				CountSort(a, num10000, number);
				alltime = clock() - begintime;
				cout << "��������1w������ʱ:" << alltime << "ms\n";

				for (i = 0; i < num50000; i++)
				{
					a[i] = rand();
				}
				number = a[i - 1];
				for (i = 0; i < num50000; i++)
				{
					if (a[i] > number)number = a[i];
				}
				begintime = clock();
				CountSort(a, num50000, number);
				alltime = clock() - begintime;
				cout << "��������5w������ʱ:" << alltime << "ms\n";

				for (i = 0; i < num200000; i++)
				{
					a[i] = rand();
				}
				number = a[i - 1];
				for (i = 0; i < num200000; i++)
				{
					if (a[i] > number)number = a[i];
				}
				begintime = clock();

				CountSort(a, num200000, number);
				alltime = clock() - begintime;
				cout << "��������20w������ʱ:" << alltime << "ms\n";

				alltime = 0;
				for (ii = 0; ii < 100000; ii++)
				{
					for (i = 0; i < 100; i++)
					{
						a[i] = rand();
					}
					number = a[i - 1];
					for (i = 0; i < 100; i++)
					{
						if (a[i] > number)number = a[i];

					}
					begintime = clock();
					CountSort(a, 100, number);

					alltime += clock() - begintime;
				}
				cout << "��������100����*100k��������ʱ:" << alltime << "ms\n";

			}
			else if (switcher2 == 2)
			{
				iii = 0;
				cout << "����ʮ������(�ո����)��";
				for (num200000 = 0; num200000 < 10; num200000++)
				{
					std::cin >> number;
					a[iii] = number;

					++iii;
				}
				number = a[iii - 1];
				for (i = 0; i < iii; i++)

				{
					if (a[i] > number)number = a[i];
				}
				while (getchar() != '\n');
				for (i = 0; i < iii; i++)cout << a[i] << " ";

				begintime = clock();
				CountSort(a, iii, number);

				alltime = clock() - begintime;

				cout << "�����:";
				for (i = 0; i < iii; i++)cout << a[i] << " ";
				cout << "\n��������������ʱ:" << alltime << "ms\n";
				break;
			}
			break;
		case 6:/**
*  @name        : void RadixCountSort(int *a,int size)
*  @description : ������������
*  @param       : ����ָ��a�����鳤��size
*/
			switcher2 = -1;
			cout << "1�Զ�����  2����\n";
			std::cin >> switcher2;

			if (switcher2 == 1)
			{

				for (i = 0; i < num10000; i++)a[i] = rand();

				begintime = clock();
				RadixCountSort(a, num10000);
				alltime = clock() - begintime;

				cout << "��������1w������ʱ:" << alltime << "ms\n";

				for (i = 0; i < num50000; i++)
				{

					a[i] = rand();
				}
				begintime = clock();
				RadixCountSort(a, num50000);
				alltime = clock() - begintime;

				cout << "��������5w������ʱ:" << alltime << "ms\n";

				for (i = 0; i < num200000; i++)a[i] = rand();

				begintime = clock();
				RadixCountSort(a, num200000);

				alltime = clock() - begintime;
				cout << "��������20w������ʱ:" << alltime << "ms\n";

				alltime = 0;
				for (ii = 0; ii < 100000; ii++)
				{
					for (i = 0; i < 100; i++)

						a[i] = rand();

					begintime = clock();
					RadixCountSort(a, 100);
					alltime += clock() - begintime;
				}
				cout << "��������100����*100k��������ʱ:" << alltime << "ms\n";

			}
			else if (switcher2 == 2)
			{
				iii = 0;
				cout << "����ʮ������(�ո����)��";
				for (num200000 = 0; num200000 < 10; num200000++)
				{
					std::cin >> number;
					a[iii] = number;
					++iii;
				}
				while (getchar() != '\n');
				for (i = 0; i < iii; i++)cout << a[i] << " ";

				begintime = clock();
				RadixCountSort(a, iii);
				alltime = clock() - begintime;

				cout << "�����:";
				for (i = 0; i < iii; i++)cout << a[i] << " ";
				cout << "\n������������������ʱ:" << alltime << "ms\n";
				break;
			}
			break;
		case 7:/**
*  @name        : void ColorSort(int *a,int size)
*  @description : ��ɫ����
*  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
*/
			switcher2 = -1;
			cout << "1�Զ�����  2����\n";
			std::cin >> switcher2;
			if (switcher2 == 1)
			{

				for (i = 0; i < num10000; i++)

					a[i] = rand() % 3;

				begintime = clock();
				ColorSort(a, num10000);

				alltime = clock() - begintime;
				cout << "��ɫ����1w������ʱ:" << alltime << "ms\n";

				for (i = 0; i < num50000; i++)
				{
					a[i] = rand() % 3;
				}
				begintime = clock();
				ColorSort(a, num50000);

				alltime = clock() - begintime;
				cout << "��ɫ����5w������ʱ:" << alltime << "ms\n";

				for (i = 0; i < num200000; i++)

					a[i] = rand() % 3;

				begintime = clock();
				ColorSort(a, num200000);
				alltime = clock() - begintime;
				cout << "��ɫ����20w������ʱ:" << alltime << "ms\n";

				alltime = 0;
				for (ii = 0; ii < 100000; ii++)
				{
					for (i = 0; i < 100; i++)

						a[i] = rand() % 3;

					begintime = clock();

					ColorSort(a, 100);
					alltime += clock() - begintime;
				}
				cout << "��ɫ����100����*100k��������ʱ:" << alltime << "ms\n";

			}
			else if (switcher2 == 2)
			{
				cout << "����ʮ������(�ո����) :";
				for (iii = 0; iii < 10; )
				{
					std::cin >> number;

					if (number != 1 && number != 0 && number != 2)
					{
						continue;
					}
					a[iii] = number;
					iii++;
				}
				while (getchar() != '\n');
				for (i = 0; i < iii; i++)cout << a[i] << " ";
				begintime = clock();

				ColorSort(a, iii);
				alltime = clock() - begintime;
				cout << "�����:";

				for (i = 0; i < iii; i++)cout << a[i] << " ";
				cout << "\n��ɫ�������������ʱ:" << alltime << "ms\n";
				break;
			}
			break;
		case 8:/**
*  @name        : ����
*  @description : ��һ�������������ҵ���K��/С����
*  @param       : ����ָ��a�����鳤��size
*/
			switcher2 = -1;
			cout << "2����\n";

			std::cin >> switcher2;
			if (switcher2 == 1)
			{

				for (i = 0; i < num10000; i++)

					a[i] = rand();

				begintime = clock();
				number = Find(a, num10000, 5000);

				alltime = clock() - begintime;
				cout << "number:" << number;

				cout << "\t����1w������ʱ:" << alltime << "ms\n";

				for (i = 0; i < num50000; i++)
				{
					a[i] = rand();
				}
				begintime = clock();

				number = Find(a, num50000, 5000);
				alltime = clock() - begintime;

				cout << "number:" << number;
				cout << "\t����5w������ʱ:" << alltime << "ms\n";

				for (i = 0; i < num200000; i++)

					a[i] = rand();

				begintime = clock();
				number = Find(a, num200000, 5000);

				alltime = clock() - begintime;
				cout << "number:" << number;

				cout << "\t����20w������ʱ:" << alltime << "ms\n";

				for (ii = 0; ii < 100000; ii++)
				{
					for (i = 0; i < 100; i++)

						a[i] = rand();

					begintime = clock();

					number = Find(a, 100, 50);
					alltime = clock() - begintime;

					cout << "\t����100����*100k��������ʱ:" << alltime << "ms\n";


				}
			}
			else if (switcher2 == 2)
			{
				iii = 0;
				cout << "����ʮ������(�ո����)��";
				for (num200000 = 0; num200000 < 10; num200000++)
				{
					std::cin >> number;
					a[iii] = number;
					iii++;
				}
				while (getchar() != '\n');
				cout << "���ҵڼ���Ԫ�أ�";
				std::cin >> number;

				if (number < 1 || number>10) { cout << "����!!!" << endl; break; }
				begintime = clock();
				number = Find(a, iii, number);

				alltime = clock() - begintime;

				cout << "number:" << number;
				cout << "\n���Ҳ���������ʱ:" << alltime << "ms\n";
				break;
			}
			break;
		}
		_getch();
		system("cls");
	}

	return 0;
}