#ifndef MYTREE_FUN
#define MYTREE_FUN
#include"Mytree.h"
#include<list>
#include<vector>
using namespace std;
//���ڶ�������ϰ�⣬��װ���࣬�̳�֮ǰ����ʵ��
class MytreeFun :public Mytree
{
public:
	Node* floor(int k);//Ѱ�Ҷ���������е�һ��elementֵ������k�Ľڵ�
	Node* ceiling(int k);//Ѱ�Ҷ���������е�һ��elementֵ��С��k�Ľڵ�
	bool isBST();//�жϸ����Ƿ�Ϊ������������ڱ�������һ���ǻ᷵��true��
	void mirror();//�������о���ת
	bool isSameTree(Mytree *t);//�ж�this��t��ָ���������Ƿ���ͬ,�β�Ϊ���࣬����ʵ��Ϊ�����ʱ����Զ�ת��Ϊ����,�����������޷�ת��Ϊ����
	//����Ҫ��̬��Ϊ������Ҫ����Ĺ��ܻ����ݳ�Ա
	bool isfoldable();//�ж϶������Ƿ���۵���

	Node* getIterative(int k);//����ѭ����ʽ��ȡָ��Ԫ��ֵk�Ľڵ�
	void insertIterative(int k);//����ѭ����ʽ����ָ��Ԫ��ֵk�Ľڵ�
	void printInorderIterative();//����ѭ����ʽ˳��������������������ң�
	void printPreorderIterative();//����ѭ����ʽ��������������ң�
	void printPostorderIterative();//����ѭ����ʽ������������Ҹ���

	void printLevelOrder();//�����˳���ӡ
	void printLevelOrderReverse();//���������˳���ӡ
	void printLevelOrderZigzag();//���㡰֮���������˳���ӡ

	void buildTreeBy_PreIn(int *preorder,int *inorder,int len);//���������������������Ľ����ԭ������
	void sortedArray2BST(int *array,int len);//���ݸ��������������鹹����Ⱦ�����С�Ķ��������
	void sortedList2BST(list<int> &l);//���ݸ�������������������Ⱦ�����С�Ķ��������

	bool hasPathSum(int k);//�ж��Ƿ���ڴӸ��ڵ㵽Ҷ�ӵ�·��ʹ·���ϵ�Ԫ�غ�Ϊk
	void printPathSum(int k);//��ӡ���Ӹ��ڵ㵽Ҷ��ʹ·���ϵ�Ԫ�غ�Ϊk��·��
	bool findPaths(int k);//�ж��Ƿ���ڴ�����ڵ㵽�����·��ʹ·���ϵ�Ԫ�غ�Ϊk���������������
	Node* lowestCommonAncestor(Node* n1,Node* n2);//Ѱ�Ҷ��������BST�������ڵ�����Ĺ�ͬ����

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