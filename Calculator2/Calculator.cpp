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
    int n = 0;//���ڱ��� 
    l = input.size();
    for (i=0; i<l; i++)
    {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' 
        || input[i] == '%' || input[i] == '(' || input[i] == ')')
        {   n = 0;//�����Ȳ���ʮλʱ�����¼��� 
            k=input[i];
            que.push(k);//���ַ���push������� 
            k.clear();
        }
        else
        {
            k = k + input[i];//ֱ���üӷ����� 
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
        cout << "ERROR" << endl; //���õ��������push����������Ƿ񳬹�ʮλ 
    }
    if (!k.empty()) //�����������֣�����������push�������� 
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
        cout << que.front() << endl;//��ӡ��ǰ����ַ������� 
        que.pop();//ɾ����һλ��ʹ�õڶ�λ��Ϊ��һλ������� 
    }
}
