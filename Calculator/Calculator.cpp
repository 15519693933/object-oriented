#include"Scan.h"
#include"Print.h"
#include<iostream>
#include<string>
#include<queue>
using namespace std;
queue<string> Scan::ToStringQueue(string input)
{
    queue<string>que;
    string k;
    int i,l;
    int n = 0;//用于报错 
    l = input.size();
    for (i=0; i<l; i++)
    {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' 
        || input[i] == '%' || input[i] == '(' || input[i] == ')')
        {   n = 0;//当长度不足十位时，重新计数 
            k=input[i];
            que.push(k);//将字符串push入队列中 
            k.clear();
        }
        else
        {
            k = k + input[i];//直接用加法连接 
            if (input[i+1] == '+' || input[i+1] == '-' || input[i+1] == '*' || input[i+1] == '/' 
        || input[i+1] == '%' || input[i+1] == '(' || input[i+1] == ')')
            {
            	que.push(k);
            	k.clear();
                n++;       //
            }
            if (n == 10) 
            {
                break;
            }
        }
    }
    if(n == 10) 
    {
        cout << "ERROR" << endl; //将得到后的数字push入队列评判是否超过十位 
    }
    if (!k.empty()) //如果最后是数字，将最后的数字push到队列中 
    {
        que.push(k);
        k.clear();
    }
    return que;
}

void Print::PrintQueue(queue<string> que)
{
    while (!que.empty())
    {
        cout << que.front() << endl;//打印最前面的字符或数字 
        que.pop();//删除第一位，使得第二位成为第一位可以输出 
    }
}
