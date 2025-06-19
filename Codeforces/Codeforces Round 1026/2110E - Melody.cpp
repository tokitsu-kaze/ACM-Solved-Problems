#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Discretization
{
	#define type ll
	#define all(x) x.begin(),x.end()
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.push_back(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return lower_bound(all(a),x)-a.begin()+1;}
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef all
}da,db;
struct Eulerian_Path
{
	static const int N=4e5+10;
	static const int M=4e5+10;
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
			be=1;
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
		dfs(be);
		if(re.size()!=m) return {};
		reverse(re.begin(),re.end());
		reverse(rn.begin(),rn.end());
		return re;
	}
}ep;
/*
ep.init(n,bool dir);
ep.add_edge(a,b,id);
ep.work();
*/
int a[MAX],b[MAX];
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		da.init();
		db.init();
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			da.add(a[i]);
			db.add(b[i]);
		}
		da.work();
		db.work();
		ep.init(da.size()+db.size(),false);
		for(i=1;i<=n;i++)
		{
			a[i]=da.get_pos(a[i]);
			b[i]=da.size()+db.get_pos(b[i]);
			ep.add_edge(a[i],b[i],i);
		}
		auto res=ep.work();
		if(res.size()==0)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
	}
	return 0;
}
