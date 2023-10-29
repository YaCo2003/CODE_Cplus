// A. DS排序--希尔排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

//希尔排序
int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		int n = 0;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		//预排序
		//gap>1 希尔排序
		//gap==1  插入排序
		int gap = n;
		while (gap > 1)
		{
			gap = gap / 2 ;
			for (int i = 0; i < n - gap; i++)
			{

				int end = i;
				int tmp = a[end + gap];
				while (end >= 0)
				{
					if (a[end] < tmp)
					{
						a[end + gap] = a[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				a[end + gap] = tmp;
			}
			for (int j = 0; j < n; j++)
			{
				if (j < n - 1)
				{
					cout << a[j] << " ";
				}
				else
				{
					cout << a[j] << endl;
				}
			}		
		}	
		cout << endl;
	}
}
