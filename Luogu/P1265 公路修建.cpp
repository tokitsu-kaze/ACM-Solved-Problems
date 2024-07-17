#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e3+10;
int x[MAX],y[MAX];
double sqr(double a){return a*a;}
double get_dis(int i,int j)
{
	return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}
struct Prim
{
	#define type double
	const type inf=INF;
	static const int N=MAX;
	type dis[N];
	int n,vis[N];
	void init(int _n)
	{
		n=_n;
	}
	type work()
	{
		int i,x,cnt;
		type res,mn;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=0;
		}
		x=1;
		for(i=1;i<=n;i++) dis[i]=min(dis[i],get_dis(x,i));
		res=0;
		cnt=0;
		while(1)
		{
			mn=inf;
			vis[x]=1;
			cnt++;
			for(i=1;i<=n;i++)
			{
				if(!vis[i]&&dis[i]<mn)
				{
					mn=dis[i];
					x=i;
				}
			}
			if(mn==inf) break;
			res+=mn;
			for(i=1;i<=n;i++) dis[i]=min(dis[i],get_dis(x,i));
		}
		if(cnt<n) return inf; // no connect
		return res;
	}
	#undef type
}prim;
/*
O(n^2+m)

prim.init(n);
prim.add_edge(x,y,w);  x<->y
prim.work();
*/
int main()
{
	int k,n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	prim.init(n);
	printf("%.2f\n",prim.work());
	return 0;
}

