#include"MytreeFun.h"
#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<list>
using namespace std;

Node* MytreeFun::floor(int k)
{
	return floor_helper(root, k);
}
Node* MytreeFun::floor_helper(Node *node, int k)
{
	if (node == nullptr)return nullptr;//base����
	else if (node->element == k)return node;
	else if (node->element > k)return floor_helper(node->left, k);
	else
	{
		Node* tmp = floor_helper(node->right, k);
		if (tmp == nullptr)return node;
		else return tmp;
	}
}

Node* MytreeFun::ceiling(int k)//Ѱ�Ҷ���������е�һ��elementֵ��С��k�Ľڵ㡣
{
	return ceiling_helper(root, k);
}
Node* MytreeFun::ceiling_helper(Node* node, int k)
{
	if (node == nullptr)return nullptr;//base����
	else if (node->element == k)return node;
	else if (node->element < k)return ceiling_helper(node->right, k);
	else
	{
		Node* tmp = ceiling_helper(node->left, k);
		if (tmp == nullptr)return node;
		else return tmp;
	}
}

bool MytreeFun::isBST()//�жϸ����Ƿ�Ϊ������������ڱ�������һ���ǻ᷵��true��
{
	return isBST_helper(root, INT_MIN, INT_MAX);
}
bool MytreeFun::isBST_helper(Node* node, int min, int max)
{
	if (node == nullptr)return true;
	else
	{
		if (node->element >= min&&node->element <= max&&
			isBST_helper(node->left, min, node->element) &&
			isBST_helper(node->right, node->element, max))
			return true;
		else return false;
	}
}

void MytreeFun::mirror()//�������о���ת
{
	mirror_helper(root);
}
void MytreeFun::mirror_helper(Node* node)
{
	if (node != nullptr)
	{
		mirror_helper(node->left);
		mirror_helper(node->right);
		Node *tmp = node->left;
		node->left = node->right;
		node->right = tmp;
	}
	
}

bool MytreeFun::isSameTree(Mytree *t)//�ж�this��t��ָ���������Ƿ���ͬ
{
	return isSameTree_helper(root, t->root);
}
bool MytreeFun::isSameTree_helper(Node *n1, Node *n2)
{
	if (n1 == nullptr&&n2 == nullptr)return true;
	else
	{
		if (n1 != nullptr&&n2 != nullptr&&n1->element==n2->element)
		{
			return isSameTree_helper(n1->left, n2->left) && isSameTree_helper(n1 -> right, n2->right);
		}
		return false;
	}
}

bool MytreeFun::isfoldable()//�ж϶������Ƿ���۵�
{
	if (root == nullptr)return true;
	return isfoldable_helper(root->left, root->right);
}

bool MytreeFun::isfoldable_helper( Node* n1, Node* n2)
{
	if (n1 == nullptr&&n2 == nullptr)return true;
	else if (n1 != nullptr&&n2 != nullptr)
	{
		return isfoldable_helper(n1->left, n2->right) && isfoldable_helper(n1->right, n2->left);
	}
	return false;
}

Node* MytreeFun::getIterative(int k)//����ѭ����ʽ��ȡָ��Ԫ��ֵk�Ľڵ�
{
	Node* n = root;
	while (n!=nullptr)
	{
		if (n->element == k)return n;
		if (k < n->element)n = n->left;
		else n = n->right;
	}
	return nullptr;
}

void  MytreeFun::insertIterative(int k)//����ѭ����ʽ����ָ��Ԫ��ֵk�Ľڵ�
{
	if (root == nullptr)
	{
		root = new Node;
		root->element = k;
		return;
	}
	Node* parent = nullptr;
	Node* current = root;
	while (current != nullptr)
	{
		parent = current;
		if (current->element == k)return;
		else if (k < current->element)current = current->left;
		else current = current->right;
	}
	current = new Node;
	current->element = k;
	if (k < parent->element)parent->left = current;
	else parent->right = current;
}

void MytreeFun::printInorderIterative()//����ѭ����ʽ˳��������������:����ң�
{
	stack<Node*>s;
	if (root == nullptr)return;
	Node* n = root;
	while (true)
	{
		while (n != nullptr)
		{
			s.push(n);
			n = n->left;
		}
		if (s.size() == 0)return;
		Node *tmp = s.top();
		s.pop();
		cout << tmp->element << '\t';
		n = tmp->right;
	}
}

void MytreeFun::printPreorderIterative()//����ѭ����ʽ��������������ң�
{
	if (root == nullptr)return;
	Node* node = root;
	stack<Node*>s;
	s.push(node);
	while (s.size() != 0)
	{
		node = s.top();
		s.pop();
		if (node != nullptr)
		{
			cout << node->element << '\t';
			s.push(node->right);
			s.push(node->left);
		}
	}
}

void MytreeFun::printPostorderIterative()//����ѭ����ʽ������������Ҹ���
{
	if (root == nullptr)return;
	Node* node = root;
	stack<pair<Node*,bool>>s;
	s.push({root,false});
	while (s.size() != 0)
	{
		pair<Node*, bool>tmp;
		tmp = s.top();
		s.pop();
		if (tmp.first == nullptr)continue;
		if (tmp.second == true)
		{
			cout << tmp.first->element << '\t';
		}
		else{
			s.push(make_pair(tmp.first, true));
			s.push(make_pair(tmp.first->right, false));
			s.push(make_pair(tmp.first->left, false));
		}
	
	}
}
void MytreeFun::printLevelOrder()//�����˳���ӡ
{
	if (root == nullptr)return;
	vector<Node*>level;
	vector<vector<Node*>>res;
	level.push_back(root);
	while (level.size() != 0)
	{
		res.push_back(level);
		vector<Node*>nextlevel;
		for (auto it : level)
		{
			if (it->left != nullptr)
				nextlevel.push_back(it->left);
			if (it->right != nullptr)
				nextlevel.push_back(it->right);
		}
		swap(level, nextlevel);//��������ָ�룬���ڵ�level��nextlevel���ͷŵľֲ�������ԭ����level��
	}
	for (auto out : res)
	{
		for (auto in : out)
			cout << in->element<<'\t';
		cout << endl;
	}
}

void MytreeFun::printLevelOrderReverse()//���������˳���ӡ,ֻ��Ҫ�������res�����depue��res��front push����
{
	if (root == nullptr)return;
	vector<Node*>level;
	vector<vector<Node*>>res;
	level.push_back(root);
	while (level.size() != 0)
	{
		res.push_back(level);
		vector<Node*>nextlevel;
		for (auto it : level)
		{
			if (it->left != nullptr)
				nextlevel.push_back(it->left);
			if (it->right != nullptr)
				nextlevel.push_back(it->right);
		}
		swap(level, nextlevel);//��������ָ�룬���ڵ�level��nextlevel���ͷŵľֲ�������ԭ����level��
	}
	for (auto out = res.rbegin(); out != res.rend();out++)
	{
		for (auto in : *out)
			cout << in->element << '\t';
		cout << endl;
	}
}

void MytreeFun::printLevelOrderZigzag()//���㡰֮���������˳���ӡ,����flagʵ��
{
	if (root == nullptr)return;
	vector<Node*>level;
	vector<vector<Node*>>res;
	level.push_back(root);
	bool flag = true;
	while (level.size() != 0)
	{
		res.push_back(level);
		vector<Node*>nextlevel;
		if (flag == true)
		{
			for (auto it : level)
			{
				if (it->left != nullptr)
					nextlevel.push_back(it->left);
				if (it->right != nullptr)
					nextlevel.push_back(it->right);
			}
		}
		else
		{
			for (auto it = level.rbegin(); it != level.rend(); it++)
			{
				if ((*it)->right != nullptr)
					nextlevel.push_back((*it)->right);
				if ((*it)->left != nullptr)
					nextlevel.push_back((*it)->left);
			}
		}
		swap(level, nextlevel);//��������ָ�룬���ڵ�level��nextlevel���ͷŵľֲ�������ԭ����level��
		flag ^= true;
	}
	for (auto out : res)
	{
		for (auto in : out)
			cout << in->element << '\t';
		cout << endl;
	}
}

void MytreeFun::buildTreeBy_PreIn(int *preorder, int *inorder, int len)//���������������������Ľ����ԭ������
{
	root = buildTreeBy_PreIn_helper(preorder, inorder, 0, len - 1, 0, len - 1);
}

Node* MytreeFun::buildTreeBy_PreIn_helper(int *preorder, int *inorder, int prebegin, int preend, int inbegin, int inend)
{
	if (preend < prebegin)return nullptr;
	Node* node = new Node;
	int rootval = preorder[prebegin];
	node->element = rootval;
	int index;
	for (int i = inbegin; i <= inend; i++)
	{
		if (inorder[i] == rootval)
		{
			index = i;
			break;
		}
	}
	//�ҵ�index֮�󣬴�inbegin��index-1�Ľڵ���һ������preorder���������Ľڵ������Դ�ȷ����һ�ε���preorder���±ꡣ
	node->left = buildTreeBy_PreIn_helper(preorder, inorder, prebegin + 1, prebegin + index - inbegin, inbegin, index - 1);
	node->right = buildTreeBy_PreIn_helper(preorder, inorder, prebegin + index - inbegin+1, preend,  index + 1,inend);
	return node;
}

void MytreeFun::sortedArray2BST(int *array,int len)//���ݸ��������������鹹����Ⱦ�����С�Ķ��������
{
	root = sortedArray2BST_helper(array, 0, len - 1);
}
Node* MytreeFun::sortedArray2BST_helper(int *array, int begin, int end)
{
	if (end < begin)return nullptr;
	int mid = (end + begin) / 2;
	Node* node = new Node;
	node->element = array[mid];
	node->left = sortedArray2BST_helper(array, begin, mid - 1);
	node->right = sortedArray2BST_helper(array, mid + 1, end);
	return node;
}

void MytreeFun::sortedList2BST(list<int> &l)//���ݸ�������������������Ⱦ�����С�Ķ��������
{
	root = sortedList2BST_helper(l);
}
Node* MytreeFun::sortedList2BST_helper(list<int> &l)
{
	if (l.size() == 0)return nullptr;
	auto slow = l.begin();
	auto fast = l.begin();
	while ( ++fast != l.end() && ++fast != l.end())slow++;
	auto mid = slow;
	Node* node = new Node;
	node->element = *mid;
	/*auto test = --mid;
	auto test2 = l.begin();*/
	node->left = sortedList2BST_helper(list<int>(l.begin(),mid));
	node->right = sortedList2BST_helper(list<int>(++mid, l.end()));
	return node;
}

bool MytreeFun::hasPathSum(int k)//�ж��Ƿ���ڴӸ��ڵ㵽Ҷ�ӵ�·��ʹ·���ϵ�Ԫ�غ�Ϊk
{
	if (root == nullptr)return false;
	return hasPathSum_helper(root, k);
}
bool MytreeFun::hasPathSum_helper(Node* n, int k)
{
	if (n == nullptr)
	{
		return false;
	}
	if (n->left == nullptr&&n->right == nullptr&&n->element == k)return true;
	int tmp = k - n->element;
	return hasPathSum_helper(n->left, tmp) || hasPathSum_helper(n->right, tmp);//�����Ҷ�ӽڵ㵫element������k�������´εݹ鷵��false
}

void MytreeFun::printPathSum(int k)//��ӡ���Ӹ��ڵ㵽Ҷ��ʹ·���ϵ�Ԫ�غ�Ϊk��·
{
	if (root == nullptr)return;
	vector<vector<Node*>> res;
	vector<Node*>tmp;
	printPathSum_helper(root, k, res, tmp);
	if (res.size() == 0)
	{
		cout << "DO NOT EXIST!";
		return;
	}
	cout << "PATH IS:" << endl;
	for (auto out : res)
	{
		for (auto in : out)
			cout << in->element << '\t';
		cout << endl;
	}
}
void MytreeFun::printPathSum_helper(Node* n, int k, vector<vector<Node*>> &res, vector<Node*> tmp)//tmp��ֵ���ݣ�ÿ�ε���ʱ������ʱ������
{
	if (n->left==nullptr&&n->right==nullptr)
	{
		if (n->element == k)
		{
			tmp.push_back(n);
			res.push_back(tmp);
			return;
		}
		else return;
	}
	tmp.push_back(n);
	int nextk = k - n->element;
	if (n->left!=nullptr)
	printPathSum_helper(n->left, nextk, res, tmp);
	if (n->right!=nullptr)
	printPathSum_helper(n->right, nextk, res, tmp);
}

bool MytreeFun::findPaths(int k)//�ж��Ƿ���ڴ�����ڵ㵽�����·��ʹ·���ϵ�Ԫ�غ�Ϊk���������������
{
	if (root == nullptr)return false;
	return findPaths_helper(root, k);

}
bool MytreeFun::findPaths_helper(Node* n, int k)
{
	if (n != nullptr)
		return hasPathSum_helper(n, k) || findPaths_helper(n->left, k) || findPaths_helper(n->right, k);
	return false;
}

Node* MytreeFun::lowestCommonAncestor(Node* n1, Node* n2)//Ѱ�������ڵ�����Ĺ�ͬ����
{
	if (root == nullptr)return nullptr;
	return lowestCommonAncestor_helper(root, n1, n2);
}

Node* MytreeFun::lowestCommonAncestor_helper(Node* ancestor, Node* n1, Node* n2)
{
	if (n1->element < ancestor->element&&n2->element < ancestor->element)
		return lowestCommonAncestor_helper(ancestor->left, n1, n2);
	if (n1->element> ancestor->element&&n2->element > ancestor->element)
		return lowestCommonAncestor_helper(ancestor->right, n1, n2);
	return ancestor;
}