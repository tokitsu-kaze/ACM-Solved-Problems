#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
struct Eulerian_Path
{
	static const int N=1e5+10;
	static const int M=2e5+10;
	struct edge{int to,id;};
	vector<edge> mp[N];
	int vis[M],n,m,in[N],out[N];
	bool dir;
	vector<int> re,rn;
	void init(int _n,bool _dir)
	{
		n=_n;
		dir=_dir;
		for(int i=1;i<=n;i++)
		{
			mp[i].clear();
			in[i]=out[i]=0;
		}
		m=0;
	}
	void add_edge(int x,int y,int id)
	{
		mp[x].push_back({y,id});
		in[y]++;
		out[x]++;
		if(!dir) mp[y].push_back({x,id});
		m++;
	}
	void dfs(int x)
	{
		while(mp[x].size())
		{
			auto it=mp[x].back();
			mp[x].pop_back();
			if(vis[it.id]) continue;
			vis[it.id]=1;
			dfs(it.to);
			re.push_back(it.id);
		}
		rn.push_back(x);
	}
	vector<int> work()
	{
		int i,cnt,be,en;
		if(dir)
		{
			be=en=-1;
			for(i=n;i;i--)
			{
				if(out[i]-in[i]==1)
				{
					if(be!=-1) return {};
					be=i;
				}
				else if(in[i]-out[i]==1)
				{
					if(en!=-1) return {};
					en=i;
				}
				else if(in[i]!=out[i]) return {};
			}
			if(be==-1)
			{
				assert(en==-1);
				be=1;
			}
		}
		else
		{
			cnt=0;
			for(i=n;i;i--)
			{
				if(mp[i].size()) be=i;
			}
			for(i=n;i;i--)
			{
				if(mp[i].size()&1)
				{
					cnt++;
					be=i;
				}
			}
			if(cnt>2) return {};
		}
		re.clear();
		rn.clear();
		for(i=0;i<=m;i++) vis[i]=0;
		for(i=1;i<=n;i++) sort(mp[i].begin(),mp[i].end(),[](edge x,edge y){
			return x.to>y.to;
		});
		dfs(be);
		if(re.size()!=m) return {};
		reverse(re.begin(),re.end());
		reverse(rn.begin(),rn.end());
		return rn;
	}
}ep;
/*
ep.init(n,bool dir);
ep.add_edge(a,b,id);
ep.work();
*/
int main()
{
	int m,i,a,b;
	scanf("%d",&m);
	ep.init(500,false);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		ep.add_edge(a,b,i);
	}
	auto res=ep.work();
	for(i=0;i<res.size();i++) printf("%d\n",res[i]);
	return 0;
}
