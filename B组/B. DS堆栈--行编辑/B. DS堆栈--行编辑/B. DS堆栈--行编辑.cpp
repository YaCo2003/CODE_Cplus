// B. DS堆栈--行编辑.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <stack>
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
		len = str.length();
		char p;
		stack<char>Q, T;//创建两个堆区

		for (int i = 0; i < len; i++)//先进后出
		{

			if (str[i] == '#')//若不为空，则退格，为空就跳过
			{
				if (!Q.empty())//栈为空就返回真
				{
					Q.pop();//后退
				}
			}
			else
			{
				Q.push(str[i]);//入栈
			}

		}
		//本题先建立一个Q栈，按顺序存储退格后的数据，但此时若要输出，只能从后往前输出
		//则反序了，所以再创建一个新的T栈，存储Q中的数据，在进行输出
		if (Q.empty())
		{
			cout << "NULL";
		}
		else
		{
			while (!Q.empty())
			{
				p = Q.top();
				Q.pop();
				T.push(p);
			}
			while (!T.empty())
			{
				p = T.top();
				T.pop();
				cout << p;
			}
		}
		cout << endl;
	}
	return 0;
}
