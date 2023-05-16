////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-13 19:14:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1269
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:4084KB
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
const int MAX=10000+10;
const int EDGE=100000+10;//边的条数
typedef long long ll;
int n,cnt,top,k;
vector<int> mp[MAX];
int low[MAX],dfn[MAX],belong[MAX];
int sstack[MAX],flag[MAX];
void init()
{
	int i;
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
	}
	mem(low,0);
	mem(dfn,0);
	mem(sstack,0);
	mem(flag,0);
	cnt=top=k=0;
}
void tarjan(int now)
{
	int to,i,temp;
	sstack[top++]=now;
	flag[now]=1;//标记进栈
	low[now]=dfn[now]=++k;
	for(i=0;i<mp[now].size();i++)
	{
		to=mp[now][i];
		if(!dfn[to])
		{
			tarjan(to);
			low[now]=min(low[now],low[to]);
		}
		else if(flag[to]) low[now]=min(low[now],dfn[to]);
	}
	if(low[now]==dfn[now])
	{
		cnt++;
		do
		{
			temp=sstack[top--];
			flag[temp]=0;
			belong[temp]=cnt;
		}while(temp!=now);
	}
}
int main()
{
	int a,b,m,i;
	while(~scanf("%d%d",&n,&m)&&(n+m))
	{
		init();
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
		}
		for(i=1;i<=n;i++)
		{
			if(!dfn[i]) tarjan(i);
		}
		if(cnt==1) puts("Yes");
		else puts("No");
	}
	return 0;
} 