#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int head[MAX],tot;
struct node
{
	int to,v,next;
}e[MAX<<1];
void init()
{
	mem(head,-1);
	tot=0;
}
void add(int x,int y,int v)
{  
	e[tot].v=v;  
	e[tot].to=y;
	e[tot].next=head[x];  
	head[x]=tot++;
}
namespace Tarjan
{
	int bcc,top,tot,n;
	vector<int> mp[MAX];
	int low[MAX],dfn[MAX],belong[MAX],fa[MAX];
	int stk[MAX];
	void dfs(int x,int pre)
	{
		int to,i,tmp,k,son;
		stk[top++]=x;
		low[x]=dfn[x]=++tot;
		fa[x]=pre;
		son=k=0;
		for(i=head[x];~i;i=e[i].next)
		{
			to=e[i].to;
			if(to==pre&&!k) 
            {
                k++;
                continue;
            }
			if(!dfn[to])
			{
				son++;
				dfs(to,x);
				low[x]=min(low[x],low[to]);
			}
			else low[x]=min(low[x],dfn[to]);
		}
		if(low[x]==dfn[x])
		{
			bcc++;
			do
			{
				tmp=stk[--top];
				belong[tmp]=bcc;
			}while(tmp!=x);
		}
	}
	void work(int _n,vector<int> e[])
	{
		n=_n;
		for(int i=1;i<=n;i++)
		{
			mp[i]=e[i];
			low[i]=dfn[i]=fa[i]=stk[i]=0;
		}
		bcc=top=tot=0;
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i]) dfs(i,i);
		}
	}
	void rebuild(vector<int> e[]) 
	{
		int i,t;
		for(i=1;i<=n;i++) e[i].clear();
	    for(i=1;i<=n;i++)
		{
	        t=fa[i];
	        if(belong[i]!=belong[t])
			{
	            e[belong[i]].pb(belong[t]);
	            e[belong[t]].pb(belong[i]);
	        }
	    }
	}
}
VI mp[MAX];
int fa[MAX],dep[MAX];
void dfs(int x,int pre)
{
	int i,to;
	fa[x]=pre;
	dep[x]=dep[pre]+1;
//	cout<<x<<" "<<pre<<endl;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==pre) continue;
		dfs(to,x);
	}
}
int flag[MAX];
int gao(int a,int b)
{
	int x,y,res=0;
	x=a;
	y=b;
	while(x!=y)
	{
		if(dep[x]>dep[y])
		{
			res+=flag[x];
			flag[x]=0;
			x=fa[x];
		}
		else
		{
			res+=flag[y];
			flag[y]=0;
			y=fa[y];
		}
	}
	return res;
}
int main()
{
	int n,m,i,a,b,q,cas=1,ans;
	while(~scanf("%d%d",&n,&m)&&n+m)
	{
		init();
		while(m--)
		{
			scanf("%d%d",&a,&b);
			add(a,b,0);
			add(b,a,0);
		}
		Tarjan::work(n,mp);
		Tarjan::rebuild(mp);
		dep[0]=0;
		dfs(1,0);
		for(i=2;i<=Tarjan::bcc;i++) flag[i]=1;
		scanf("%d",&q);
		printf("Case %d:\n",cas++);
		ans=Tarjan::bcc-1;
		while(q--)
		{
			scanf("%d%d",&a,&b);
			ans-=gao(Tarjan::belong[a],Tarjan::belong[b]);
			printf("%d\n",ans);
		}
		puts("");
	}
	return 0;
}