////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-03 12:08:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4421
////Problem Title: 
////Run result: Accept
////Run time:780MS
////Run memory:6120KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e3+10;
const ll mod=1e9+7;
int scc,top,idx;
vector<int> mp[MAX];
int low[MAX],dfn[MAX],belong[MAX];
int stk[MAX],vis[MAX];
void init(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		mp[i].clear();
		low[i]=0;
		dfn[i]=0;
		stk[i]=0;
		vis[i]=0;
		belong[i]=0;
	}
	scc=top=idx=0;
}
void tarjan(int x)
{
	int to,i,temp;
	stk[top++]=x;
	vis[x]=1;
	low[x]=dfn[x]=++idx;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(!dfn[to])
		{
			tarjan(to);
			low[x]=min(low[x],low[to]);
		}
		else if(vis[to]) low[x]=min(low[x],dfn[to]);
	}
	if(low[x]==dfn[x])
	{
		scc++;
		do
		{
			temp=stk[--top];
			vis[temp]=0;
			belong[temp]=scc;
		}while(temp!=x);
	}
}
void add(int x,int y)
{
	mp[x].pb(y);
}
int two_sat(int n)
{
	int i;
	for(i=0;i<2*n;i++)
	{
		if(!dfn[i]) tarjan(i);
	}
	for(i=0;i<n;i++)
	{
		if(belong[i]==belong[i+n]) return 1;
	}
	return 0;
}
int g[510][510];
int main()
{
	int i,j,k,flag,n;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&g[i][j]);
			}
		}
		if(n==1)
		{
			puts("YES");
			continue;
		}
		flag=0;
		for(i=0;i<n;i++)
		{
			if(g[i][i]) flag=1;
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(g[i][j]!=g[j][i]) flag=1;
			}
		}
		if(flag)
		{
			puts("NO");
			continue;
		}
		for(k=0;k<=30;k++)
		{
			init(2*n);
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					int tag=(g[i][j]>>k)&1;
					if(i%2&&j%2)
					{
						if(tag)
						{
							add(i+n,j);
							add(j+n,i);
						}
						else
						{
							add(i,i+n);
							add(j,j+n);
						}
					}
					else if(i%2==0&&j%2==0)
					{
						if(tag)
						{
							add(i+n,i);
							add(j+n,j);
						}
						else
						{
							add(j,i+n);
							add(i,j+n);
						}
					}
					else
					{
						if(tag)
						{
							add(i,j+n);
							add(j,i+n);
							add(i+n,j);
							add(j+n,i);
						}
						else
						{
							add(i,j);
							add(j,i);
							add(i+n,j+n);
							add(j+n,i+n);
						}
					}
				}
			}
			flag=two_sat(n);
			if(flag) break;
		}
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}