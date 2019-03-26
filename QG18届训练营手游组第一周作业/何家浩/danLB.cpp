#include"danLB.h"
#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;



danLB::danLB()
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
}

danLB::~danLB()
{
	while (p1 != nullptr) 
	{
		p2 = p1;
		delete p1;
		p1 = p2->next;
	}
}


bool danLB::front(int &e)
{
	if (sizeof(head->data) == 0)return false;
	e = p1->data;
	return true;
}


bool danLB::back(int &e)
{
	p1 = head;
	for (; p1->next != nullptr; p1 = p1->next);
	if (sizeof(head->data) == 0)return false;
	return true;
}


//按q在链表前插入一个节点
bool danLB::push_front(int & e)
{
	head = new Node;
	head->data=e;
	head->next = p1;
	return false;
}

//按w删掉链表最前的节点
bool danLB::pop_front()
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
	cout << "已删除头结点" << endl;
	_getch();
	return false;
}

//按e在链表后插入一个节点
bool danLB::push_back(int & e)
{
	for (; p1->next != nullptr; p1 = p1->next);
	p2 = new Node;
	p1->next = p2;
	p2->data = e;
	p2->next = nullptr;
	return false;
}

//按r删掉链表最后的节点
bool danLB::pop_back()
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
bool danLB::insert(unsigned int index, int & e)
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
	Node* p3=head;
	while (i+2 < index)
	{
		if (p3 != nullptr)p3 = p3->next;
		i++;
	}
	p2 = new Node;
	p3->next = p2;
	p2->data = e;
	p2->next = p1;
	return true;
}

//按y删除任意节点
bool danLB::erase(unsigned int index)
{
	if (head->next==nullptr) 
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
			if (p1 != nullptr)p1 = p1->next;
			if (p2 != nullptr)p2 = p2->next;
			i++;
		}
		if(p1!=nullptr)p2->next = p1->next;
		delete p1;
	}
	return false;
}

//按u删掉所有节点
bool danLB::clear()
{
	for (; p1 != nullptr; )
	{
		p2 = p1;
		p1 = p1->next;
		delete p2;
	}
	
	cout << "已删除全部" << endl<<"现在是空链表哦"<<endl;
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
	return false;
}

//按i查询元素存不存在
bool danLB::contain(int & e)
{
	for (; p1 != nullptr;)
	{
		if (p1->data ==  e)return true;
		p1 = p1->next;
	}
	return false;
}

//按o查询链表元素数量
unsigned int danLB::size()
{
	unsigned int i = 0;
	for (; p1 != nullptr; i++)
	{
		p1 = p1->next;
	}
	_getch();
	return i;
}

//按p遍历链表对每个元素调用visit指向的函数
bool danLB::traverse(void(*visit)(int &e))
{
	while (p1 != nullptr)
	{
		visit(p1->data); 
		p1 = p1->next;
	}
	return true;
}
void danLB:: prints(int& e)
{
	cout << e << endl;
}

//按a翻转链表
void danLB::reverse()
{
	if (head == nullptr || head->next == nullptr)return;
	Node* p3;
	p1 = head;
	p2 = head->next;
	head->next = nullptr;
	while (p2)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	head = p1;
}

//按s查询链表是否成环
bool danLB::isLoop()
{
	if (head == nullptr)
	{
		cout << "找不到链表，请再来!" << endl;
			return false;
	}

	p1 = p2 = head;
	while (p1 != p2 && !p2&&p2->next != nullptr)
	{
		p1 = p1->next;
		p2 = p2->next;
		p2 = p2->next;
		if (p1 == p2)
		{
			return true;
		}
	}
	return false;
}

//按d偶节点反转链表
bool danLB::reverseEven()
{
	int i = 0;
	int temp1;
	for (p1 = head; p1 != nullptr; i++)p1=p1->next;//测节点数目
	p1 = head;
	p2 = p1->next;
	while (p2 != nullptr && i % 2 == 1)//奇数个节点
	{
	temp1 = p1->data;
	p1->data = p2->data;
	p2->data = temp1;
	p2 = p2->next->next;
	p1 = p1->next->next;
	}
	while (p2 != nullptr && i % 2 == 0)//偶数个节点
	{
		temp1 = p1->data;
		p1->data = p2->data;
		p2->data = temp1;
		if (p2->next == nullptr)break;
		p2 = p2->next->next;
		p1 = p1->next->next;
	}
	return false;
}

//返回中间节点
void danLB::middleElem()
{
	int i = 0;
	for (p1 = head; p1 != nullptr; i++)p1 = p1->next;//测节点数目
	p1 = p2 = head;
	if (head == nullptr)
	{
		cout << "找不到链表，请再来!" << endl;
		return;
	}
	if (head->next == nullptr)
	{
		cout << "中间节点为头结点" << endl;
		_getch();
		return;
	}
	if (i % 2 == 1)
	{
		while (p2->next != nullptr)
		{
			p1 = p1->next;
			p2 = p2->next;
			if(p2!=nullptr)p2 = p2->next;
		}
		cout << "中间节点的数值为" << p1->data << endl;
		_getch();
	}
	if (i % 2 == 0)
	{
		while (p2->next->next!=nullptr)
		{
			p1 = p1->next;
			p2 = p2->next;
			if(p2 != nullptr)p2= p2->next;
		}
		cout << "中间节点的数值为" << p1->data <<"还有"<<p1->next->data<< endl;
		_getch();
	}
}


//最最最最最最最最最最最最重要的函数
void danLB::show()
{
	system("cls");
	cout << "这里是单向链表" << endl;
	cout << "按q在链表前插入一个节点" << endl << "按w删掉链表最前的节点" << endl << "按e在链表后插入一个节点" << endl;
	cout << "按r删掉链表最后的节点" << endl << "按t在链表的第n个元素前插入元素" << endl << "按y删除任意节点" << endl;
	cout << "按u删掉所有节点" << endl << "按i查询元素存不存在" << endl << "按o查询链表元素数量" << endl;
	cout << "按p遍历链表对每个元素调用visit指向的函数" << endl << "按a翻转链表" << endl << "按s查询链表是否成环" << endl;
	cout << "按d偶节点反转链表" << endl << "按f查询中间节点" << endl;
	cout << "非常感谢师兄来测试该作业哦" << endl << "强烈推荐师兄先重复多次：按e加数字加回车创建一个较多节点的链表" << endl;
	cout << endl;
	cout << endl;
	p1 = head;
	p2 = head;
	for (int i=1; p1 != nullptr;i++,p1=p1->next)
	{
		cout << "节点"<<i<<"的数据是"<<p1->data << endl;
	}
	p1 = head;
	p2 = head;
	cout << "您还可以用qwertyuiopasd继续操作"<<endl;
}


