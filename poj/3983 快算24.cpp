#include <iostream>
#include <cstdio>                    
#include <algorithm>
using namespace std;
char s[5]={'+','-','*','/'};
double cal(double a,int c,double b)
{
	switch(s[c])
	{
		case '+':return a+b;break;
		case '-':return a-b;break;
		case '*':return a*b;break;
		case '/':return a/b;break;
	}
}

/*
(a b) (c d)
((a b) c) d
(a (b c)) d
a ((b c) d)
a (b (c d))
*/
int istrue(int i,int j,int k,double a,double b,double c,double d)
{
	if(cal(cal(a,i,b),j,cal(c,k,d))-24==0)
	{
		cout<<"("<<a<<s[i]<<b<<")"<<s[j]<<"("<<c<<s[k]<<d<<")"<<endl;
		return 1;
	}
	else if(cal(cal(cal(a,i,b),j,c),k,d)-24==0)
	{
		cout<<"("<<"("<<a<<s[i]<<b<<")"<<s[j]<<c<<")"<<s[k]<<d<<endl;
		return 1;
	}
	else if(cal(a,i,cal(cal(b,j,c),k,d))-24==0)
	{
		cout<<a<<s[i]<<"("<<"("<<b<<s[j]<<c<<")"<<s[k]<<d<<")"<<endl;
		return 1;
	}
	else if(cal(a,i,cal(b,j,cal(c,k,d)))-24==0)
	{
		cout<<a<<s[i]<<"("<<b<<s[j]<<"("<<c<<s[k]<<d<<")"<<")"<<endl;
		return 1;
	}
	else return 0;
}

int main()
{
	int i,j,k,flag;
	double a,b,c,d;
	while(~scanf("%lf%lf%lf%lf",&a,&b,&c,&d))
	{
		flag=0;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				for(k=0;k<4;k++)
				{
					if(istrue(i,j,k,a,b,c,d))
					{
						flag=1;
						break;
					}
				}
				if(flag) break;
			}
			if(flag) break;
		}
	}
	return 0;
}