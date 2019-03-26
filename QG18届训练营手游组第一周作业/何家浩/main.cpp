#include"main.h"
using namespace std;
int k = 0;

void say1()
{
	cout << "这里是单向链表" << endl;
	cout << "按q在链表前插入一个节点" << endl << "按w删掉链表最前的节点" << endl << "按e在链表后插入一个节点" << endl;
	cout << "按r删掉链表最后的节点" << endl << "按t在链表的第n个元素前插入元素" << endl << "按y删除任意节点" << endl;
	cout << "按u删掉所有节点" << endl << "按i查询元素存不存在" << endl << "按o查询链表元素数量" << endl;
	cout << "按p遍历链表对每个元素调用visit指向的函数" << endl << "按a翻转链表" << endl << "按s查询链表是否成环" << endl;
	cout << "按d偶节点反转链表" << endl << "按f查询中间节点" << endl;
	cout << "非常感谢师兄来测试该作业哦" << endl << "强烈推荐师兄先重复多次：按e加数字加回车创建一个较多节点的链表" << endl;
	cout << endl;
}
void say2()
{
	cout << "这里是双向链表" << endl;
	cout << "按q在链表前插入一个节点" << endl << "按w删掉链表最前的节点" << endl << "按e在链表后插入一个节点" << endl;
	cout << "按r删掉链表最后的节点" << endl << "按t在链表的第n个元素前插入元素" << endl << "按y删除任意节点" << endl;
	cout << "按u删掉所有节点" << endl << "按i查询元素存不存在" << endl << "按o查询链表元素数量" << endl;
	cout << "按p遍历链表对每个元素调用visit指向的函数" << endl;
	cout << "非常感谢师兄来测试该作业哦" << endl << "强烈推荐师兄先重复多次：按e加数字加回车创建一个较多节点的链表" << endl;
	cout << endl;
}





int main()
{
	system("color F0");
	cout << "请选择单链表（按1）or双链表（按2）" << endl;
	int x=0;
	while (1 != scanf_s("%d", &x) || x < 1 || x > 2)
	{
		cout<<"错误！重新输入！"<<endl;
		while (getchar() != '\n');
	}
	if (x == 1)
	{
		danLB d1;
		int temp=0;
		unsigned int index;
		say1();
		while (true)
		{
			char a = _getch();
			if (a == 'q')
			{
				cout << "请输入在头部添加的节点data哦（int类型）" << endl;
				while (1 != scanf_s("%d", &temp))
				{
					cout << "错误！重新输入！"<<endl;
					while (getchar() != '\n');
				}
				d1.push_front(temp);
			}
			if (a == 'w')
			{
				d1.pop_front();
			}
			if (a == 'e')
			{
				cout << "请输入在尾部添加的节点data哦（int类型）" << endl;
				while (1 != scanf_s("%d", &temp))  
				{
					cout << "错误！重新输入！" << endl;
					while (getchar() != '\n');
				}
				d1.push_back(temp);
			}
			if (a == 'r')
			{
				d1.pop_back();
			}
			if (a == 't')
			{
				cout << "将在第n个元素前插入元素，请输入n（n不能为1哦谢谢）" << endl;
				int i = 0;
				for (d1.p1 = d1.head; d1.p1 != nullptr; i++)d1.p1 = d1.p1->next;//测节点数目
				while (1 != scanf_s("%d", &index)||(int)index < 2|| (int)index > i)
				{
					cout << "错误！重新输入！" << endl;
					while (getchar() != '\n');
				}
				cout << "请输入该节点的内容哦（int类型）" << endl;
				while (1 != scanf_s("%d", &temp))
				{
					cout << "错误！重新输入！" << endl;
					while (getchar() != '\n');
				}
				d1.insert(index, temp);
			}
			if (a == 'y')
			{
				
				while (d1.p1 != nullptr)
				{
					d1.p1 = d1.p1->next;
					k++;
				}
				d1.p1 = d1.head;
				cout << "请输入你想删除的节点" << endl;
				while (1 != scanf_s("%d", &index)|| (int)index>k|| (int)index<1)
				{
					cout << "错误！重新输入！" << endl;
					while (getchar() != '\n');
				}
				d1.erase(index);
			}
			if (a == 'u')
			{
				d1.clear();
			}
			if (a == 'i')
			{
				cout << "请输入你想查找的那个存不存在的元素" << endl;
				while (1 != scanf_s("%d", &temp))
				{
					cout << "错误！重新输入！" << endl;
					while (getchar() != '\n');
				}
				if (d1.contain(temp))
				{
					cout << "存在！！！" << endl;
					_getch();
				}
				else
				{
					cout << "不存在！！！" << endl;
					_getch();
				}
			}
			if (a == 'o')
			{
				cout << "链表元素数量为" << d1.size() << endl;
				_getch();
			}
			if (a == 'p')
			{
				d1.traverse(d1.prints);	
				_getch();
			}
			if (a == 'a')
			{
				d1.reverse();
			}
			if (a == 's')
			{
				if (d1.isLoop())
				{
					cout << "该链表存在环！！！" << endl;
					_getch();
				}
				else
				{
					cout << "该链表没有环！！！" << endl;
					_getch();
				}
			}
			if (a == 'd')
			{
				d1.reverseEven();
			}

			if (a == 'f')
			{
				d1.middleElem();
			}
			d1.show();
		}
	}
	if (x == 2)
	{
		
		shuangLB d2;
		int temp;
		unsigned int index;
		say2();
		while (true)
		{
			char a = _getch();
			if (a == 'q')
			{
				cout << "请输入在头部添加的节点data哦（int类型）" << endl;
				while (1 != scanf_s("%d", &temp))
				{
					cout << "错误！重新输入！" << endl;
					while (getchar() != '\n');
				}
				d2.push_front(temp);
			}
			if (a == 'w')
			{
				d2.pop_front();
			}
			if (a == 'e')
			{
				cout << "请输入在尾部添加的节点data哦（int类型）" << endl;
				while (1 != scanf_s("%d", &temp))
				{
					cout << "错误！重新输入！" << endl;
					while (getchar() != '\n');
				}
				d2.push_back(temp);
			}
			if (a == 'r')
			{
				d2.pop_back();
			}
			if (a == 't')
			{
				cout << "将在第n个元素前插入元素，请输入n（n不能为1哦谢谢）" << endl;
				while (1 != scanf_s("%d", &index))
				{
					cout << "错误！重新输入！" << endl;
					while (getchar() != '\n');
				}
				cout << "请输入该节点的内容哦（int类型）" << endl;
				while (1 != scanf_s("%d", &temp))
				{
					cout << "错误！重新输入！" << endl;
					while (getchar() != '\n');
				}
				d2.insert(index, temp);
			}
			if (a == 'y')
			{

				while (d2.p1 != nullptr)
				{
					d2.p1 = d2.p1->next;
					k++;
				}
				d2.p1 = d2.head;
				cout << "请输入你想删除的节点" << endl;
				while (1 != scanf_s("%d", &index) || (int)index > k || (int)index < 1)
				{
					cout << "错误！重新输入！" << endl;
					while (getchar() != '\n');
				}
				d2.erase(index);
			}
			if (a == 'u')
			{
				d2.clear();
			}
			if (a == 'i')
			{
				cout << "请输入你想查找的那个存不存在的元素" << endl;
				while (1 != scanf_s("%d", &temp))
				{
					cout << "错误！重新输入！" << endl;
					while (getchar() != '\n');
				}
				if (d2.contain(temp))
				{
					cout << "存在！！！" << endl;
					_getch();
				}
				else
				{
					cout << "不存在！！！" << endl;
					_getch();
				}
			}
			if (a == 'o')
			{
				cout << "链表元素数量为" << d2.size() << endl;
				_getch();
			}
			if (a == 'p')
			{
				d2.traverse(d2.prints);
				_getch();
			}
			d2.show();
		}
	}
	system("pause");
	return 0;
}