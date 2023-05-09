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
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e4+10;
const ll mod=1e9+7;
int n,scc,top,tot;
vector<int> mp[MAX];
int low[MAX],dfn[MAX],belong[MAX];
int stk[MAX],flag[MAX];
int pos[MAX],degree[MAX],ans[MAX],outflag[MAX],cnt;
vector<int> dag[MAX];
void init(int n)
{
	int i;
	for(i=0;i<2*n;i++)
	{
		mp[i].clear();
		dag[i].clear();
		low[i]=0;
		dfn[i]=0;
		stk[i]=0;
		flag[i]=0;
		degree[i]=0;
		outflag[i]=0;
	}
	scc=top=tot=0;
}
void tarjan(int x)
{
	int to,i,temp;
	stk[top++]=x;
	flag[x]=1;
	low[x]=dfn[x]=++tot;
	for(i=0;i<mp[x].size();i++)
	{
		to=mp[x][i];
		if(!dfn[to])
		{
			tarjan(to);
			low[x]=min(low[x],low[to]);
		}
		else if(flag[to]) low[x]=min(low[x],dfn[to]);
	}
	if(low[x]==dfn[x])
	{
		scc++;
		do
		{
			temp=stk[--top];
			flag[temp]=0;
			belong[temp]=scc;
		}while(temp!=x);
	}
}
void add(int x,int y)
{
	mp[x].pb(y);
}
void topsort(int n)
{
	int i,t;
	queue<int> q;
	cnt=0;
	for(i=1;i<=scc;i++)
	{
		if(degree[i]==0) q.push(i);
		outflag[i]=0;
	}
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(outflag[t]==0)
		{
			outflag[t]=1;
			outflag[pos[t]]=2;
		}
		for(i=0;i<sz(dag[t]);i++)
		{
			int to=dag[t][i];
			degree[to]--;
			if(degree[to]==0) q.push(to);
		}
	}
}
void builddag(int n)
{
	int i,j,to;
	for(i=0;i<2*n;i++)
	{
		for(j=0;j<sz(mp[i]);j++)
		{
			to=mp[i][j];
			if(belong[i]!=belong[to])
			{
				degree[belong[i]]++;
				dag[belong[to]].pb(belong[i]);
			}
		}
	}
}
void twosat(int n)
{
	int i;
	for(i=0;i<2*n;i++)
	{
		if(!dfn[i]) tarjan(i);
	}
	for(i=0;i<n;i++)
	{
		if(belong[2*i]==belong[2*i+1])
		{
			puts("bad luck"); 
			return;
		}
		pos[belong[2*i]]=belong[2*i+1];
		pos[belong[2*i+1]]=belong[2*i];
	}
	builddag(n);
	topsort(n);
	cnt=0;
	for(i=2;i<2*n;i+=2)
	{
		if(outflag[belong[i]]==outflag[belong[0]]) printf("%d%c ", i/2,'w');
		else printf("%d%c ", i/2,'h');
	}
	puts("");
}
int main()
{
	int n,m,i,a,b,x1,x2,y1,y2;
	char sa[11],sb[11];
	while(~scanf("%d%d",&n,&m)&&n+m)
	{
		init(n);
		while(m--)
		{
			scanf("%d%s %d%s",&a,sa,&b,sb);
			if(sa[0]=='h')
			{
				x1=2*a;
				x2=2*a+1;
			}
			else
			{
				x1=2*a+1;
				x2=2*a;
			}
			if(sb[0]=='h')
			{
				y1=2*b;
				y2=2*b+1;
			}
			else
			{
				y1=2*b+1;
				y2=2*b;
			}
			add(x2,y1);
			add(y2,x1);
		}
		add(0,1);
		twosat(n);
	}
	return 0;
}