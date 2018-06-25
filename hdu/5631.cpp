////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-13 19:33:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5631
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:1564KB
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
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=100+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int pre[MAX],a[MAX],b[MAX];
int find(int x)
{
	if(pre[x]!=x) pre[x]=find(pre[x]);
	return pre[x];
}
void merge(int a,int b)
{
	int ta,tb;
	ta=find(a);
	tb=find(b);
	if(ta!=tb) pre[ta]=tb; 
}
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		pre[i]=i;
	}
}
int main()
{
	int t,n,i,j,k,ans,cnt;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			mem(a,0);
			mem(b,0);
			for(i=0;i<=n;i++)
			{
				scanf("%d%d",&a[i],&b[i]);
			}
			ans=0;
			for(i=0;i<=n;i++)
			{
				for(j=i;j<=n;j++)
				{
					init(n);
					for(k=0;k<=n;k++)
					{
						if(k!=i&&k!=j)
						{
							merge(a[k],b[k]);
						}
					}
					cnt=0;
					for(k=1;k<=n;k++)
					{
						if(pre[k]==k) cnt++;
					}
					if(cnt==1) ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
}