#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+20;
const int mod=1e9+7;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(!dir && sz[x]>sz[y]) swap(x,y);
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		return 1;
	}
}dsu;
struct node{int v,id;};
int a[MAX],l[MAX],r[MAX],id[MAX];
int main()
{
	int T,n,i,p,cnt;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&p);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		vector<node> now,tmp;
		for(i=1;i<=n;i++)
		{
			for(auto &it:now) it.v=__gcd(it.v,a[i]);
			now.push_back({a[i],i});
			sort(now.begin(),now.end(),[](node x,node y){
				if(x.v==y.v) return x.id<y.id;
				return x.v<y.v;
			});
			tmp.clear();
			for(auto &it:now)
			{
				if(tmp.empty() || tmp.back().v!=it.v) tmp.push_back(it);
			}
			now=tmp;
			for(auto &it:now)
			{
				if(it.v==a[i]) l[i]=it.id;
			}
		}
		for(i=n;i;i--)
		{
			for(auto &it:now) it.v=__gcd(it.v,a[i]);
			now.push_back({a[i],i});
			sort(now.begin(),now.end(),[](node x,node y){
				if(x.v==y.v) return x.id>y.id;
				return x.v<y.v;
			});
			tmp.clear();
			for(auto &it:now)
			{
				if(tmp.empty() || tmp.back().v!=it.v) tmp.push_back(it);
			}
			now=tmp;
			for(auto &it:now)
			{
				if(it.v==a[i]) r[i]=it.id;
			}
		}
		set<int> s;
		for(i=1;i<=n;i++)
		{
			id[i]=i;
			s.insert(i);
		}
		sort(id+1,id+1+n,[&](int x,int y){
			return a[x]<a[y];
		});
		dsu.init(n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(a[id[i]]>=p) break;
			ans+=a[id[i]]*dsu.merge(l[id[i]],id[i]);
			ans+=a[id[i]]*dsu.merge(r[id[i]],id[i]);
			auto it=s.lower_bound(l[id[i]]);
			vector<int> del;
			for(;it!=s.end();it++)
			{
				if((*it)>r[id[i]]) break;
				del.push_back(*it);
				ans+=a[id[i]]*dsu.merge(*it,id[i]);
			}
			for(auto &it:del) s.erase(it);
		}
		cnt=0;
		for(i=1;i<=n;i++) cnt+=(dsu.find(i)==i);
		ans+=1LL*(cnt-1)*p;
		printf("%lld\n",ans);
	}
	return 0;
}
