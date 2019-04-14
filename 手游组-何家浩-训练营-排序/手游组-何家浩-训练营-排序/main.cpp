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
		cout << "NICEDAY！！！" << endl;
		cout << "输入1插入排序   2归并排序       3快速排序（递归）   4快速排序（非递归）\n";
		cout << "    5计数排序   6基数计数排序   7颜色排序           8查找            0退出当前\n";


		while (1 != scanf_s("%d", &switcher1) || switcher1 < 0 || switcher1 > 9) { cout << "错误！重新输入!"; while (getchar() != '\n'); }
		switch (switcher1)
		{

		case 1:/**
*  @name        : void insertSort(int *a,int n);
*  @description : 插入排序
*  @param       : 数组指针 a, 数组长度 n
*/
			switcher2 = -1;
			cout << "1自动测试  2输入\n";

			while (1 != scanf_s("%d", &switcher2) || switcher2 < 1 || switcher2 > 2) { cout << "错误！重新输入!"; while (getchar() != '\n'); }
			if (switcher2 == 1)
			{

				for (i = 0; i < num10000; i++)a[i] = rand();
				begintime = clock();
				insertSort(a, num10000);
				alltime = clock() - begintime;
				cout << "插入排序1w数据用时:" << alltime << "ms\n";

				for (i = 0; i < num50000; i++) { a[i] = rand(); }
				begintime = clock();
				insertSort(a, num50000);
				alltime = clock() - begintime;
				cout << "插入排序5w数据用时:" << alltime << "ms\n";

				for (i = 0; i < num200000; i++) { a[i] = rand(); }
				begintime = clock();
				insertSort(a, num200000);
				alltime = clock() - begintime;
				cout << "插入排序20w数据用时:" << alltime << "ms\n";

				alltime = 0;
				for (ii = 0; ii < 100000; ii++)
				{
					for (i = 0; i < 100; i++)a[i] = rand();
					begintime = clock();
					insertSort(a, 100);
					alltime += clock() - begintime;
				}
				cout << "插入排序100数据*100k次排序用时:" << alltime << "ms\n";

			}
			else if (switcher2 == 2)
			{
				iii = 0;
				cout << "输入十个数字(空格隔开)：";
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
				cout << "排序后:";
				for (i = 0; i < iii; i++)cout << a[i] << " ";
				cout << "\n插入排序数据用时:" << alltime << "ms\n";
				break;
			}
			break;

		case 2:/**
*  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
*  @description : 归并排序（合并数组）
*  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
*/
			switcher2 = -1;
			cout << "1自动测试  2输入\n";
			std::cin >> switcher2;
			if (switcher2 == 1)
			{

				for (i = 0; i < num10000; i++)a[i] = rand();

				begintime = clock();
				MergeSort(a, 0, num10000 - 1, a);
				alltime = clock() - begintime;
				cout << "归并排序1w数据用时:" << alltime << "ms\n";

				for (i = 0; i < num50000; i++)a[i] = rand();

				begintime = clock();
				MergeSort(a, 0, num50000 - 1, a);
				alltime = clock() - begintime;
				cout << "归并排序5w数据用时:" << alltime << "ms\n";

				for (i = 0; i < num200000; i++)a[i] = rand();

				begintime = clock();
				MergeSort(a, 0, num200000 - 1, a);
				alltime = clock() - begintime;
				cout << "归并排序20w数据用时:" << alltime << "ms\n";

				alltime = 0;
				for (ii = 0; ii < 100000; ii++)
				{
					for (i = 0; i < 100; i++)a[i] = rand();

					begintime = clock();
					MergeSort(a, 0, 99, a);
					alltime += clock() - begintime;
				}
				cout << "归并快排100数据*100k次排序用时:" << alltime << "ms\n";



			}
			else if (switcher2 == 2)
			{
				iii = 0;
				cout << "输入十个数字(空格隔开)：";
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
				cout << "排序后:";
				for (i = 0; i < iii; i++)cout << a[i] << " ";
				cout << "\n归并排序数据用时:" << alltime << "ms\n";
				break;
			}
			break;
		case 3:/**
*  @name        : void QuickSort(int *a, int begin, int end);
*  @description : 快速排序（递归版）
*  @param       : 数组指针a，数组起点begin，数组终点end
*/
			switcher2 = -1;
			cout << "1自动测试  2输入\n";
			std::cin >> switcher2;
			if (switcher2 == 1)
			{

				for (i = 0; i < num10000; i++)a[i] = rand();

				begintime = clock();
				QuickSort_Recursion(a, 0, num10000 - 1);
				alltime = clock() - begintime;
				cout << "递归快排1w数据用时:" << alltime << "ms\n";

				for (i = 0; i < num50000; i++)
				{
					a[i] = rand();
				}
				begintime = clock();
				QuickSort_Recursion(a, 0, num50000 - 1);
				alltime = clock() - begintime;
				cout << "递归快排5w数据用时:" << alltime << "ms\n";

				for (i = 0; i < num200000; i++)a[i] = rand();

				begintime = clock();
				QuickSort_Recursion(a, 0, num200000 - 1);

				alltime = clock() - begintime;
				cout << "递归快排20w数据用时:" << alltime << "ms\n";

				alltime = 0;
				for (ii = 0; ii < 100000; ii++)
				{
					for (i = 0; i < 100; i++)a[i] = rand();

					begintime = clock();
					QuickSort_Recursion(a, 0, 99);
					alltime += clock() - begintime;
				}
				cout << "递归快排100数据*100k次排序用时:" << alltime << "ms\n";


			}
			else if (switcher2 == 2)
			{
				iii = 0;
				cout << "输入十个数字(空格隔开)：";
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
				cout << "排序后:";
				for (i = 0; i < iii; i++)cout << a[i] << " ";
				cout << "\n递归快排数据用时:" << alltime << "ms\n";
				break;
			}
			break;
		case 4:/**
*  @name        : void QuickSort(int *a,int size)
*  @description : 快速排序（非递归版）
*  @param       : 数组指针a，数组长度size
*/
			switcher2 = -1;
			cout << "1自动测试  2输入\n";
			std::cin >> switcher2;
			if (switcher2 == 1)
			{

				for (i = 0; i < num10000; i++)a[i] = rand();

				begintime = clock();
				QuickSort(a, num10000);
				alltime = clock() - begintime;
				cout << "非递归快排1w数据用时" << alltime << "ms\n";

				for (i = 0; i < num50000; i++)
				{
					a[i] = rand();
				}
				begintime = clock();
				QuickSort(a, num50000);
				alltime = clock() - begintime;
				cout << "非递归快排5w数据用时:" << alltime << "ms\n";

				for (i = 0; i < num200000; i++)
				{
					a[i] = rand();
				}
				begintime = clock();
				QuickSort(a, num200000);
				alltime = clock() - begintime;
				cout << "非递归快排20w数据用时:" << alltime << "ms\n";

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
				cout << "非递归快排100数据*100k次排序用时:" << alltime << "ms\n";

			}
			else if (switcher2 == 2)
			{
				iii = 0;
				cout << "输入十个数字(空格隔开)：";
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
				cout << "排序后:";
				for (i = 0; i < iii; i++)cout << a[i] << " ";
				cout << "\n非递归快排数据用时:" << alltime << "ms\n";
				break;
			}
			break;
		case 5:/**
*  @name        : void CountSort(int *a, int size , int max)
*  @description : 计数排序
*  @param       : 数组指针a，数组长度size，数组最大值max
*/
			switcher2 = -1;
			cout << "1自动测试  2输入\n";
			std::cin >> switcher2;
			if (switcher2 == 1)
			{

				for (i = 0; i < num10000; i++)a[i] = rand();

				number = a[i - 1];
				for (i = 0; i < num10000; i++)if (a[i] > number)number = a[i];

				begintime = clock();
				CountSort(a, num10000, number);
				alltime = clock() - begintime;
				cout << "计数排序1w数据用时:" << alltime << "ms\n";

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
				cout << "计数排序5w数据用时:" << alltime << "ms\n";

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
				cout << "计数排序20w数据用时:" << alltime << "ms\n";

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
				cout << "计数排序100数据*100k次排序用时:" << alltime << "ms\n";

			}
			else if (switcher2 == 2)
			{
				iii = 0;
				cout << "输入十个数字(空格隔开)：";
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

				cout << "排序后:";
				for (i = 0; i < iii; i++)cout << a[i] << " ";
				cout << "\n计数排序数据用时:" << alltime << "ms\n";
				break;
			}
			break;
		case 6:/**
*  @name        : void RadixCountSort(int *a,int size)
*  @description : 基数计数排序
*  @param       : 数组指针a，数组长度size
*/
			switcher2 = -1;
			cout << "1自动测试  2输入\n";
			std::cin >> switcher2;

			if (switcher2 == 1)
			{

				for (i = 0; i < num10000; i++)a[i] = rand();

				begintime = clock();
				RadixCountSort(a, num10000);
				alltime = clock() - begintime;

				cout << "基数计数1w数据用时:" << alltime << "ms\n";

				for (i = 0; i < num50000; i++)
				{

					a[i] = rand();
				}
				begintime = clock();
				RadixCountSort(a, num50000);
				alltime = clock() - begintime;

				cout << "基数计数5w数据用时:" << alltime << "ms\n";

				for (i = 0; i < num200000; i++)a[i] = rand();

				begintime = clock();
				RadixCountSort(a, num200000);

				alltime = clock() - begintime;
				cout << "基数计数20w数据用时:" << alltime << "ms\n";

				alltime = 0;
				for (ii = 0; ii < 100000; ii++)
				{
					for (i = 0; i < 100; i++)

						a[i] = rand();

					begintime = clock();
					RadixCountSort(a, 100);
					alltime += clock() - begintime;
				}
				cout << "基数计数100数据*100k次排序用时:" << alltime << "ms\n";

			}
			else if (switcher2 == 2)
			{
				iii = 0;
				cout << "输入十个数字(空格隔开)：";
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

				cout << "排序后:";
				for (i = 0; i < iii; i++)cout << a[i] << " ";
				cout << "\n基数计数排序数据用时:" << alltime << "ms\n";
				break;
			}
			break;
		case 7:/**
*  @name        : void ColorSort(int *a,int size)
*  @description : 颜色排序
*  @param       : 数组指针a（只含0，1，2元素），数组长度size
*/
			switcher2 = -1;
			cout << "1自动测试  2输入\n";
			std::cin >> switcher2;
			if (switcher2 == 1)
			{

				for (i = 0; i < num10000; i++)

					a[i] = rand() % 3;

				begintime = clock();
				ColorSort(a, num10000);

				alltime = clock() - begintime;
				cout << "颜色排序1w数据用时:" << alltime << "ms\n";

				for (i = 0; i < num50000; i++)
				{
					a[i] = rand() % 3;
				}
				begintime = clock();
				ColorSort(a, num50000);

				alltime = clock() - begintime;
				cout << "颜色排序5w数据用时:" << alltime << "ms\n";

				for (i = 0; i < num200000; i++)

					a[i] = rand() % 3;

				begintime = clock();
				ColorSort(a, num200000);
				alltime = clock() - begintime;
				cout << "颜色排序20w数据用时:" << alltime << "ms\n";

				alltime = 0;
				for (ii = 0; ii < 100000; ii++)
				{
					for (i = 0; i < 100; i++)

						a[i] = rand() % 3;

					begintime = clock();

					ColorSort(a, 100);
					alltime += clock() - begintime;
				}
				cout << "颜色排序100数据*100k次排序用时:" << alltime << "ms\n";

			}
			else if (switcher2 == 2)
			{
				cout << "输入十个数字(空格隔开) :";
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
				cout << "排序后:";

				for (i = 0; i < iii; i++)cout << a[i] << " ";
				cout << "\n颜色排序测试数据用时:" << alltime << "ms\n";
				break;
			}
			break;
		case 8:/**
*  @name        : 自拟
*  @description : 在一个无序序列中找到第K大/小的数
*  @param       : 数组指针a，数组长度size
*/
			switcher2 = -1;
			cout << "2输入\n";

			std::cin >> switcher2;
			if (switcher2 == 1)
			{

				for (i = 0; i < num10000; i++)

					a[i] = rand();

				begintime = clock();
				number = Find(a, num10000, 5000);

				alltime = clock() - begintime;
				cout << "number:" << number;

				cout << "\t查找1w数据用时:" << alltime << "ms\n";

				for (i = 0; i < num50000; i++)
				{
					a[i] = rand();
				}
				begintime = clock();

				number = Find(a, num50000, 5000);
				alltime = clock() - begintime;

				cout << "number:" << number;
				cout << "\t查找5w数据用时:" << alltime << "ms\n";

				for (i = 0; i < num200000; i++)

					a[i] = rand();

				begintime = clock();
				number = Find(a, num200000, 5000);

				alltime = clock() - begintime;
				cout << "number:" << number;

				cout << "\t查找20w数据用时:" << alltime << "ms\n";

				for (ii = 0; ii < 100000; ii++)
				{
					for (i = 0; i < 100; i++)

						a[i] = rand();

					begintime = clock();

					number = Find(a, 100, 50);
					alltime = clock() - begintime;

					cout << "\t查找100数据*100k次排序用时:" << alltime << "ms\n";


				}
			}
			else if (switcher2 == 2)
			{
				iii = 0;
				cout << "输入十个数字(空格隔开)：";
				for (num200000 = 0; num200000 < 10; num200000++)
				{
					std::cin >> number;
					a[iii] = number;
					iii++;
				}
				while (getchar() != '\n');
				cout << "查找第几大元素：";
				std::cin >> number;

				if (number < 1 || number>10) { cout << "超出!!!" << endl; break; }
				begintime = clock();
				number = Find(a, iii, number);

				alltime = clock() - begintime;

				cout << "number:" << number;
				cout << "\n查找测试数据用时:" << alltime << "ms\n";
				break;
			}
			break;
		}
		_getch();
		system("cls");
	}

	return 0;
}