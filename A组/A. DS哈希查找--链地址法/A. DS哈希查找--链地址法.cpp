#include<iostream>
using namespace std;
struct Node //���ڹ�ϣ��ͻ������ַ�������Լ���ڶ���Ԫ��Node *next,
{
    int data;
    Node* next;//����ڵ�
};
Node* s[11]; //�������෨��Ϊ��ϣ���������Թ�ϣ�����mod11�ڴ�
void HashInsert(int key)  //���뷽��
{
    Node* p = new Node;//�����½ڵ�
    p->data = key;//��ֵ
    p->next = s[key % 11];
    s[key % 11] = p;//�ҵ�Ҫ����Ľڵ�λ��

}
int main()
{
    int n, key;
    while (cin >> n)
    {
        for (int i = 0; i < 11; i++)//��ʼ����ϣ��
        {
            s[i] = NULL; 
        }         
        while (n--)  //������ϣ��
        {
            cin >> key;
            HashInsert(key);
        }
        cin >> n;
        while (n--) //n�β�ѯ
        {
            cin >> key;
            Node* p = s[key % 11]; //�ҵ�key��Ӧ������s
            int num = 1;
            while (p) //��������б�����ѯ
            {
                if (p->data == key)
                    break;
                p = p->next;
                num++;//��ѯ���
            }
            if (p)
            {
                cout << key % 11 << " " << num << endl;  //���������Ϊ��βNULL�����������ϣ������λ�ú����
            }
            else    //�������error���������ϣ��
            {
                cout << "error" << endl;
                HashInsert(key);
            }
        }
    }
    return 0;
}
