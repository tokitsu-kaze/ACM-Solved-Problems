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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int v[MAX],l[MAX],r[MAX],a[MAX];
int bit[MAX],n;
int head[2*MAX],tot;
struct node
{
	int to,v,next;
}mp[2*MAX];
void init()
{
	mem(head,-1);
	tot=0;
}
void add(int x,int y,int v)
{  
	mp[tot].v=v;  
	mp[tot].to=y;
	mp[tot].next=head[x];  
	head[x]=tot++;
}  
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,int v)
{
	while(x<=n)
	{
		bit[x]+=v;
		x+=lowbit(x);
	}
}
int getsum(int x)
{
	int res=0;
	while(x)
	{
		res+=bit[x];
		x-=lowbit(x);
	}
	return res;
}
void dfs(int x,int pre)
{
	int i,to;
	tot++;
	l[x]=tot;
	a[tot]=v[x];
	for(i=head[x];~i;i=mp[i].next)
	{
		to=mp[i].to;
		if(to==pre) continue;
		dfs(to,x);
	}
	r[x]=tot;
}
int main()
{
	int i,q,x,c,d;
	char op[11];
	while(~scanf("%d",&n))
	{
		init();
		for(i=1;i<=n;i++) v[i]=1;
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&c,&d);
			add(c,d,0);
			add(d,c,0);
		}
		tot=0;
		dfs(1,0);
		mem(bit,0);
		for(i=1;i<=n;i++)
		{
			update(i,a[i]);
		}
		scanf("%d",&q);
		while(q--)
		{
			scanf("%s%d",op,&x);
			if(op[0]=='Q') printf("%d\n",getsum(r[x])-getsum(l[x]-1));
			else
			{
				if(a[l[x]]==0)
				{
					update(l[x],1);
					a[l[x]]=1;
				}
				else
				{
					update(l[x],-1);
					a[l[x]]=0;
				}
			}
		}
	}
	return 0;
}