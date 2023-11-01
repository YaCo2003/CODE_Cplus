// A. DS二叉树--赫夫曼树的构建与编码（不含代码框架）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
//  构建节点
class Node
{
public:
	int left, right;
	int weight;
	int parent;
};
class HufTree
{
public:
	Node* huftree;	//huftree来存放各个节点
	int max = 10000;//max为最大权（为了后面与其他权值相比较）
	int len;		//len为节点个数；
	int lnum;		//lnum为叶子个数；
	string* code;	//code来存放各个节点的对应编码

	void Init(int n, int* wei);//初始化
	void SelectMin(int pos, int* s0, int* s1);//选出两个最小的权值
	void Coding();	//编码
};


void HufTree::Init(int n, int* wei)
{
	//创建2n-1个节点
	//其中，1到lnum为原节点  ，lnum+1 到 2lnum-1为生成的huffman根节点

	lnum = n;//叶子节点
	len = 2 * n - 1; //总节点
	huftree = new Node[2 * n];

	code = new string[lnum + 1];

	//for (i = 1; i <= n; i++)
	//{
	//	huftree[i].weight = wei[i - 1];
	//}

	for (int i = 1; i <= len; i++)
	{
		if (i <= n)
		{
			huftree[i].weight = wei[i - 1];//要求数组从1开始访问，所以huftree[i].weight = wei[i - 1]
			
		}
		else
		{
			huftree[i].weight = 0;//大于n就放0，表示新的根节点
		}

		huftree[i].parent = 0;
		huftree[i].left = 0;
		huftree[i].right = 0;
	}

	for (int i = lnum + 1; i <= len; i++)
	{
		int s0, s1;
		SelectMin(i - 1, &s0, &s1);//选出两个最小权值
		huftree[s0].parent = huftree[s1].parent = i;//i=n+1;
		huftree[i].left = s0;
		huftree[i].right = s1;
		huftree[i].weight = huftree[s0].weight + huftree[s1].weight;
	}
}
void HufTree::SelectMin(int pos, int* s0, int* s1)
{
	int w0, w1, i;
	w0 = w1 = max;
	*s0 = *s1 = 0;
	for (i = 1; i <= pos; i++)   //其实就是遍历原节点 1到n
	{
		if (w0 > huftree[i].weight && !huftree[i].parent) //两个判断条件1，w0大于 wi，2，wi的双亲下标为0
		{
			w1 = w0;
			*s1 = *s0;
			w0 = huftree[i].weight;
			*s0 = i;
		}
		else if (w1 > huftree[i].weight && !huftree[i].parent)
		{
			w1 = huftree[i].weight;
			*s1 = i;
		}
	}
}
void HufTree::Coding()
{
	char* tmp;
	int i, c, f, start;
	tmp = new char[lnum];
	tmp[lnum - 1] = '\0';
	for (i = 1; i <= lnum; i++)
	{
		start = lnum - 1;
		for (c = i, f = huftree[i].parent; f != 0; c = f, f = huftree[f].parent)
		{
			if (huftree[f].left == c)
			{
				tmp[--start] = '0';
			}
			else
			{
				tmp[--start] = '1';
			}
			code[i].assign(&tmp[start]);
		}
	}
	delete[]tmp;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int* weight = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> weight[i];
		}
		HufTree tree;
		tree.Init(n, weight);
		tree.Coding();
		for (int i = 1; i <= n; i++)
		{
			cout << tree.huftree[i].weight << "-";
			cout << tree.code[i] << endl;
		}
		delete[]weight;
	}
}