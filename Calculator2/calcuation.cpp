#include"calcuation.h"
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<cctype>
#include<sstream>
using namespace std;
int priority(string s)
{
	if(s=="+" || s=="-")
	{
		return 0;
	}
	if(s=="*" || s=="/")
	{
		return 1;
	}

}

int calculate(int a,int b,char s)
{

	if(s=='+')
	{
		return a+b;
	}
	if(s=='-')
	{
		return b-a;
	}
	if(s=='*')
	{
		return b*a;
	}
	if(s=='/' && a!=0)
	{
		return b/a;
	}
	else
		return 0;
}


int Calculation::out(queue<string> que)
{
	stack<string> digital;
	stack<string> cache;
	stack<string> character;
	stack<int> answer;
	string t;

	while(!que.empty())
	{
		cache.push(que.front());
		que.pop();
	}

	while(!cache.empty())
	{
		t = cache.top();
		cache.pop();
		if (t == "+"||t == "-"||t == "*"||t == "/")
		{
			if (character.empty() )
			{
				character.push(t);
			}
			else if (character.top() == ")")
			{
				character.push(t);
			}
			else if (priority(t) >= priority(character.top()))
			{
				character.push(t);
			}
			else
			{
				digital.push(character.top());
				character.pop();
				continue;
			}
		}
		else if (t == ")")
		{
			character.push(t);
		}
		else if (t == "(")
		{
			if (character.top() == ")")
			{
				character.pop();
				break;
			}
			else
			{
				digital.push(character.top());
				character.pop();
			}
		}
		else
		{
			digital.push(t);
		}

	}
	while (!character.empty())
	{
		digital.push(character.top());
		character.pop();
	}
	string ss[101];
	int i,j;
	for (i=0; !digital.empty(); i++)
	{
		ss[i]=digital.top();
		digital.pop();
		j=i;
	}
    for (i=j; i>=0; i--)
	{
		if (!isdigit(ss[i][0]))
		{
			int a,b,an;
			a=answer.top();
			answer.pop();
			b=answer.top();
			answer.pop();
			an=calculate(a,b,ss[i][0]);
			answer.push(an);
		}
		else
		{
			int f;
			stringstream stream(ss[i]);
			stream >> f;
			answer.push(f);
		}
	}
	return answer.top();
}






