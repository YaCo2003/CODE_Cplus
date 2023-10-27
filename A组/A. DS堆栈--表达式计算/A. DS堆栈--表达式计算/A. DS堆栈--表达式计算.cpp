#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stack>
#include<string>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<stdio.h>
using namespace std;

#define ok 0
#define error -1
#define overflow -1
#define opsetsize 7//运算符集合长度，目前只有7个运算符
typedef int Status;

char Prior[7][7] = {//运算符间的优先关系
    '>','>','<','<','<','>','>',
    '>','>','<','<','<','>','>',
    '>','>','>','>','<','>','>',
    '>','>','>','>','<','>','>',
    '<','<','<','<','<','=',' ',
    '>','>','>','>',' ','>','>',
    '<','<','<','<','<',' ',' '
};

float Operate(float a, unsigned char theta, float b) {
    double dou;
    if (theta == '+') {
        return a + b;
    }
    else if (theta == '-') {
        return a - b;
    }
    else if (theta == '*') {
        return a * b;
    }
    else if (theta == '/') {
        return a / b;
    }
}
char opset[opsetsize] = { '+', '-', '*', '/', '(', ')','#' };//运算符集合
Status in(char Test, char* Testop) {//判断字符Test是否是运算符
    for (int j = 0; j < opsetsize; j++) {
        if (Test == Testop[j])
            return 1;
    }
    return 0;
}
char precede(char Aop, char Bop) {//获取两个运算符之间的优先级
    int i;
    for (i = 0; i < opsetsize; i++)
        if (opset[i] == Aop)
            break;
    int j;
    for (j = 0; j < opsetsize; j++)
        if (opset[j] == Bop)
            break;
    return Prior[i][j];
}

float EvaluateExpression(string Myexp) {
    stack<char> Optr;//运算符栈
    stack<double> Opnd;//操作数栈
    char Tempdata[20];
    double data, a, b, r;
    char theta, dr[2];
    char c;
    int i = 0;//用于控制字符串的位置移动

    Optr.push('#');
    c = Myexp[0];

    strcpy(Tempdata, "\0");
    while (c != '#' || Optr.top() != '#') {
        if (!in(c, opset)) {//判断读入的字符是不是运算符，不是则进入
            dr[0] = c;
            dr[1] = '\0';
            strcat(Tempdata, dr);
            c = Myexp[++i];//读取下一个字符
            if (in(c, opset)) {//如果c是运算符，表明前面读入了一个完整的操作数
                data = (float)atof(Tempdata);
                Opnd.push(data);
                strcpy(Tempdata, "\0");
            }
        }
        else {//是运算符，开始计算
            switch (precede(Optr.top(), c)) {
            case '<'://。。栈顶的优先级低
                Optr.push(c);
                c = Myexp[++i];
                break;
            case '='://脱括号
                Optr.pop();
                c = Myexp[++i];
                break;
            case '>'://退栈并将计算结果入栈
                double b = Opnd.top();
                Opnd.pop();
                double a = Opnd.top();
                Opnd.pop();
                theta = Optr.top();
                Optr.pop();
                Opnd.push(Operate(a, theta, b));
                break;
            }
        }
    }
    return Opnd.top();
}
int main() {

    string exp;
    int t;
    double result;
    cin >> t;
    while (t--) {
        cin >> exp;
        result = EvaluateExpression(exp);

        cout << fixed << setprecision(4) << result << endl;
    }
    return 0;
}

