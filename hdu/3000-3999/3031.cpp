////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-02 11:18:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3031
////Problem Title: 
////Run result: Accept
////Run time:452MS
////Run memory:25180KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int tot,v[MAX],ls[MAX],rs[MAX],d[MAX],fa[MAX];
int merge(int x,int y)
{
	if(!x||!y)
	{
		fa[x+y]=x+y;
		return x+y;
	}
	if(v[x]<v[y]) swap(x,y);
	rs[x]=merge(rs[x],y);
	fa[rs[x]]=x;
	if(d[ls[x]]<d[rs[x]]) swap(ls[x],rs[x]);
	d[x]=d[rs[x]]+1;
	return x;  
}
int newnode(int x)
{
	v[tot]=x;
	fa[tot]=tot;
	ls[tot]=rs[tot]=d[tot]=0;
	return tot++;
}
int push(int x,int y)
{
	return merge(x,newnode(y));
}
int pop(int x)
{  
	fa[ls[x]]=ls[x];
	fa[rs[x]]=rs[x];
	int t=merge(ls[x],rs[x]);
	ls[x]=rs[x]=d[x]=0;
	fa[x]=x;
	return t;
}
int del(int x)
{  
	int fx,t;
	fx=fa[x];
	t=pop(x);
	if(fx!=x)
	{
		if(ls[fx]==x)
		{
			ls[fx]=t;
			fa[t]=fx;
		}
		if(rs[fx]==x)
		{
			rs[fx]=t;
			fa[t]=fx;
		}
	}
	x=fx;  
	while(x!=fa[x])
	{  
		if(d[ls[x]]<d[rs[x]]) swap(ls[x],rs[x]);  
		if(d[rs[x]]+1==d[x]) break;  
		d[x]=d[rs[x]]+1;
	}  
	return t;
}  
int find(int x)
{
	while(fa[x]!=x) x=fa[x];
	return x;
}
int root[MAX],cnt[MAX];
void init()
{
	mem(ls,0);
	mem(rs,0);
	mem(d,0);
	mem(root,0);
	tot=1;
}
int main()
{
	int r,n,m,i,j,x,a,b,now[2],win[2],heap[2];
	char op[11];
	while(~scanf("%d",&r))
	{
		mem(win,0);
		while(r--)
		{
			init();
			mem(now,0);
			mem(heap,0);
			scanf("%d%d",&n,&m);
			for(i=1;i<=m;i++) scanf("%d",&cnt[i]);
			for(i=1;i<=m;i++)
			{
				for(j=1;j<=cnt[i];j++)
				{
					scanf("%d",&x);
					root[i]=push(root[i],x);
				}
			}
			for(i=1;i<=n;i++)
			{
				scanf("%s",op);
				if(op[0]=='T')
				{
					scanf("%d",&x);
					heap[i&1]=merge(heap[i&1],root[x]);
					now[i&1]+=cnt[x];
					
				}
				else if(op[0]=='C')
				{
					a=v[heap[1]];
					b=v[heap[0]];
					if(a!=b)
					{
						heap[a>b]=merge(heap[1],heap[0]);
						now[a>b]+=now[a<b];
						now[a<b]=0;
					}
				}
				else if(op[0]=='L')
				{
					heap[i&1]=pop(heap[i&1]);
					now[i&1]--;
				}
				else if(op[0]=='A')
				{
					scanf("%d",&x);
					v[heap[i&1]]+=x;
				}
				else if(op[0]=='E') 
				{
					scanf("%d",&x);
					v[heap[i&1]]=x;
					a=heap[i&1];
					heap[i&1]=pop(heap[i&1]);
					heap[i&1]=merge(heap[i&1],a);
				}
			}
			printf("%d:%d\n",now[1],now[0]);
			win[now[1]>=now[0]]++;
		}
		win[1]>win[0]?puts("Hahaha...I win!!"):puts("I will be back!!");
	}
	return 0;
}
