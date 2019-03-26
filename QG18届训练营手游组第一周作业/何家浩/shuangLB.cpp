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
	cout << "�������һ���ڵ������Ŷ��int���ͣ�" << endl;
	while (1 != scanf_s("%d", &p1->data))
	{
		cout << "�����������룡" << endl;
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

//��q������ǰ����һ���ڵ�
bool shuangLB::push_front(int & e)
{
	head = new Node;
	head->data = e;
	head->next = p1;
	return false;
}

//��wɾ��������ǰ�Ľڵ�
bool shuangLB::pop_front()
{
	if (head->next == nullptr)
	{
		cout << "��~�Ѿ�������ɾ����" << endl;
		_getch();
		return true;
	}
	p1 = p1->next;
	delete head;
	head = p1;
	head->prior = nullptr;
	cout << "��ɾ��ͷ���" << endl;
	_getch();
	return false;
}

//��e����������һ���ڵ�yes
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

//��rɾ���������Ľڵ�
bool shuangLB::pop_back()
{
	p1 = head;
	p2 = p1;
	int i = 1;
	if (head->next == nullptr)
	{
		cout << "�������㲻Ҫ��ɾ�˺ðɣ����������" << endl;
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

//��t������ĵ�n��Ԫ��ǰ����Ԫ��
bool shuangLB::insert(unsigned int index, int & e)
{
	//p1ָ��p2ָ�£�p3ָǰ
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

//��yɾ������ڵ�yes
bool shuangLB::erase(unsigned int index)//y
{
	if (head->next == nullptr)
	{
		cout << "��ɾ�˰���" << endl;
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

//��uɾ�����нڵ�
bool shuangLB::clear()
{
	for (; p1 != nullptr; )
	{
		p2 = p1;
		p1 = p1->next;
		delete p2;
	}

	cout << "��ɾ��ȫ��" << endl;
	cout << "Have a niceday!" << endl;
	head = new Node;
	p1 = head;
	p2 = head;
	cout << "�����ǿ�����" << endl << "�������һ���ڵ������Ŷ��int���ͣ�" << endl;
	while (1 != scanf_s("%d", &p1->data))
	{
		cout << "�����������룡" << endl;
		while (getchar() != '\n');
	}
	p1->next = nullptr;
	return false;
}

//��i��ѯԪ�ش治����
bool shuangLB::contain(int & e)
{
	for (; p1 != nullptr;)
	{
		if (p1->data == e)return true;
		p1 = p1->next;
	}
	return false;
}

//��o��ѯ����Ԫ������
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

//��p���������ÿ��Ԫ�ص���visitָ��ĺ���
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

//��������������������������Ҫ�ĺ���
void shuangLB::show()
{
	system("cls");
	cout << "������˫������" << endl;
	cout << "��q������ǰ����һ���ڵ�" << endl << "��wɾ��������ǰ�Ľڵ�" << endl << "��e����������һ���ڵ�" << endl;
	cout << "��rɾ���������Ľڵ�" << endl << "��t������ĵ�n��Ԫ��ǰ����Ԫ��" << endl << "��yɾ������ڵ�" << endl;
	cout << "��uɾ�����нڵ�" << endl << "��i��ѯԪ�ش治����" << endl << "��o��ѯ����Ԫ������" << endl;
	cout << "��p���������ÿ��Ԫ�ص���visitָ��ĺ���" << endl;
	cout << "�ǳ���лʦ�������Ը���ҵŶ" << endl << "ǿ���Ƽ�ʦ�����ظ���Σ���e�����ּӻس�����һ���϶�ڵ������" << endl;
	cout << endl;
	p1 = head;
	p2 = head;
	for (int i = 1; p1 != nullptr; i++, p1 = p1->next)
	{
		cout << "�ڵ�" << i << "��������" << p1->data << endl;
	}
	p1 = head;
	p2 = head;
	cout << "����������qwertyuiopasd��������" << endl;
}

