////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-25 19:34:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2082
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1588KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
using namespace std;
int main()
{
	int c1[51],c2[51],a[27],n,i,j,k,sum;
	while(cin>>n)
	{
		while(n--)
		{
			for(i=1;i<=26;i++)
			{
				cin>>a[i];
			}
			memset(c1,0,sizeof(c1));
			memset(c2,0,sizeof(c2));
			for(i=0;i<=a[1];i++)
			{
				c1[i]=1;
			}
			for(i=2;i<=26;i++)
			{
				for(j=0;j<=50;j++)
				{
					for(k=0;k+j<=50&&k<=a[i]*i;k+=i)
					{
						c2[k+j]+=c1[j];
					}
				}
				for(j=0;j<=50;j++)
				{
					c1[j]=c2[j];
					c2[j]=0;
				}
			}
			sum=0;
			for(i=1;i<=50;i++)
			{
				sum+=c1[i];
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}