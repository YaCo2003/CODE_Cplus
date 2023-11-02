// A. DS堆栈--逆序输出（不使用STL栈）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		string str;
		int len;
		cin >> str; //把输入的字符串保存在变量str;
		len = str.length();  //获取输入字符串的长度
		for (int i = len - 1; i >= 0; i--)
		{
			cout << str[i];
		}
		cout << endl;
	}
	return 0;
}
