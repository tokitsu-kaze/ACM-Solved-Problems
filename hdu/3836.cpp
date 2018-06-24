////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-15 09:48:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3836
////Problem Title: 
////Run result: Accept
////Run time:280MS
////Run memory:5928KB
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
const int MAX=20000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int scc,k,n;
int dfn[MAX],low[MAX],flag[MAX],belong[MAX];
stack<int> s;
vector<int> mp[MAX];
void init()
{
	for(int i=1;i<=n;i++)
	{
		mp[i].clear();
	}
	mem(dfn,0);
	mem(low,0);
	mem(flag,0);
	mem(belong,0);
	scc=k=0;
}
void tarjan(int v)
{
	int t,i;
	s.push(v);
	flag[v]=1;
	dfn[v]=low[v]=++k;
	for(i=0;i<mp[v].size();i++)
	{
		t=mp[v][i];
		if(!dfn[t])
		{
			tarjan(t);
			low[v]=min(low[v],low[t]);
		}
		else if(flag[t]) low[v]=min(low[v],dfn[t]);
	}
	if(dfn[v]==low[v])
	{
		scc++;
		do
		{
			t=s.top();
			s.pop();
			belong[t]=scc;
			flag[t]=0;
		}while(t!=v);
	}
}
int main()
{
	int m,a,b,i,j,in[MAX],out[MAX],temp,cntin,cntout;
	while(~scanf("%d%d",&n,&m))
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
	//	cout<<scc<<endl;
		if(scc==1)
		{
			puts("0");
			continue;
		}
		mem(in,0);
		mem(out,0);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<mp[i].size();j++)
			{
				temp=mp[i][j];
				if(belong[temp]!=belong[i])
				{
					out[belong[i]]++;
					in[belong[temp]]++;
				}
			}
		}
		cntin=cntout=0;
		for(i=1;i<=scc;i++)
		{
			if(!in[i]) cntin++;
			if(!out[i]) cntout++;
		}
		printf("%d\n",max(cntin,cntout));
	}
	return 0;
}