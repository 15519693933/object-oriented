#include<stdio.h>
#include<string.h>
int main()
{
int a,b,q,i,j=0,sum=0;
char temp[10000];
scanf("%d %d",&a,&b);
sum=a+b;
sprintf(temp,"%d",sum);
q=strlen(temp);
for (i=0;i<q;i++)
if (temp[0]=='-')
{
	printf("%c",temp[0]);
    for (i=1;i<q;i++)
    if ((i+1-q%3)%3==0)
    {
    	if(i!=q-1)
	    {
		printf("%c",temp[i]);
    	printf(",");
        }
        else
        {
        	printf("%c",temp[i]);
		}
    }
	else 
	{
		printf("%c",temp[i]);
	}
}
else
{
	for (i=0;i<q;i++)
	if ((i+1-q%3)%3==0)
	{
		if(i!=q-1)
		{
			printf("%c",temp[i]);
			printf(",");
		}
		else
		{
			printf("%c",temp[i]);
		}
	}
	else
	{
		printf("%c",temp[i]);
	}
}
	
	
return 0;
}
