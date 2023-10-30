// ConsoleApplication9.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class TreeNode {
public:
	char data;
	TreeNode* left;
	TreeNode* right;
	TreeNode()
	{
		left = NULL;
		right = NULL;
	}
};

class Tree {
private:
	int i = 0;
	int len;
	string strtree;
	TreeNode* root;
	TreeNode* Createtree(int pos);
	void PrevTree(TreeNode* root);
public:
	Tree() {}
	~Tree() {}
	void PrevCreate(string str)
	{
		len = str.length();
		strtree.assign(str);//string赋值，用于两个字符串之间
		root = Createtree(0);
	}
	void PrevPrint()
	{
		PrevTree(root);
		cout << endl;
	}
};
TreeNode* Tree::Createtree(int pos)
{
	TreeNode* t;
	char ch;
	if (pos >= len)
	{
		return NULL;
	}
	ch = strtree[pos];
	if (ch == '0')
	{
		t = NULL;
	}
	else
	{
		t = new TreeNode();
		t->data = ch;
		t->left = Createtree(2 * pos + 1);//先序创建
		t->right = Createtree(2 * pos + 2);
	}
	return t;
}
void Tree::PrevTree(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data;
	PrevTree(root->left);
	PrevTree(root->right);
}
int main()
{
	int t;
	cin >> t;
	string str;
	Tree tr;
	while (t--)
	{
		cin >> str;
		tr.PrevCreate(str);
		tr.PrevPrint();
	}
}