////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-01 22:41:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1512
////Problem Title: 
////Run result: Accept
////Run time:795MS
////Run memory:3648KB
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
int tot,v[MAX],ls[MAX],rs[MAX],d[MAX],fa[MAX];
int merge(int x,int y)
{
	if(!x||!y) return x+y;
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
int main()  
{  
	int n,m,x,y,i,fx,fy;  
	while(~scanf("%d",&n))
	{  
		init();  
		for(i=1;i<=n;i++)
		{  
			scanf("%d",&v[i]);  
			fa[i]=i;  
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&x,&y);
			fx=find(x);
			fy=find(y);
			if(fx==fy)
			{
				puts("-1");
				continue;
			}
			v[fx]>>=1;
			v[fy]>>=1;
			fx=merge(pop(fx),fx);
			fy=merge(pop(fy),fy);
			printf("%d\n",v[merge(fx,fy)]);
		}
	}
	return 0;
}