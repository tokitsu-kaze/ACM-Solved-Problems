#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll g,tmp;
	g=exgcd(b,a%b,x,y);
	tmp=x;
	x=y;
	y=tmp-a/b*y;
	return g;
}
/*
xa+yb=gcd(a,b)

get x,y
x1=x+b/gcd(a,b)*t
y1=y-a/gcd(a,b)*t
t is any integer
*/
ll linear_equation(ll a,ll b,ll c,ll &x,ll &y)
{
	
	ll g,dx,dy,t;
	g=exgcd(a,b,x,y);
	
	if(a==0&&b==0)
	{
		if(c) return -1;
		x=y=0;
		return g;
	}
	if(c%g) return -1; //no solution
	dx=b/g,dy=-a/g;
	x*=c/g,y*=c/g;
	t=(x%dx-x)/dx;
	if(x+dx*t<0) t++;
	x+=dx*t,y+=dy*t;
	return g;
}
ll l[MAX],s[MAX],h;
struct Dijkstra
{
	#define type ll
	const type inf=LLINF;
	struct node
	{
		int id;
		type v;
		friend bool operator <(node a,node b){return a.v>b.v;}
	};
	static const int N=MAX;
	vector<node> mp[N];
	type dis[N];
	int n,vis[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){mp[x].push_back({y,v});}
	void work(int st)
	{
		int i,to;
		type w,tmp,a,b,c;
		priority_queue<node> q;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=0;
		}
		dis[st]=0;
		q.push({st,type(0)});
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(vis[t.id]) continue;
			vis[t.id]=1;// this node has already been extended
			for(auto &it:mp[t.id])
			{
				to=it.id;
				//x*(s1-s2) + h*y=l2-l1
				a=(s[t.id]-s[to]+h)%h;
				b=h;
				c=((l[to]-l[t.id]-(s[t.id]-s[to])*(dis[t.id]%h))%h+h)%h;
	//			printf("%lld %lld %lld\n",a,b,c);
				if(linear_equation(a,b,c,w,tmp)==-1) continue;
	//			printf("%d %d %lld\n",t.id,to,w);
				if(dis[to]>dis[t.id]+w+1)
				{
					dis[to]=dis[t.id]+w+1;
					if(!vis[to]) q.push({to,dis[to]}); 
				}
			}
		}
	}
	#undef type
}dij;
int main()
{
	int t,n,m,i,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%lld",&n,&m,&h);
		for(i=1;i<=n;i++) scanf("%lld",&l[i]);
		for(i=1;i<=n;i++) scanf("%lld",&s[i]);
		dij.init(n);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			dij.add_edge(a,b,0);
			dij.add_edge(b,a,0);
		}
		dij.work(1);
		if(dij.dis[n]==dij.inf) puts("-1");
		else printf("%lld\n",dij.dis[n]);
	}
	return 0;
}
/*
l1+x*s1=l2+x*s2
x*(s1-s2)=l2-l1 mod h
x*(s1-s2) + h*y=l2-l1
*/
