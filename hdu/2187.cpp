////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-09 16:54:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2187
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1700KB
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
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-9;
const int MAX=100000+10;
const ll mod=10000;
struct node
{
	int v,w;
	friend bool operator<(node a,node b)
	{
		return a.v<b.v;
	}
}a[1111];
int main()
{
	int t,n,m,i;
	double ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a[i].v,&a[i].w);
		}
		sort(a,a+m);
		ans=0;
		for(i=0;i<m&&n;i++)
		{
			
			if(n>=a[i].v*a[i].w)
			{
				ans+=a[i].w;
				n-=a[i].v*a[i].w;
			}
			else
			{
				ans+=n*1.0/a[i].v;
				n=0;
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}