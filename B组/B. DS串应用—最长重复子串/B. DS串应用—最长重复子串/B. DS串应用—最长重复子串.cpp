// B. DS串应用—最长重复子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;
int test()
{
    string s, t1, t2;
    cin >> s;
    for (int len = s.size() / 2; len > 0; len--)
    {
        for (int i = 0; i < s.size() - len; i++)
        {
            t1 = s.substr(i, len);
            t2 = s.substr(len + i);
            if (t2.find(t1) != string::npos)//可在t2中找到t1出现的位置
            {
                return len;
            }          
        }
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cout << test() << endl;
    }
    return 0;
}
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int test()
//{
//    string s, t1, t2;
//    cin >> s;
//    for (int len = s.size() / 2; len > 0; len--)
//    {
//        for (int i = 0; i < s.size() - len; i++)
//        {
//            t1 = s.substr(i, len);
//            t2 = s.substr(len + i);
//            if (t2.find(t1) != string::npos)
//                return len;
//        }
//    }
//    return -1;
//}
//int main()
//{
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        cout << test() << endl;
//    }
//    return 0;
//}
