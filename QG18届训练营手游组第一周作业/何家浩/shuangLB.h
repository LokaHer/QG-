/**
 * ����ʱ��: 2019��3��22��20:34:46
 * ����:
 **/


#ifndef __QGLIST_H__
#define __QGLIST_H__

 /*
  * ˫������
  */
class shuangLB 
{
protected:
	struct Node 
	{
		int data;
		struct Node *prior;
		struct Node *next;
	};

public:
	Node* head;
	Node* tail;
	Node* p1;
	Node* p2;
	/*
	 * ��ʼ������
	 */
	shuangLB();

	/*
	 * ��������
	 */
	~shuangLB();

	/*
	 * ���������е�һ��Ԫ�ص�����
	 */
	bool front(int& e);

	/*
	 * �������������һ��Ԫ�ص�����
	 */
	bool back(int& e);

	/*
	 * �������һ��Ԫ��ǰ���Ԫ��e
	 */
	bool push_front(int& e);

	/*
	 * ɾ�������һ��Ԫ��
	 */
	bool pop_front();

	/*
	 * ���������һ��Ԫ�غ����Ԫ��e
	 */
	bool push_back(int& e);

	/*
	 * ɾ���������һ��Ԫ��
	 */
	bool pop_back();

	/*
	 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
	 */
	bool insert(unsigned int index, int& e);

	/*
	 * ɾ������λ��Ԫ��
	 */
	bool erase(unsigned int index);

	/*
	 * �������
	 */
	bool clear();

	/*
	 * ����Ԫ���Ƿ����
	 */
	bool contain(int& e);

	/*
	 * ����������Ԫ�ص�����
	 */
	int size();

	/*
	 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���!!!!
	 */
	bool traverse(void(*visit)(int& e));
	static void prints(int& e);

	void show();
};

#endif

