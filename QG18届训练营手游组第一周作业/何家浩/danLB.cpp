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
	cout << "�������һ���ڵ������Ŷ��int���ͣ�" << endl;
	while (1 != scanf_s("%d", &p1->data))
	{
		cout << "�����������룡" << endl;
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


//��q������ǰ����һ���ڵ�
bool danLB::push_front(int & e)
{
	head = new Node;
	head->data=e;
	head->next = p1;
	return false;
}

//��wɾ��������ǰ�Ľڵ�
bool danLB::pop_front()
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
	cout << "��ɾ��ͷ���" << endl;
	_getch();
	return false;
}

//��e����������һ���ڵ�
bool danLB::push_back(int & e)
{
	for (; p1->next != nullptr; p1 = p1->next);
	p2 = new Node;
	p1->next = p2;
	p2->data = e;
	p2->next = nullptr;
	return false;
}

//��rɾ���������Ľڵ�
bool danLB::pop_back()
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
bool danLB::insert(unsigned int index, int & e)
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

//��yɾ������ڵ�
bool danLB::erase(unsigned int index)
{
	if (head->next==nullptr) 
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
			if (p1 != nullptr)p1 = p1->next;
			if (p2 != nullptr)p2 = p2->next;
			i++;
		}
		if(p1!=nullptr)p2->next = p1->next;
		delete p1;
	}
	return false;
}

//��uɾ�����нڵ�
bool danLB::clear()
{
	for (; p1 != nullptr; )
	{
		p2 = p1;
		p1 = p1->next;
		delete p2;
	}
	
	cout << "��ɾ��ȫ��" << endl<<"�����ǿ�����Ŷ"<<endl;
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
	return false;
}

//��i��ѯԪ�ش治����
bool danLB::contain(int & e)
{
	for (; p1 != nullptr;)
	{
		if (p1->data ==  e)return true;
		p1 = p1->next;
	}
	return false;
}

//��o��ѯ����Ԫ������
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

//��p���������ÿ��Ԫ�ص���visitָ��ĺ���
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

//��a��ת����
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

//��s��ѯ�����Ƿ�ɻ�
bool danLB::isLoop()
{
	if (head == nullptr)
	{
		cout << "�Ҳ�������������!" << endl;
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

//��dż�ڵ㷴ת����
bool danLB::reverseEven()
{
	int i = 0;
	int temp1;
	for (p1 = head; p1 != nullptr; i++)p1=p1->next;//��ڵ���Ŀ
	p1 = head;
	p2 = p1->next;
	while (p2 != nullptr && i % 2 == 1)//�������ڵ�
	{
	temp1 = p1->data;
	p1->data = p2->data;
	p2->data = temp1;
	p2 = p2->next->next;
	p1 = p1->next->next;
	}
	while (p2 != nullptr && i % 2 == 0)//ż�����ڵ�
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

//�����м�ڵ�
void danLB::middleElem()
{
	int i = 0;
	for (p1 = head; p1 != nullptr; i++)p1 = p1->next;//��ڵ���Ŀ
	p1 = p2 = head;
	if (head == nullptr)
	{
		cout << "�Ҳ�������������!" << endl;
		return;
	}
	if (head->next == nullptr)
	{
		cout << "�м�ڵ�Ϊͷ���" << endl;
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
		cout << "�м�ڵ����ֵΪ" << p1->data << endl;
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
		cout << "�м�ڵ����ֵΪ" << p1->data <<"����"<<p1->next->data<< endl;
		_getch();
	}
}


//��������������������������Ҫ�ĺ���
void danLB::show()
{
	system("cls");
	cout << "�����ǵ�������" << endl;
	cout << "��q������ǰ����һ���ڵ�" << endl << "��wɾ��������ǰ�Ľڵ�" << endl << "��e����������һ���ڵ�" << endl;
	cout << "��rɾ���������Ľڵ�" << endl << "��t������ĵ�n��Ԫ��ǰ����Ԫ��" << endl << "��yɾ������ڵ�" << endl;
	cout << "��uɾ�����нڵ�" << endl << "��i��ѯԪ�ش治����" << endl << "��o��ѯ����Ԫ������" << endl;
	cout << "��p���������ÿ��Ԫ�ص���visitָ��ĺ���" << endl << "��a��ת����" << endl << "��s��ѯ�����Ƿ�ɻ�" << endl;
	cout << "��dż�ڵ㷴ת����" << endl << "��f��ѯ�м�ڵ�" << endl;
	cout << "�ǳ���лʦ�������Ը���ҵŶ" << endl << "ǿ���Ƽ�ʦ�����ظ���Σ���e�����ּӻس�����һ���϶�ڵ������" << endl;
	cout << endl;
	cout << endl;
	p1 = head;
	p2 = head;
	for (int i=1; p1 != nullptr;i++,p1=p1->next)
	{
		cout << "�ڵ�"<<i<<"��������"<<p1->data << endl;
	}
	p1 = head;
	p2 = head;
	cout << "����������qwertyuiopasd��������"<<endl;
}


