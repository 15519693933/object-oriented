#include "Scan.h"
#include "Print.h"
#include "calcuation.h"
#include<iostream>
#include<string>
#include<queue>
#include<stdlib.h>
using namespace std;



int main(int argc,char*argv[])   
{
	queue<string> que; 

	Scan sc;    
	Print put;  
	Calculation ca; 

	string input;
	cin>>input;
	if (input=="-a")
	{
		string inpu;
		cin>>inpu;
		que=sc.ToStringQueue(inpu);
		cout<<inpu<<""<<"="<<"";
		cout<<ca.out(que)<<endl;
	}
	else
	{
	    
	    cout<<ca.out(sc.ToStringQueue(input));
	}
	return 0;
}
