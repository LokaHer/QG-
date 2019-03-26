/**
 * ����ʱ��: 2019��3��22��20:34:46
 * ����:
 **/


#ifndef __QGFORWARD_LIST_H__
#define __QGFORWARD_LIST_H__

 /*
  * ��������
  */

class danLB 
{
	struct Node
	{
		int data;
		struct Node *next;
	};
public:
	Node* head;
	Node* tail;
	Node* p1;
	Node* p2;
	/*1
	 * ��ʼ������
	 */
	danLB();

	/*2
	 * ��������
	 */
	~danLB();

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
	unsigned int size();

	/*
	 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
	 */
	 bool traverse(void(*visit)(int& e));
	static void prints(int& e);

	/*
	 * ��ת����1234��ת����4321
	 */
	void reverse();

	/*
	 * �����л�
	 */
	bool isLoop();

	/*
	 * ż�ڵ㷴ת��1234��ת����2143
	 */
	bool reverseEven();

	/*
	 * �����м�ڵ�
	 */
	void middleElem();

	//��������������������������Ҫ�ĺ���
	void show();
};

#endif
