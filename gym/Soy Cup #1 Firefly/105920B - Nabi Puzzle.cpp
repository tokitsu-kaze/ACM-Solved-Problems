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
	static const int N=2e5+10;
	vector<pair<int,type> > mp[N];
	type dis[N];
	int n,in[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) 
		{
			mp[i].clear();
			in[i]=0;
		}
	}
	void add_edge(int x,int y,type v)
	{
		mp[x].push_back({y,v});
		in[y]++;
	}
	bool work()
	{
		int x,i,to,w;
		queue<int> q;
		for(i=1;i<=n;i++)
		{
			if(!in[i])
			{
				q.push(i);
				dis[i]=0;
			}
			else dis[i]=inf;
		}
		vector<int> toplist;
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			toplist.push_back(x);
			for(auto &it:mp[x])
			{
				to=it.first;
				w=it.second;
				in[to]--;
				if(!in[to]) q.push(to);
				dis[to]=min(dis[to],dis[x]+w);
			}
		}
		if(toplist.size()!=n) return false;
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
	int T,p,q,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&p,&q,&n);
		dfct.init(n+1);
		for(i=p;i<=n;i++) dfct.add_edge(i+1,i-p+1,-1);
		for(i=q;i<=n;i++) dfct.add_edge(i-q+1,i+1,-1);
		if(!dfct.work())
		{
			puts("NO");
			continue;
		}
		for(i=1;i<=n;i++) res[i]=-(dfct.dis[i]-dfct.dis[i+1]);
		puts("YES");
		for(i=1;i<=n;i++) printf("%lld%c",res[i]," \n"[i==n]);
	}
	return 0;
}
