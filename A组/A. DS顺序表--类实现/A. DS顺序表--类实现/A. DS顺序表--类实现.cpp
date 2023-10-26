// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#define ok 0
#define error -1

//顺序表类定义
class SeqList
{
private:
    int* list;//元素数组
    int maxsize;//顺序表最大长度
    int size;//顺序表实际长度
public:
    SeqList()//构造函数
    {
        maxsize = 1000;
        size = 0;
        list = new int[maxsize];
    }

    ~SeqList()  //析构函数
    {
        delete[]list;
    }
    int list_size() //获取顺序表实际长度
    {
        return size;
    }
    int list_insert(int i, int item) //插入一个元素，参数是插入的数值和位置
    {
        if (i <= 0 || i > size + 1)
        {
            return error;
        }
        else
        {
            size++;

            for (int j = size - 1; j >= i - 1; j--)
            {
                list[j] = list[j - 1];
            }
            list[i - 1] = item;
            return ok;

        }

    }
    int list_del(int i) //删除一个元素，参数是删除的位置
    {
        if (i > size)
        {
            return error;
        }
        else
        {
            size--;
            for (int j = i - 1; j < size; j++)
            {
                list[j] = list[j + 1];
            }
            return ok;
        }
    }
    int list_get(int i) //获取一个元素，参数是获取的位置
    {
        if (i > size || i <= 0)
        {
            return error;
        }
        else
        {
            return list[i - 1];
        }
    }
    void list_display()
    {
        cout << size << " ";
        for (int i = 0; i < size; i++)
        {
            cout << list[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    int num;
    SeqList q;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        q.list_insert(i + 1, num);
    }
    q.list_display();
    int insert1, insert2, num1, num2;
    cin >> insert1 >> num1;
    if (q.list_insert(insert1, num1) == 0)
    {
        q.list_display();
    }
    else
    {
        cout << "error" << endl;
    }
    cin >> insert2 >> num2;
    if (q.list_insert(insert2, num2) == 0)
    {
        q.list_display();
    }
    else
    {
        cout << "error" << endl;
    }
    int del1, del2;
    cin >> del1;
    if (q.list_del(del1) == 0)
    {
        q.list_display();
    }
    else
    {
        cout << "error" << endl;
    }
    cin >> del2;
    if (q.list_del(del2) == 0)
    {
        q.list_display();
    }
    else
    {
        cout << "error" << endl;
    }
    int get1, get2;
    cin >> get1;
    if (q.list_get(get1) == -1)
    {
        cout << "error" << endl;
    }
    else
    {
        cout << q.list_get(get1) << endl;
    }
    cin >> get2;
    if (q.list_get(get2) == -1)
    {
        cout << "error" << endl;
    }
    else
    {
        cout << q.list_get(get2) << endl;
    }
}