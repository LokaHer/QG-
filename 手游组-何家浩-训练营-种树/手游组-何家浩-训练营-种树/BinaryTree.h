#ifndef _BIANRYTREE_H_
#define	_BIANRYTREE_H_
#include<stdio.h>
#include<stack>
#include<queue>
#include<conio.h>
#include<iostream>

template <class T>
class BinaryTree
{
protected:
	template<class T>
	struct  BiTNode {
		T	data;     // 数据域
		struct BiTNode  *lchild, *rchild;  // 左、右孩子指针
	};
	BiTNode<T> *Root;
public:


	/**
 *  @name        : BinaryTree();
 *  @description : 构造空二叉树T
 *  @param       :
 */
	BinaryTree();

	/**
	 *  @name        : ~BinaryTree();
	 *  @description : 摧毁二叉树T
	 *  @param       :
	 */
	~BinaryTree();

	/**
	 *  @name        : 	bool CreateBiTree(char* definition, int n);
	 *  @description : 构造二叉树T
	 *  @param       : 二叉树先序遍历字符串definition，数组二叉树长度n
	 */
	bool CreateBiTree(T* definition, int n);

	/**
	 *  @name        : 	bool PreOrderTraverse(void (*visit)(T e));
	 *  @description : 先序遍历二叉树T
	 *  @param       : 对结点的操作函数visit
	 */
	bool PreOrderTraverse(void(*visit)(T e));

	/**
	 *  @name        : 	bool PreOrderTraverse_Recursion(void(*visit)(T e), BinaryTree<T>::BiTNode<T> *tree);
	 *  @description : 先序遍历二叉树T(递归版)
	 *  @param       : 对结点的操作函数visit,树节点指针tree
	 */
	bool PreOrderTraverse_Recursion(void(*visit)(T e), BinaryTree<T>::BiTNode<T> *tree);

	/**
	 *  @name        : bool InOrderTraverse(void (*visit)(T e));
	 *  @description : 中序遍历二叉树T
	 *  @param       : 对结点的操作函数visit
	 */
	bool InOrderTraverse(void(*visit)(T e));

	/**
	 *  @name        : bool InOrderTraverse_Recursion(void (*visit)(T e), BinaryTree<T>::BiTNode<T> *tree);
	 *  @description : 中序遍历二叉树T(递归版)
	 *  @param       : 对结点的操作函数visit,树节点指针tree
	 */
	bool InOrderTraverse_Recursion(void(*visit)(T e), BinaryTree<T>::BiTNode<T> *tree);

	/**
	 *  @name        : bool PostOrderTraverse(void (*visit)(T e));
	 *  @description : 后序遍历二叉树T
	 *  @param       : 对结点的操作函数visit
	 */
	bool PostOrderTraverse(void(*visit)(T e));

	/**
	 *  @name        : bool PostOrderTraverse_Recursion(void(*visit)(T e), BinaryTree<T>::BiTNode<T> *tree);
	 *  @description : 后序遍历二叉树T
	 *  @param       : 对结点的操作函数visit,树节点指针tree
	 */
	bool PostOrderTraverse_Recursion(void(*visit)(T e), BinaryTree<T>::BiTNode<T> *tree);


	/**
	 *  @name        : bool LevelOrderTraverse(void (*visit)(T e));
	 *  @description : 层序遍历二叉树T
	 *  @param       : 对结点的操作函数visit
	 */
	bool LevelOrderTraverse(void(*visit)(T e));

	/**
	 *  @name        : int Value();
	 *  @description : 对构造出前缀表达式二叉树求值
	 *  @param       : 二叉树根结点T
	 *  @note        : 可在结点结构体中设置个Tag值标志数字与操作符来构造二叉树，
	 *                 可根据需要自行增加操作.
	 */
	int Value();

	int calc(BiTNode<char> * tree);
};

template<class T>
inline BinaryTree<T>::BinaryTree()
{
	Root = new BiTNode<T>;
	Root->lchild = NULL;
	Root->rchild = NULL;
}

template<class T>
inline BinaryTree<T>::~BinaryTree()
{
	BiTNode<T> *bit;
	std::queue<BiTNode<T>*> q1;
	q1.push(Root);
	while (!q1.empty())
	{
		bit = q1.front();
		q1.pop();
		if (NULL != bit->lchild) q1.push(bit->lchild);
		if (NULL != bit->rchild) q1.push(bit->rchild);
		delete bit;
	}
}

template<class T>
inline bool BinaryTree<T>::CreateBiTree(T * definition, int n)
{
	if (NULL == definition)return false;
	BiTNode<T> *bitArray = new BiTNode<T>[n];
	for (int i = 0; i < n; i++) bitArray[i] = NULL;
	BiTNode<T> *bit1, *bit2;
	Root->data = definition[0];
	bitArray[0] = Root;
	for (int i = 1; i < n; i++)
	{
		if (i % 2 == 1)
		{
			bit1 = new BiTNode<T>;
			bit1->data = definition[i];
			bit1->lchild = NULL;
			bit1->rchild = NULL;
			bitArray[i] = bit1;
			bit2 = bitArray[(i - 1) / 2];
			bit2->lchild = bit1;
		}
		else
		{
			bit1 = new BiTNode<T>;
			bit1->data = definition[i];
			bit1->lchild = NULL;
			bit1->rchild = NULL;
			bitArray[i] = bit1;
			bit2 = bitArray[(i - 1) / 2];
			bit2->rchild = bit1;
		}
	}
	return true;
}

template<class T>
inline bool BinaryTree<T>::PreOrderTraverse(void(*visit)(T e))
{
	if (Root->lchild == NULL && Root->rchild == NULL)return false;
	BiTNode<T> bit;
	std::stack<BiTNode> s1;
	s1.push(Root);
	while (!s1.empty())
	{
		bit = s1.top();
		s1.pop();
		visit(bit.data);
		if (bit.lchild != NULL)s1.push(bit.lchild);
		if (bit.rchild != NULL)s1.push(bit.rchild);
	}
	return true;
}

template<class T>
inline bool BinaryTree<T>::PreOrderTraverse_Recursion(void(*visit)(T e), BinaryTree<T>::BiTNode<T>* tree)
{
	if (Root->lchild == NULL && Root->rchild == NULL)return false;
	visit(tree->data);
	if (Root->lchild != NULL)PreOrderTraverse_Recursion(visit, Root->lchild);
	if (Root->rchild != NULL)PreOrderTraverse_Recursion(visit, Root->rchild);
	return true;
}

template<class T>
inline bool BinaryTree<T>::InOrderTraverse(void(*visit)(T e))
{
	if (Root->lchild == NULL && Root->rchild == NULL)return false;
	BiTNode<T> bit;
	std::stack<BiTNode> s1;
	s1.push(Root);
	while (!s1.empty())
	{
		bit = s1.top();
		if (bit.lchild != NULL)s1.push(bit.lchild);
		s1.pop();
		visit(bit.data);
		if (bit.rchild != NULL)s1.push(bit.rchild);
	}
	return true;
}

template<class T>
inline bool BinaryTree<T>::InOrderTraverse_Recursion(void(*visit)(T e), BinaryTree<T>::BiTNode<T>* tree)
{
	if (Root->lchild == NULL && Root->rchild == NULL)return false;
	if (Root->lchild != NULL)PreOrderTraverse_Recursion(visit, Root->lchild);
	visit(tree->data);
	if (Root->rchild != NULL)PreOrderTraverse_Recursion(visit, Root->rchild);
	return true;
}

template<class T>
inline bool BinaryTree<T>::PostOrderTraverse(void(*visit)(T e))
{
	if (Root->lchild == NULL && Root->rchild == NULL)return false;
	BiTNode<T> bit;
	std::stack<BiTNode> s1;
	s1.push(Root);
	while (!s1.empty())
	{
		bit = s1.top();
		if (bit.lchild != NULL)s1.push(bit.lchild);
		if (bit.rchild != NULL)s1.push(bit.rchild);
		s1.pop();
		visit(bit.data);
	}
	return true;
}

template<class T>
inline bool BinaryTree<T>::PostOrderTraverse_Recursion(void(*visit)(T e), BinaryTree<T>::BiTNode<T>* tree)
{
	if (Root->lchild == NULL && Root->rchild == NULL)return false;
	if (Root->lchild != NULL)PreOrderTraverse_Recursion(visit, Root->lchild);
	if (Root->rchild != NULL)PreOrderTraverse_Recursion(visit, Root->rchild);
	visit(tree->data);
	return true;
}

template<class T>
inline bool BinaryTree<T>::LevelOrderTraverse(void(*visit)(T e))
{
	if (Root->lchild == NULL || Root->rchild == NULL)return false;
	BiTNode<T> *bit;
	std::queue<BiTNode<T>*> q1;
	q1.push(Root);
	while (!q1.empty())
	{
		bit = q1.front();
		q1.pop();
		if (NULL != bit->lchild) q1.push(bit->lchild);
		if (NULL != bit->rchild) q1.push(bit->rchild);
		visit(bit->data);
	}
	return true;
}

template<class T>
inline int BinaryTree<T>::Value()
{
	std::cout << "请输入中缀表达式" << std::endl;
	char key1;
	std::stack<char> s1, s2, final;
	std::stack<BiTNode<char>*> bitStack;
	BiTNode<char> *bit, *bit2;
	while (1)
	{
		key1 = _getch();
		std::cout << key1;
		if (key1 != 13)s1.push(key1);
		else break;
	}
	while (!s1.empty())
	{
		key1 = s1.top();
		s1.pop();
		switch (key1)
		{
		case'0':
		case'1':
		case'2':
		case'3':
		case'4':
		case'5':
		case'6':
		case'7':
		case'8':
		case'9':
			final.push(key1);
			break;
		case'+':
		case'-':
			if (s2.empty() || s2.top() == ')' || s2.top() == '+' || s2.top() == '-') s2.push(key1);
			else
			{
				while (!(s2.empty() || s2.top() == ')' || s2.top() == '+' || s2.top() == '-'))
				{
					final.push(s2.top());
					s2.pop();
				}
				s2.push(key1);
			}
			break;
		case'*':
		case'/':
		case')':
			s2.push(key1);
			break;
		case'(':
			while (s2.top() != ')')
			{
				final.push(s2.top());
				s2.pop();
			}
			s2.pop();
			break;
		}
	}
	while (!s2.empty())
	{
		final.push(s2.top());
		s2.pop();
	}
	s1 = final;
	std::cout << std::endl;
	std::cout << "前缀表达式为:" << std::endl;
	while (!s1.empty())
	{
		std::cout << s1.top();
		s1.pop();
	}
	std::cout << std::endl;
	while (!final.empty())
	{
		s1.push(final.top());
		final.pop();
	}
	final = s1;
	while (!final.empty())
	{
		key1 = final.top();
		final.pop();
		switch (key1)
		{
		case'0':
		case'1':
		case'2':
		case'3':
		case'4':
		case'5':
		case'6':
		case'7':
		case'8':
		case'9':
			bit = new BiTNode<char>;
			bit->data = key1;
			bit->lchild = NULL;
			bit->rchild = NULL;
			bitStack.push(bit);
			break;
		case'+':
		case'-':
		case'*':
		case'/':
			bit2 = new BiTNode<char>;
			bit2->data = key1;
			bit = bitStack.top();
			bitStack.pop();
			bit2->lchild = bit;
			bit = bitStack.top();
			bitStack.pop();
			bit2->rchild = bit;
			bitStack.push(bit2);
			break;
		}
	}
	std::cout << "答案为:";
	return calc(bitStack.top());
}

template<class T>
inline int BinaryTree<T>::calc(BiTNode<char> * tree)
{
	switch (tree->data)
	{
	case'+':
		return calc(tree->lchild) + calc(tree->rchild);
	case'-':
		return calc(tree->lchild) - calc(tree->rchild);
	case'*':
		return calc(tree->lchild) * calc(tree->rchild);
	case'/':
		return calc(tree->lchild) / calc(tree->rchild);
	case'0':
		return 0;
	case'1':
		return 1;
	case'2':
		return 2;
	case'3':
		return 3;
	case'4':
		return 4;
	case'5':
		return 5;
	case'6':
		return 6;
	case'7':
		return 7;
	case'8':
		return 8;
	case'9':
		return 9;
	}
}

#endif 