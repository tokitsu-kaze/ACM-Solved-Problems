#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Difference_Constraints
{
	#define type ll
	static const type inf=LLINF;
	static const int N=4005;
	vector<pair<int,type> > mp[N];
	type dis[N];
	int n,s,vis[N],cnt[N];
	void init(int _n)
	{
		s=_n+1;
		n=s;
		for(int i=0;i<=n;i++) mp[i].clear();
		
	}
	void add_edge(int x,int y,type v){mp[x].push_back({y,v});}
	bool work()
	{
		int i,x,to;
		type w;
		queue<int> q;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=cnt[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			if(i==s) continue;
			add_edge(s,i,0);
		}
		vis[s]=1;
		dis[s]=0;
		q.push(s);
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			vis[x]=0;
			for(auto &it:mp[x])
			{
				to=it.first;
				w=it.second;
				if(dis[to]>dis[x]+w)
				{
					dis[to]=dis[x]+w;
					cnt[to]=cnt[x]+1;
					if(cnt[to]>n) return false;
					if(!vis[to])
					{
						q.push(to);
						vis[to]=1;
					}
				}
			}
		}
		return true;
	}
	#undef type
}dfct;
/*
O(n*m)
dfct.init(n);  x[1],x[2],...,x[n]
dfct.add_edge(a,b,val); -> x[a]+val>=x[b]
dfct.work();
*/
ll res[MAX];
int main()
{
	int n,m,i,l,r,s;
	ll ans;
	scanf("%d%d",&n,&m);
	n++;
	dfct.init(n);
	while(m--)
	{
		scanf("%d%d%d",&l,&r,&s);
		l++;
		r++;
		dfct.add_edge(l-1,r,s);
		dfct.add_edge(r,l-1,-s);
	}
	for(i=2;i<=n;i++) dfct.add_edge(i,i-1,-1);
	if(!dfct.work()) return 0*puts("-1");
	for(i=1;i<=n;i++) res[i]=-(dfct.dis[i]-dfct.dis[i+1]);
/*	for(i=1;i<=n;i++) cout<<res[i]<<" ";
	puts("");*/
	ans=0;
	for(i=1;i<=n;i++) ans+=res[i];
	printf("%lld\n",ans);
	return 0;
}
