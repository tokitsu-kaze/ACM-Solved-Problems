////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-02 11:54:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5818
////Problem Title: 
////Run result: Accept
////Run time:1154MS
////Run memory:3608KB
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
const int MAX=1e5+10;
const ll mod=1e9+7;
int tot,v[MAX],ls[MAX],rs[MAX],d[MAX],fa[MAX],val[MAX];
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
void init()
{
	mem(ls,0);
	mem(rs,0);
	mem(d,0);
	tot=1;
}
int pos[333];
int main()
{
	int n,cas=1,root[2],x,now;
	char op[11],a[11],b[11];
	pos['A']=0;
	pos['B']=1;
	while(~scanf("%d",&n)&&n)
	{
		init();
		now=1;
		mem(root,0);
		printf("Case #%d:\n",cas++);
		while(n--)
		{
			scanf("%s%s",op,a);
			if(op[2]=='s')
			{
				scanf("%d",&x);
				val[now]=x;
				root[pos[a[0]]]=merge(root[pos[a[0]]],newnode(now));
				now++;
			}
			else if(op[2]=='p')
			{
				printf("%d\n",val[root[pos[a[0]]]]);
				root[pos[a[0]]]=pop(root[pos[a[0]]]);
			}
			else if(op[2]=='r')
			{
				scanf("%s",b);
				root[pos[a[0]]]=merge(root[pos[a[0]]],root[pos[b[0]]]);
				root[pos[b[0]]]=0;
			}
		}
	}
	return 0;
}
