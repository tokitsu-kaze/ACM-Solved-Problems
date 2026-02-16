#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int l[MAX],r[MAX],idl[MAX],idr[MAX],tot,vis[MAX];
ll p[MAX],d[MAX];
vector<int> mp[MAX];
void dfs(int x)
{
	if(vis[x]) return;
	vis[x]=1;
	for(auto &to:mp[x]) dfs(to);
}
int main()
{
	int T,n,i,q,rt;
	ll k,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&k);
		for(i=1;i<=n;i++) scanf("%lld",&p[i]);
		for(i=1;i<=n;i++) scanf("%lld",&d[i]);
		tot=0;
		for(i=1;i<=n;i++)
		{
			l[i]=0;
			r[i]=n+1;
			idl[i]=++tot;
			idr[i]=++tot;
		}
		rt=++tot;
		idl[0]=idr[0]=idl[n+1]=idr[n+1]=rt;
		map<ll,int> lst;
		for(i=1;i<=n;i++)
		{
			x=(p[i]+d[i])%k;
			if(lst.count(x)) l[i]=lst[x];
			lst[x]=i;
		}
		lst.clear();
		for(i=n;i;i--)
		{
			x=((p[i]-d[i])%k+k)%k;
			if(lst.count(x)) r[i]=lst[x];
			lst[x]=i;
		}
		for(i=1;i<=tot;i++)
		{
			mp[i].clear();
			vis[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			mp[idr[l[i]]].push_back(idl[i]);
			mp[idl[r[i]]].push_back(idr[i]);
//			printf("%d %d %d\n",i,l[i],r[i]);
		}
		dfs(rt);
		map<ll,vector<pair<ll,int>>> ha;
		for(i=1;i<=n;i++)
		{
			x=((p[i]-d[i])%k+k)%k;
			ha[x].push_back({p[i],i});
		}
		for(auto &it:ha) sort(it.second.begin(),it.second.end());
		scanf("%d",&q);
		while(q--)
		{
			scanf("%lld",&x);
			if(!ha.count(x%k))
			{
				puts("YES");
				continue;
			}
			auto it=lower_bound(ha[x%k].begin(),
								ha[x%k].end(),
								make_pair(x,-1));
			if(it==ha[x%k].end()) puts("YES");
			else
			{
				if(vis[idl[(*it).second]]) puts("YES");
				else puts("NO");
			}
		}
	}
	return 0;
}
/*
考虑每个灯是红灯的时候。 
从第i个红灯出发,往左到达l[i]红灯,往右到达r[i]红灯 
idl表示往左走的id，idr表示往右走的id， 
建反图找环，建图时注意方向。 
每次查询也是找往左走能走到哪个红灯，
走不到红灯说明直接出边界就YES，
否则看一下是否在环上 
*/
