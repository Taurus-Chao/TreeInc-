#include<iostream>
#include<algorithm>
#include"Mytree.h"

using namespace std;

//判断树是否为空
bool Mytree::isempty()
{
	if (root == nullptr)return true;
	else return false;
}

//将树初始化为空
Node* Mytree::makeEmpty()
{
	makeEmpty_helper(root->left);
	makeEmpty_helper(root->right);
	delete root;
	root = nullptr;
	return root;
}
void Mytree::makeEmpty_helper(Node *node)
{
	if (node != nullptr)
	{
		makeEmpty_helper(node->left);
		makeEmpty_helper(node->right);
		delete node;
	}
	return;
}

//求树的size
int Mytree::size()
{
	return size_helper(root);
}
int Mytree::size_helper(Node* node)
{
	if (node == nullptr)return 0;
	else
	{
		return 1 + size_helper(node->left) + size_helper(node->right);
	}
}

//求树的最大深度
int  Mytree::maxdepth()
{
	return maxdepth_helper(root);
}
int Mytree::maxdepth_helper(Node* node)
{
	if (node == nullptr)return 0;
	else
	{
		return 1 + max(maxdepth_helper(node->left) , maxdepth_helper(node->right));
	}
}

//先序遍历树的元素
bool Mytree::print_preorder()
{
	return print_preorder_helper(root);
}
bool Mytree::print_preorder_helper(Node *node)
{
	if (node == nullptr)return false;
	else
	{
		cout << node->element << '\t';
		print_preorder_helper(node->left);
		print_preorder_helper(node->right);
	}
}

//寻找元素值为K的节点
Node* Mytree::find(int k)
{
	return find_helper(root, k);
}
Node* Mytree::find_helper(Node *node, int k)
{
	if (node == nullptr)return nullptr;
	else
	{
		if (node->element == k)return node;
		if (node->element > k)return find_helper(node->left,k);
		else return find_helper(node->right,k);
	}
}

//寻找最小值
Node* Mytree::findMin()
{
	return findMin_helper(root);
}
Node* Mytree::findMin_helper(Node *node)
{
	if (node == nullptr)return nullptr;
	if (node->left == nullptr)return node;
	else return findMin_helper(node->left);
}

//寻找最大值
Node* Mytree::findMax()
{
	return findMax_helper(root);
}
Node* Mytree::findMax_helper(Node *node)
{
	if (node == nullptr)return nullptr;
	if (node->right == nullptr)return node;
	else return findMax_helper(node->right);
}

//插入元素值为k的节点
bool Mytree::insert(int k)
{
	root = insert_helper(root,k);
	return true;
}
Node* Mytree::insert_helper(Node* node, int k)
{
	if (node == nullptr)
	{
		node = new Node;
		node->element = k;
	}
	else
	{
		if (k < node->element) node->left = insert_helper(node->left, k);
		else if (k > node->element) node->right = insert_helper(node->right, k);
	}
	return node;
}


//删除元素k值为k的节点
bool Mytree::mydelete(int k)
{
	mydelete_helper(root, k);
	return true;
}
Node* Mytree::mydelete_helper(Node* node, int k)
{
	if (node==nullptr)
	return nullptr;
	else
	{
		if (node->element == k)
		{
			if (node->left == nullptr)
			{
				Node *tmp=node;
				node = node->right;
				delete tmp;
				return node;
			}
			else if (node->right == nullptr)
			{
				Node *tmp = node;
				node = node->left;
				delete tmp;
				return node;
			}
			else
			{
				Node *min=findMin_helper(node->right);
				node->element = min->element;
				node->right=mydelete_helper(node->right, node->element);
				return node;
			}
		}
		else
		{
			if (k < node->element) node->left = mydelete_helper(node->left, k);
			else node->right = mydelete_helper(node->right, k);
			return node;
		}
	}
}