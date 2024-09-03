#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Floyd
{
	#define type ll
	const type inf=LLINF;
	static const int N=405;
	int n;
	type mp[N][N],dis[N][N];
	void init(int _n)
	{
		int i,j;
		n=_n;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				mp[i][j]=dis[i][j]=inf;
			}
			mp[i][i]=dis[i][i]=0;
		}
	}
	void add_edge(int x,int y,type w)
	{
		w=min(mp[x][y],w);
		mp[x][y]=dis[x][y]=w;
	}
	void work()
	{
		int i,j,k;
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				if(dis[i][k]==inf) continue;
				for(j=1;j<=n;j++)
				{
					if(dis[k][j]==inf) continue;
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	#undef type
}flyd;
/*
flyd.init(n);
flyd.add_edge(x,y,w); x,y [1..n] x->y 
flyd.work();
*/
int a[MAX],b[MAX],c[MAX];
int main()
{
	int n,m,i,j,q,k,x;
	ll ans,now;
	scanf("%d%d",&n,&m);
	flyd.init(n);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		flyd.add_edge(a[i],b[i],c[i]);
		flyd.add_edge(b[i],a[i],c[i]);
	}
	flyd.work();
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&k);
		vector<int> id(k);
		for(auto &it:id) scanf("%d",&it);
		sort(id.begin(),id.end());
		ans=LLINF;
		do
		{
			for(i=0;i<(1<<k);i++)
			{
				now=0;
				x=1;
				for(j=0;j<k;j++)
				{
					if((i>>j)&1)
					{
						now+=flyd.dis[x][a[id[j]]];
						now+=c[id[j]];
						x=b[id[j]];
					}
					else
					{
						now+=flyd.dis[x][b[id[j]]];
						now+=c[id[j]];
						x=a[id[j]];
					}
				}
				now+=flyd.dis[x][n];
				ans=min(ans,now);
			}
		}
		while(next_permutation(id.begin(),id.end()));
		printf("%lld\n",ans);
	}
	return 0;
}
