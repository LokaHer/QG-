/**
 * 创建时间: 2019年3月22日20:34:46
 * 作者:
 **/


#ifndef __QGLIST_H__
#define __QGLIST_H__

 /*
  * 双向链表
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
	 * 初始化链表
	 */
	shuangLB();

	/*
	 * 销毁链表
	 */
	~shuangLB();

	/*
	 * 返回链表中第一个元素的引用
	 */
	bool front(int& e);

	/*
	 * 返回链表中最后一个元素的引用
	 */
	bool back(int& e);

	/*
	 * 在链表第一个元素前添加元素e
	 */
	bool push_front(int& e);

	/*
	 * 删除链表第一个元素
	 */
	bool pop_front();

	/*
	 * 在链表最后一个元素后添加元素e
	 */
	bool push_back(int& e);

	/*
	 * 删除链表最后一个元素
	 */
	bool pop_back();

	/*
	 * 在链表的第index + 1个元素前插入元素e
	 */
	bool insert(unsigned int index, int& e);

	/*
	 * 删除任意位置元素
	 */
	bool erase(unsigned int index);

	/*
	 * 清空链表
	 */
	bool clear();

	/*
	 * 查找元素是否存在
	 */
	bool contain(int& e);

	/*
	 * 返回链表中元素的数量
	 */
	int size();

	/*
	 * 遍历链表, 对每个元素调用visit指向的函数!!!!
	 */
	bool traverse(void(*visit)(int& e));
	static void prints(int& e);

	void show();
};

#endif

