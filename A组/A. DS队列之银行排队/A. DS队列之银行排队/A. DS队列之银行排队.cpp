#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int timeA = 0, timeB = 0, timeC = 0;;
    int cntA = 0, cntB = 0, cntC = 0;
    queue<char>que1;
    queue<int>que2;
    int t = 0;
    cin >> t;
    char type;
    for (int i = 0; i < t; i++)
    {
        cin >> type;
        que1.push(type);
    }
    int tim;
    for (int i = 0; i < t; i++)
    {
        cin >> tim;
        que2.push(tim);
    }
    char temp1;
    int temp2;
    for (int i = 0; i < t; i++)
    {
        temp1 = que1.front();
        temp2 = que2.front();
        if (temp1 == 'A')
        {
            timeA += temp2;
            cntA++;
        }
        else if (temp1 == 'B')
        {
            timeB += temp2;
            cntB++;
        }
        else
        {
            timeC += temp2;
            cntC++;
        }
        que1.pop();
        que2.pop();
    }
    cout << (timeA / cntA) << endl;
    cout << (timeB / cntB) << endl;
    cout << (timeC / cntC) << endl;

}