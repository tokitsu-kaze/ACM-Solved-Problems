////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-06 12:45:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2616
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:1740KB
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
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
struct node
{
	int a,m;
}a[15];
int n,flag[15],ans;
void dfs(int cnt,int hp)
{
	int i;
	if(hp<=0)
	{
		ans=min(ans,cnt);
		return;
	}
	for(i=0;i<n;i++)
	{
		if(!flag[i])
		{
			flag[i]=1;
			if(hp<=a[i].m) dfs(cnt+1,hp-2*a[i].a);
			else dfs(cnt+1,hp-a[i].a);
			flag[i]=0;
		}
	}
}
int main()
{
	int i,m;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].a,&a[i].m);
		}
		mem(flag,0);
		ans=INF;
		dfs(0,m);
		if(ans==INF) puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}
