////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-14 18:44:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2767
////Problem Title: 
////Run result: Accept
////Run time:249MS
////Run memory:6432KB
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
int sstack[MAX],top,flag[MAX];
int belong[MAX],dfn[MAX],low[MAX];
int scc,k,n;
int in[MAX],out[MAX];
vector<int> mp[MAX];
void init()
{
	int i;
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
	}
	mem(sstack,0);
	mem(flag,0);
	mem(belong,0);
	mem(dfn,0);
	mem(low,0);
	mem(in,0);
	mem(out,0);
	scc=top=k=0;
}
void tarjan(int v)
{
	int temp,t,i;
	sstack[top++]=v;
	flag[v]=1;
	dfn[v]=low[v]=++k;
	for(i=0;i<mp[v].size();i++)
	{
		temp=mp[v][i];
		if(!dfn[temp])
		{
			tarjan(temp);
			low[v]=min(low[v],low[temp]);
		}
		else if(flag[temp]) low[v]=min(low[v],dfn[temp]);
	}
	if(dfn[v]==low[v])
	{
		scc++;
		do
		{
			temp=sstack[--top];
			flag[temp]=0;
			belong[temp]=scc;
		}while(temp!=v);
	}
}
int main()
{
	int t,m,i,j,a,b,temp,cntin,cntout;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d",&n,&m);
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
	//		cout<<scc<<endl;
			if(scc==1)
			{
				puts("0");
				continue;
			}
			for(i=1;i<=n;i++)
			{
				if(mp[i].size())
				{
					for(j=0;j<mp[i].size();j++)
					{
						temp=mp[i][j];
						if(belong[temp]!=belong[i])
						{
							in[belong[temp]]++;
							out[belong[i]]++;
						}
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
	}
	return 0;
}