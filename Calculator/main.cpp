#include"Scan.h"
#include"Print.h"
#include<iostream>
#include<string>
#include<queue>
using namespace std;
queue<string>que;
int main()
{
    string input;
    cin >> input;
    Scan Input;
    Print Output;
    que = Input.ToStringQueue(input);
    Output.PrintQueue(que);
    return 0;
}
