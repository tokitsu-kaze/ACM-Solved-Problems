////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-06 21:42:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1262
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
using namespace std;
int main()
{
	int a,b,prime[10001],i,j,c=0;
	memset(prime,0,sizeof(prime));
	for(i=3;i<10000;i++)
	{
		if(i%2) prime[i]=1;
	}
	prime[2]=1;
	for(i=3;i<sqrt(10000);i++)
	{
		if(prime[i])
		{
			for(j=i+i;j<10000;j+=i)
			{
				prime[j]=0;
			}
		}
	}
	while(cin>>a)
	{
		b=a/2;
		for(i=b;i>5;i--)
		{
			if(prime[i]&&prime[a-i])
			{
				cout<<i<<" "<<a-i<<endl;
				break;
			}
		}
		c=0;
	}
	return 0;
}