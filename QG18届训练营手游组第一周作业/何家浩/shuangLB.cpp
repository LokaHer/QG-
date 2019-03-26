#include"shuangLB.h"
#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

shuangLB::shuangLB()
{
	cout << "Have a niceday!" << endl;
	head = new Node;
	p1 = head;
	p2 = head;
	cout << "请输入第一个节点的内容哦（int类型）" << endl;
	while (1 != scanf_s("%d", &p1->data))
	{
		cout << "错误！重新输入！" << endl;
		while (getchar() != '\n');
	}
	p1->next = nullptr;
	p1->prior = nullptr;
}

shuangLB::~shuangLB()
{
	while (p1 != nullptr)
	{
		p2 = p1;
		delete p1;
		p1 = p2->next;
	}
}

bool shuangLB::front(int& e)
{
	if (sizeof(head->data) == 0)return false;
	
	return true;
}

bool shuangLB::back(int& e)
{
	p1 = head;
	for (; p1->next != nullptr; p1 = p1->next);
	if (sizeof(head->data) == 0)return false;
	e = p1->data;
	return true;
}

//按q在链表前插入一个节点
bool shuangLB::push_front(int & e)
{
	head = new Node;
	head->data = e;
	head->next = p1;
	return false;
}

//按w删掉链表最前的节点
bool shuangLB::pop_front()
{
	if (head->next == nullptr)
	{
		cout << "啊~已经不能再删了呢" << endl;
		_getch();
		return true;
	}
	p1 = p1->next;
	delete head;
	head = p1;
	head->prior = nullptr;
	cout << "已删除头结点" << endl;
	_getch();
	return false;
}

//按e在链表后插入一个节点yes
bool shuangLB::push_back(int & e)
{
	for (; p1->next != nullptr; p1 = p1->next);
	p2 = new Node;
	p1->next = p2;
	p2->prior = p1;
	p2->data = e;
	p2->next = nullptr;
	return false;
}

//按r删掉链表最后的节点
bool shuangLB::pop_back()
{
	p1 = head;
	p2 = p1;
	int i = 1;
	if (head->next == nullptr)
	{
		cout << "我求求你不要再删了好吧？真的求求你" << endl;
		_getch();
		return false;
	}
	for (; p1->next != nullptr;)
	{
		p1 = p1->next;
		i++;
	}
	delete p1;
	p1 = head;
	for (int j = 2; j < i; j++)
	{
		p1 = p1->next;
	}
	p1->next = nullptr;
	return true;
}

//按t在链表的第n个元素前插入元素
bool shuangLB::insert(unsigned int index, int & e)
{
	//p1指后，p2指新，p3指前
	unsigned int i = 1;
	p1 = head;
	while (i < index)
	{
		p1 = p1->next;
		i++;
	}
	i = 0;
	Node* p3 = head;
	while (i + 2 < index)
	{
		if (p3 != nullptr)p3 = p3->next;
		i++;
	}
	p2 = new Node;
	p3->next = p2;
	p2->data = e;
	p2->next = p1;
	p1->prior = p2;
	p2->prior = p3;
	return true;
}

//按y删除任意节点yes
bool shuangLB::erase(unsigned int index)//y
{
	if (head->next == nullptr)
	{
		cout << "别删了啊哥" << endl;
		_getch();
		return false;
	}
	if (index == 1)
	{
		head = head->next;
		delete p1;
	}
	else
	{
		unsigned int i = 2;
		p1 = p1->next;
		while (i < index)
		{
			if (p1 !=nullptr)p1 = p1->next;
			if (p2 != nullptr)p2 = p2->next;
			i++;
		}
		if (p1 != nullptr)p2->next = p1->next;
		delete p1;
	}
	return false;
}

//按u删掉所有节点
bool shuangLB::clear()
{
	for (; p1 != nullptr; )
	{
		p2 = p1;
		p1 = p1->next;
		delete p2;
	}

	cout << "已删除全部" << endl;
	cout << "Have a niceday!" << endl;
	head = new Node;
	p1 = head;
	p2 = head;
	cout << "现在是空链表" << endl << "请输入第一个节点的内容哦（int类型）" << endl;
	while (1 != scanf_s("%d", &p1->data))
	{
		cout << "错误！重新输入！" << endl;
		while (getchar() != '\n');
	}
	p1->next = nullptr;
	return false;
}

//按i查询元素存不存在
bool shuangLB::contain(int & e)
{
	for (; p1 != nullptr;)
	{
		if (p1->data == e)return true;
		p1 = p1->next;
	}
	return false;
}

//按o查询链表元素数量
int shuangLB::size()
{
	int i = 0;
	for (; p1 != nullptr; i++)
	{
		p1 = p1->next;
	}
	_getch();
	return i;
}

//按p遍历链表对每个元素调用visit指向的函数
bool shuangLB::traverse(void(*visit)(int &e))
{
	while (p1 != nullptr)
	{
		visit(p1->data);
		p1 = p1->next;
	}
	return true;
}
void shuangLB::prints(int& e)
{
	cout << e << endl;
}

//最最最最最最最最最最最最重要的函数
void shuangLB::show()
{
	system("cls");
	cout << "这里是双向链表" << endl;
	cout << "按q在链表前插入一个节点" << endl << "按w删掉链表最前的节点" << endl << "按e在链表后插入一个节点" << endl;
	cout << "按r删掉链表最后的节点" << endl << "按t在链表的第n个元素前插入元素" << endl << "按y删除任意节点" << endl;
	cout << "按u删掉所有节点" << endl << "按i查询元素存不存在" << endl << "按o查询链表元素数量" << endl;
	cout << "按p遍历链表对每个元素调用visit指向的函数" << endl;
	cout << "非常感谢师兄来测试该作业哦" << endl << "强烈推荐师兄先重复多次：按e加数字加回车创建一个较多节点的链表" << endl;
	cout << endl;
	p1 = head;
	p2 = head;
	for (int i = 1; p1 != nullptr; i++, p1 = p1->next)
	{
		cout << "节点" << i << "的数据是" << p1->data << endl;
	}
	p1 = head;
	p2 = head;
	cout << "您还可以用qwertyuiopasd继续操作" << endl;
}

