#ifndef MYTREE_FUN
#define MYTREE_FUN
#include"Mytree.h"
#include<list>
#include<vector>
using namespace std;
//关于二叉树的习题，封装成类，继承之前树的实现
class MytreeFun :public Mytree
{
public:
	Node* floor(int k);//寻找二叉查找树中第一个element值不大于k的节点
	Node* ceiling(int k);//寻找二叉查找树中第一个element值不小于k的节点
	bool isBST();//判断该数是否为二叉查找树，在本例程中一定是会返回true的
	void mirror();//将树进行镜像翻转
	bool isSameTree(Mytree *t);//判断this和t所指的两棵树是否相同,形参为父类，这样实参为子类的时候会自动转化为父类,反过来父类无法转化为子类
	//不需要多态因为并不需要子类的功能或数据成员
	bool isfoldable();//判断二叉树是否可折叠。

	Node* getIterative(int k);//采用循环方式获取指定元素值k的节点
	void insertIterative(int k);//采用循环方式插入指定元素值k的节点
	void printInorderIterative();//采用循环方式顺序遍历（中序遍历，左跟右）
	void printPreorderIterative();//采用循环方式先序遍历（根左右）
	void printPostorderIterative();//采用循环方式后序遍历（左右根）

	void printLevelOrder();//按层的顺序打印
	void printLevelOrderReverse();//按层逆序的顺序打印
	void printLevelOrderZigzag();//按层“之”字形序的顺序打印

	void buildTreeBy_PreIn(int *preorder,int *inorder,int len);//采用先序遍历和中序遍历的结果还原二叉树
	void sortedArray2BST(int *array,int len);//根据给定的已排序数组构造深度尽可能小的二叉查找树
	void sortedList2BST(list<int> &l);//根据给定的已排序链表构造深度尽可能小的二叉查找树

	bool hasPathSum(int k);//判断是否存在从根节点到叶子的路径使路径上的元素和为k
	void printPathSum(int k);//打印出从根节点到叶子使路径上的元素和为k的路径
	bool findPaths(int k);//判断是否存在从任意节点到任意的路径使路径上的元素和为k（深度优先搜索）
	Node* lowestCommonAncestor(Node* n1,Node* n2);//寻找二叉查找树BST中两个节点最近的共同祖先

private:
	Node* floor_helper(Node* node, int k);
	Node* ceiling_helper(Node* node,int k); 
	bool isBST_helper(Node* node,int min,int max);
	void mirror_helper(Node* node);
	bool isSameTree_helper(Node *n1,Node *n2);
	bool isfoldable_helper( Node* n1, Node* n2);
	Node* buildTreeBy_PreIn_helper(int *preorder,int *inorder,int prebegin,int preend,int inbegin,int inend);
	Node* sortedArray2BST_helper(int *array, int begin, int end);
	Node* sortedList2BST_helper(list<int> &l);
	bool hasPathSum_helper(Node* n,int k);
	void printPathSum_helper(Node* n,int k,vector<vector<Node*>>& res,vector<Node*> tmp);
	bool findPaths_helper(Node* n,int k);
	Node* lowestCommonAncestor_helper(Node* ancestor, Node* n1, Node* n2);
};


#endif