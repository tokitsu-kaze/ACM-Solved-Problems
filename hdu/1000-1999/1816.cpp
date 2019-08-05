////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-05 10:16:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1816
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:2124KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
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
const int MAX=4e3+10;
const ll mod=1e9+7;
int n,scc,top,tot;
vector<int> mp[MAX];
int low[MAX],dfn[MAX],belong[MAX];
int stk[MAX],flag[MAX];
void init(int n)
{
	int i;
	for(i=0;i<2*n;i++)
	{
		mp[i].clear();
		low[i]=0;
		dfn[i]=0;
		stk[i]=0;
		flag[i]=0;
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
void add(int x,int vx,int y,int vy)
{
	x=x*2+vx;
	y=y*2+vy;
	mp[x].pb(y);
}
int a[MAX],b[MAX],c[MAX],d[MAX];
bool twosat(int n,int m)
{
	if(m==0) return 1;
	int i;
	init(n);
	for(i=0;i<n/2;i++)
	{
		add(a[i],1,b[i],0);
		add(b[i],1,a[i],0);
	}
	for(i=1;i<=m;i++)
	{
		add(c[i],0,d[i],1);
		add(d[i],0,c[i],1);
	}
	for(i=0;i<2*n;i++)
	{
		if(!dfn[i]) tarjan(i);
	}
	for(i=0;i<n;i++)
	{
		if(belong[2*i]==belong[2*i+1]) return 0;
	}
	return 1;
} 
int main()
{
	int n,m,i;
	while(~scanf("%d%d",&n,&m)&&n+m)
	{
		n*=2;
		for(i=0;i<n/2;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&c[i],&d[i]);
		}
		int l,r,mid;
		l=0;
		r=m;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(twosat(n,mid+1)) l=mid+1;
			else r=mid;
		}
		if(twosat(n,l)) printf("%d\n",l);
		else puts("0");
	}
	return 0;
}