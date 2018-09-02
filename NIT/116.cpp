#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
	int len,j,n,i,t,a,c,m;
	char s[1001];
	while(~scanf("%s",s))
	{
		n=i=t=a=c=m=0;
		len=strlen(s);
		for(j=0;j<len;j++)
		{
			switch(s[j])
			{
				case 'N':n++;break;
				case 'I':i++;break;
				case 'T':t++;break;
				case 'A':a++;break;
				case 'C':c++;break;
				case 'M':m++;break;
			}
		}
		while(n+i+t+a+c+m!=0)
		{
			if(n!=0)
			{
				printf("N");
				n--;
			}
			if(i!=0)
			{
				printf("I");
				i--;
			}
			if(t!=0)
			{
				printf("T");
				t--;
			}
			if(a!=0)
			{
				printf("A");
				a--;
			}
			if(c!=0)
			{
				printf("C");
				c--;
			}
			if(m!=0)
			{
				printf("M");
				m--;
			}
		}
		cout<<endl;
	}
	return 0;
}