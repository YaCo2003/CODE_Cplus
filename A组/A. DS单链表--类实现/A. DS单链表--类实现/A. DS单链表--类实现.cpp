// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#define ok 0
#define error -1

//链表节点定义
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
//带头结点的单链表类定义
class LinkList
{
public:
    ListNode* head;
    int len;
    //操作定义
    LinkList();
    ~LinkList();
    ListNode* LL_index(int i);//返回第i个结点的指针,如果不存在返回NULL
    int LL_get(int i);//获取第i个元素的数据
    int LL_insert(int i, int item);//把数值item插入第i个位置
    int LL_del(int i);//删除第i个结点
    void LL_display();//输出单链表的内容
};
LinkList::LinkList()
{
    head = new ListNode();
    len = 0;
}
LinkList::~LinkList()//链表回收,要逐个结点回收
{
    ListNode* p, * q;
    p = head;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        delete q;
    }
    len = 0;
    head = NULL;
}
ListNode* LinkList::LL_index(int i)
{
    int j = 0;
    ListNode* p = head;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p)
    {
        return NULL;
    }
    else
    {
        return p;
    }
}
int LinkList::LL_get(int i)
{
    if (i <= 0 || i > len)
    {
        return error;
    }
    int j = 0;
    ListNode* p = head;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p)
    {
        return error;
    }
    else
    {
        return p->data;
    }
}
int LinkList::LL_insert(int i, int item)
{
    if (i<1 || i>len + 1)
    {
        return error;
    }
    else
    {
        //尾插法
        ListNode* p, * s;
        p = LL_index(i - 1);
        s = new ListNode();
        s->data = item;
        s->next = p->next;
        p->next = s;
        len++;
        return ok;
    }
}
int LinkList::LL_del(int i)
{
    if (i <= 0 || i > len)
    {
        return error;
    }
    ListNode* p, * s;
    p = LL_index(i - 1);
    s = p->next;
    p->next = s->next;
    delete s;
    len--;
    return ok;
}
void LinkList::LL_display()
{
    ListNode* p;
    p = head->next;
    while (p)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}
int main()
{
    int n;
    int data;
    LinkList list;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> data;
        list.LL_insert(i, data);
    }
    list.LL_display();
    for (int j = 0; j < 2; j++)
    {
        int i = 0;
        cin >> i >> data;
        if (list.LL_insert(i, data) != -1)
        {
            list.LL_display();
        }
        else
        {
            cout << "error" << endl;
        }
    }
    for (int j = 0; j < 2; j++)
    {
        int i = 0;
        cin >> i;
        if (list.LL_del(i) != -1)
        {
            list.LL_display();
        }
        else
        {
            cout << "error" << endl;
        }
    }
    for (int j = 0; j < 2; j++)
    {
        int i = 0;
        cin >> i;
        if (list.LL_get(i) != -1)
        {
            cout << list.LL_get(i) << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }
}