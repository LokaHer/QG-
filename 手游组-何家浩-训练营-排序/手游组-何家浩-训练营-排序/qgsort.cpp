#include "qgsort.h"

void swap(int * a, int * b)
{
	int p = *b;
	*b = *a;
	*a = p;
}

/**
*  @name        : void insertSort(int *a,int n);
*  @description : 插入排序
*  @param       : 数组指针 a, 数组长度 n
*/
void insertSort(int * a, int n)
{
	for (int i = 1; i < n; i++) 
	{
		int key = a[i],j = i - 1;
		while ((j >= 0) && (key < a[j])) 
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}
/**
*  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
*  @description : 归并排序（合并数组）
*  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
*/
void MergeArray(int * a, int begin, int mid, int end, int * temp)
{
	int i, j, k;
	i = begin; j = mid + 1; k = 0;
	while ((i <= mid) && (j <= end))
	{
		if (a[i] < a[j])temp[k++] = a[i++];
		else temp[k++] = a[j++];
	
	}
	while (i <= mid)temp[k++] = a[i++];
	while (j <= end)temp[k++] = a[j++];
	for (int q = 0; q < k; q++)a[q + begin] = temp[q];


}
/**
*  @name        : void MergeSort(int *a,int begin,int end,int *temp);
*  @description : 归并排序
*  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
*/
void MergeSort(int * a, int begin, int end, int * temp)
{
	if (begin >= end)return;
	int mid = begin + (end - begin) / 2;

	MergeSort(a, begin, mid, temp);
	MergeSort(a, mid + 1, end, temp);
	MergeArray(a, begin, mid, end, temp);
}
/**
*  @name        : void QuickSort(int *a, int begin, int end);
*  @description : 快速排序（递归版）
*  @param       : 数组指针a，数组起点begin，数组终点end
*/
void QuickSort_Recursion(int * a, int begin, int end)
{
	if (begin > end)return;
	int key = a[begin], p = begin, p2 = end;
	if (p == p2){swap(&a[p], &a[p2]);}
	while (p != p2)
	{

		while (a[p2] >= key && p < p2)--p2;

		while (a[p] <= key && p < p2)++p; 

		if (p < p2)
		{swap(&a[p], &a[p2]);}
	}
	a[begin] = a[p];
	a[p] = key;

	QuickSort_Recursion(a, begin, p - 1);

	QuickSort_Recursion(a, p2 + 1, end);
	return;
}
/**
*  @name        : void QuickSort(int *a,int size)
*  @description : 快速排序（非递归版）
*  @param       : 数组指针a，数组长度size
*/

void QuickSort(int * a, int size)
{
	int min = 0, max = size - 1, midle = (min + max) / 2;
	pair<int, int>ap;
	ap.first = 0;

	ap.second = size - 1;
	stack<pair<int, int>>p;
	p.push(ap);
	while (!p.empty())
	{
		ap = p.top();
		p.pop();

		min = ap.first;
		max = ap.second;

		midle = Partition(a, min, max);
		if (min < midle - 1)
		{
			ap.first = min;
			ap.second = midle - 1;
			p.push(ap);
		}
		if (max > midle + 1)
		{
			ap.first = midle + 1;
			ap.second = max;
			p.push(ap);
		}
	}
}
/**
*  @name        : void QuickSort(int *a, int begin, int end)
*  @description : 快速排序（枢轴存放）
*  @param       : 数组指针a，数组起点begin，数组终点end
*/
int Partition(int * a, int begin, int end)
{
	int asd = a[begin], p = begin, q = end;
	if (p == q)

	{
		swap(&a[p], &a[q]);
	}
	while (p != q)
	{

		while (a[q] >= asd && p < q)
			--q;
		while (a[p] <= asd && p < q)
			++p;

		if (p < q)

		{
			swap(&a[p], &a[q]);
		}
	}
	swap(&a[begin], &a[p]);
	return p;
}
/**
*  @name        : void CountSort(int *a, int size , int max)
*  @description : 计数排序
*  @param       : 数组指针a，数组长度size，数组最大值max
*/
void CountSort(int * a, int size, int max)
{
	int *b = new int[max + 1]{ 0 };
	int *c = new int[size] {0};
	int t = 0;
	for (t = 0; t < size; t++)++b[a[t]];
	for (t = 1; t < max + 1; t++)b[t] += b[t - 1];
	for (t = size - 1; t >= 0; t--)c[--b[a[t]]] = a[t];
	for (t = 0; t < size; t++)a[t] = c[t];
	delete(b);
	delete(c);
	b = nullptr;
	c = nullptr;
}
/**
*  @name        : void RadixCountSort(int *a,int size)
*  @description : 基数计数排序
*  @param       : 数组指针a，数组长度size
*/
void RadixCountSort(int * a, int size)
{
	vector<vector<int>>b(10, vector<int>());
	int *c = new int[size];

	int t = 0, i, p, status, num = 0, key = a[0];

	for (t = 0; t < size; t++)if (a[t] > key)key = a[t];
	
	while (key / 10 != 0){++num;key /= key;}
	++num;
	for (t = 1; t <= num; t++)
	{
		for (status = size - 1; status >= 0; status--)
		{
			p = t - 1;
			key = a[status];
			while (key / 10 != 0 && p > 0)

			{key /= 10;--p;}

			if (p > 0)key = 0;
			else key %= 10;
			b[key].push_back(a[status]);
		}

		for (i = 0, p = 0; i < size; i++)
		{
			while (b[p].empty())++p;
			a[i] = b[p].back();
			b[p].pop_back();
		}
	}
	delete(c);
	c = nullptr;
}
/**
*  @name        : void ColorSort(int *a,int size)
*  @description : 颜色排序
*  @param       : 数组指针a（只含0，1，2元素），数组长度size
*/
void ColorSort(int * a, int size)
{
	int p1 = 0, p2 = 0, p3 = size - 1;
	while (p2 != p3)
	{
		while (a[p2] != 2 && p2 < p3)++p2;
		if (a[p2] == 2 && a[p3] != 2)swap(&a[p2], &a[p3]);
		while (a[p3] == 2 && p2 < p3)--p3;
		if (a[p3] == 0 && a[p2] != 0)swap(&a[p2], &a[p3]);
	}
	while (p1 != p2)
	{
		while (a[p2] != 0 && p1 < p2)--p2;
		if (a[p2] == 0 && a[p1] != 0)swap(&a[p2], &a[p1]);
		while (a[p1] == 0 && p1 < p2)++p1;
		if (a[p2] == 0 && a[p1] != 0)swap(&a[p2], &a[p1]);
	}
}
/**
*  @name        : 自拟
*  @description : 在一个无序序列中找到第K大/小的数
*  @param       : 数组指针a，数组长度size
*/
int Find(int * a, int size, int num)
{
	int min = 0, max = size - 1, middle = (min + max) / 2;
	pair<int, int>ap;
	ap.first = 0;                              ap.second = size - 1;
	stack<pair<int, int>>p;
	p.push(ap);
	while (!p.empty())
	{


		ap = p.top();
		p.pop();
		min = ap.first;
		max = ap.second;

		middle = Partition(a, min, max);
		if (middle == (num - 1))return a[middle];
		if (min < middle - 1)
		{

			ap.first = min;
			ap.second = middle - 1;
			p.push(ap);
		}
		if (max > middle + 1)
		{
			ap.first = middle + 1;
			ap.second = max;
			p.push(ap);
		}
	}
	return a[num - 1];
}