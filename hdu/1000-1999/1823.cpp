////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-12-09 21:54:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1823
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:12000KB
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
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-9;
const int MAX=2e6+10;
const ll mod=1e9+7;
//ÄÚ²ãÊ÷ 
int root[MAX],tot,ls[MAX],rs[MAX],v[MAX];
void init()
{
	mem(root,0);
	ls[0]=rs[0]=0;
	v[0]=-1;
	tot=1;
}
int newnode()
{
	ls[tot]=rs[tot]=0;
	v[tot]=-1;
	return tot++;
}
void Insert(int l,int r,int &id,int pos,int val)
{
	int mid;
	if(!id) id=newnode();
	if(l==r&&pos==l)
	{
		v[id]=max(v[id],val);
		return;
	}
	mid=(l+r)>>1;
	if(pos<=mid) Insert(l,mid,ls[id],pos,val);
	else if(pos>=mid+1) Insert(mid+1,r,rs[id],pos,val);
	v[id]=max(v[ls[id]],v[rs[id]]);
}
int query2(int l,int r,int id,int x,int y)
{
	if(!id) return -1;
	if(l>=x&&r<=y) return v[id];
	int mid=(l+r)>>1;
	if(y<=mid) return query2(l,mid,ls[id],x,y);
	else if(x>=mid+1) return query2(mid+1,r,rs[id],x,y);
	else return max(query2(l,mid,ls[id],x,y),query2(mid+1,r,rs[id],x,y));
	v[id]=max(v[ls[id]],v[rs[id]]);
}
//
 
void update(int l,int r,int id,int pos,int h,int v)
{
	int mid;
	Insert(0,1000,root[id],h,v);
	if(l==r&&pos==l) return;
	mid=(l+r)>>1;
	if(pos<=mid) update(l,mid,id<<1,pos,h,v);
	else if(pos>=mid+1) update(mid+1,r,id<<1|1,pos,h,v);
}
int query1(int l,int r,int id,int x,int y,int h1,int h2)
{
	int mid;
	if(l>=x&&r<=y) return query2(0,1000,root[id],h1,h2);
	mid=(l+r)>>1;
	if(y<=mid) return query1(l,mid,id<<1,x,y,h1,h2);
	else if(x>=mid+1) return query1(mid+1,r,id<<1|1,x,y,h1,h2);
	else return max(query1(l,mid,id<<1,x,y,h1,h2),query1(mid+1,r,id<<1|1,x,y,h1,h2));
}
int main()
{
	int q,a,b;
	double c,d;
	char op[11];
	while(~scanf("%d",&q)&&q)
	{
		init();
		while(q--)
		{
			scanf("%s",op);
			if(op[0]=='I')
			{
				scanf("%d%lf%lf",&a,&c,&d);
				update(100,200,1,a,(int)(c*10+eps),(int)(d*10+eps));
			}
			else
			{
				scanf("%d%d%lf%lf",&a,&b,&c,&d);
				if(a>b) swap(a,b);
				if(c>d) swap(c,d);
				int ans=query1(100,200,1,a,b,(int)(c*10+eps),(int)(d*10+eps));
				if(ans<0) puts("-1");
				else printf("%.1lf\n",ans/10.0);
			}
		}
	}
	return 0;
}
/*
2
I 166 40.0 0
Q 166 177 10.0 50.0
*/