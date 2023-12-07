#include<iostream>
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
	ListNode* head;
	int len;
	LinkList() 
	{
		head = new ListNode();
		len = 0;
	}
	~LinkList() 
	{
		ListNode* p = head;
		ListNode* q;
		while (p != NULL) 
		{
			q = p;
			p = p->next;
			delete q;
		}
		len = 0;
		head = NULL;
	}
	ListNode* LL_index(int i);
	int LL_insert(int i, int item);
	int LL_swap(int pa, int pb);
	void LL_display();
};
ListNode* LinkList::LL_index(int i) 
{
	ListNode* p = head;
	if (i == 0) 
	{
		return p;
	}
	int j = 1;
	p = p->next;
	while ((p != NULL) && (j < i)) 
	{
		p = p->next;
		j++;
	}
	if ((p == NULL) || (i < j)) 
	{
		return 0;
	}
	else 
	{
		return p;
	}
}
int LinkList::LL_insert(int i, int item) 
{
	if ((i <= 0) || (i > len + 1)) 
	{
		return 0;
	}
	ListNode* p = LL_index(i - 1);
	if (p == NULL) {
		return 0;
	}
	ListNode* s = new ListNode();
	s->data = item;
	s->next = p->next;
	p->next = s;
	len++;
	return 1;
}
int LinkList::LL_swap(int pa, int pb) 
{
	if ((pa <= 0) || (pa > len) || (pb <= 0) || (pb > len))
	{
		return 0;
	}
	ListNode* p = LL_index(pa - 1);
	ListNode* q = LL_index(pb - 1);
	//考虑pa,pb相邻
	if (p->next == q) 
	{//少一个等号！！！
		p->next = p->next->next;
		q->next = p->next->next;
		p->next->next = q;
		return 1;
	}
	//保存pa位，先交换前驱
	ListNode* s = p->next;
	p->next = q->next;
	q->next = s;
	//保存pb下一位，交换后继
	s = p->next->next;
	p->next->next = q->next->next;
	q->next->next = s;
	return 1;
}
void LinkList::LL_display() 
{
	ListNode* p = head->next;
	while (p) 
	{
		cout << p->data << " ";
		p = p->next;//竟然忘记了，无止境输出11
	}
	cout << endl;
}
int main() 
{
	int len, item;
	cin >> len;
	LinkList mylist;
	for (int i = 1; i <= len; i++) 
	{
		cin >> item;
		mylist.LL_insert(i, item);
	}
	mylist.LL_display();
	int times = 2;
	int pa, pb;
	while (times--) 
	{
		cin >> pa >> pb;
		if (mylist.LL_swap(pa, pb) == 1)
		{
			mylist.LL_display();
		}
		else {
			cout << "error" << endl;
		}
	}
	return 0;
}