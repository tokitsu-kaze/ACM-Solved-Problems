////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-13 18:58:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1074
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:2088KB
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
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=10000;
struct node1
{
	int v,pre,d;
}dp[1L<<17];
struct node2
{
	char name[111];
	int v,d;
}a[22];
int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		mem(a,0);
		dp[0].v=0;
		dp[0].d=0;
		for(i=1;i<=(1L<<n);i++)
		{
			dp[i].v=INF;
			dp[i].pre=0;
			dp[i].d=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%s %d %d",a[i].name,&a[i].d,&a[i].v);
		}
		for(i=0;i<(1L<<n)-1;i++)
		{
			for(j=1;j<=n;j++)
			{
				int jj=1L<<(j-1);
				if((i&jj)==0)
				{
					int temp;
					if(dp[i].d+a[j].v<=a[j].d) temp=0;
					else if(dp[i].d+a[j].v>a[j].d) temp=dp[i].d+a[j].v-a[j].d;
					if(dp[i+jj].v>dp[i].v+temp)
					{
						dp[i+jj].v=dp[i].v+temp;
						dp[i+jj].d=dp[i].d+a[j].v;
						dp[i+jj].pre=j;
					}
				}
			}
		}
		printf("%d\n",dp[(1L<<n)-1].v);
		int s=(1L<<n)-1;
		int temp=dp[s].pre;
		stack<string> sk;
		while(temp)
		{
			sk.push(a[temp].name);
			s-=(1L<<(temp-1));
			temp=dp[s].pre;
		}
		while(!sk.empty())
		{
			cout<<(sk.top())<<endl;
			sk.pop();
		}
	}
	return 0;
}