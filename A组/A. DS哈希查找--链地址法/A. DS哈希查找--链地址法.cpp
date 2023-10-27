#include<iostream>
using namespace std;
struct Node //由于哈希冲突用链地址法，所以加入第二个元素Node *next,
{
    int data;
    Node* next;//链表节点
};
Node* s[11]; //由于求余法作为哈希函数，所以哈希表分配mod11内存
void HashInsert(int key)  //插入方法
{
    Node* p = new Node;//创建新节点
    p->data = key;//赋值
    p->next = s[key % 11];
    s[key % 11] = p;//找到要插入的节点位置

}
int main()
{
    int n, key;
    while (cin >> n)
    {
        for (int i = 0; i < 11; i++)//初始化哈希表
        {
            s[i] = NULL; 
        }         
        while (n--)  //构建哈希表
        {
            cin >> key;
            HashInsert(key);
        }
        cin >> n;
        while (n--) //n次查询
        {
            cin >> key;
            Node* p = s[key % 11]; //找到key对应的链表s
            int num = 1;
            while (p) //对链表进行遍历查询
            {
                if (p->data == key)
                    break;
                p = p->next;
                num++;//查询深度
            }
            if (p)
            {
                cout << key % 11 << " " << num << endl;  //如果不是因为到尾NULL结束，输出哈希表链表位置和深度
            }
            else    //否则输出error，并加入哈希表
            {
                cout << "error" << endl;
                HashInsert(key);
            }
        }
    }
    return 0;
}
