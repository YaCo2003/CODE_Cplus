// A. DS循环链表—约瑟夫环(Ver. I - A).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode()
    {
        next = NULL;
    }
};
class LinkList
{
public:
    int len;
    ListNode* head;
    LinkList();
    ~LinkList();
    void create(int n);//创建链表
    void test(int k, int s);
};
LinkList::LinkList()
{
    head = new ListNode();
    head->next = NULL;
    len = 0;
}
LinkList::~LinkList() 
{
    delete head;
}
void LinkList::create(int n)
{
    ListNode* p = head;
    for (int i = 1; i <= n; i++)
    {
        ListNode* newnode = new ListNode();
        newnode->data = i;
        p->next = newnode;
        p = p->next;
    }
    p->next = head;
    //创建循环链表的关键：让尾结点指向头结点
    len = n;
}

void LinkList::test(int k, int s)
{
    //先找到第s个人
    ListNode* p = head;
    for (int i = 1; i < s; i++)
    {
        p = p->next;
    }
    //开始报数
    while (len)
    {
        if (p->next == head)//删除结点使得p->next为头节点，则p要多移一次。
        {
            p = p->next;
        }
        for (int i = 1; i < k; i++)
        {
            p = p->next;
            if (p->next == head)//在p向后位移的时候如果遇到头结点，多移一次。
            {
                p = p->next;
            }
        }
        ListNode* q = p->next;
        cout << q->data;
        p->next = q->next;//先变指针域，改为删去的节点的下一位
        delete q;
        len--;
        if (len != 0) 
        {
            cout << " ";
        }
    }
    cout << endl;
}
int main()
{
    LinkList list;
    int N, K, S;
    while (cin >> N >> K >> S)
    {
        list.create(N);
        list.test(K, S);
    }
    return 0;
}

