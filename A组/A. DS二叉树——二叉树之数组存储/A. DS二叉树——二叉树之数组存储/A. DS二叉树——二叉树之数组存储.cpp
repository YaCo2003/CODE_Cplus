// A. DS二叉树——二叉树之数组存储.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class TreeNode
{
    int len;
    int* tree;
    void PreOrder(int i);
public:
    TreeNode();
    ~TreeNode();
    void PreOrder();
};
TreeNode::TreeNode()
{
    cin >> len;
    tree = new int[len];
    for (int i = 0; i < len; i++)
    {
        cin >> tree[i];
    }
}
TreeNode::~TreeNode()
{
    delete[]tree;
}
void TreeNode::PreOrder()
{
    PreOrder(0);
    cout << endl;
}
void TreeNode::PreOrder(int i)
{
    if (tree[i] != 0 && i < len)
    {
        cout << tree[i] << ' ';
        PreOrder(2 * i + 1);
        PreOrder(2 * i + 2);
    }

}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        TreeNode myTree;
        myTree.PreOrder();
    }
    return 0;
}
