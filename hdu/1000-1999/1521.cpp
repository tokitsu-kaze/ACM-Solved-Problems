////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-06 17:05:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1521
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
int fact(int n)
{
	int ans=1,i;
	for(i=1;i<=n;i++)
	{
		ans*=i;
	}
	return ans;
}
int main()
{
    int n,m,i,j,k,a[11];
    double c1[11],c2[11];
	while(cin>>n>>m)
	{
		mem(c1,0);
		mem(c2,0);
		mem(a,0);
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<=a[0];i++)
		{
			c1[i]=1.0/fact(i);
		}
		for(i=1;i<n;i++)
		{
			for(j=0;j<=m;j++)
			{
				for(k=0;k+j<=m&&k<=a[i];k++)
				{
					c2[k+j]+=c1[j]/fact(k);
				}
			}
			for(j=0;j<=m;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		printf("%.0lf\n",c1[m]*fact(m));
	} 
    return 0;
}
