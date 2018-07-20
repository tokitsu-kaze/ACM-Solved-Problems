#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll col[MAX],ans[MAX];
vector<int> mp[MAX];
map<ll,ll> v[MAX],cnt[MAX];
void merge(int x,int y)
{
	ll t;
	map<ll,ll> ::iterator it;
	for(it=cnt[y].begin();it!=cnt[y].end();it++)
	{
		v[x][cnt[x][it->fi]]-=it->fi;
		cnt[x][it->fi]+=it->se;
		v[x][cnt[x][it->fi]]+=it->fi;
	}
}
void dfs(int x,int pre)
{
	int i,to;
	cnt[x][col[x]]=1;
	v[x][1]=col[x];
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to!=pre)
		{
			dfs(to,x);
			if(sz(cnt[x])<sz(cnt[to]))
			{
				swap(cnt[x],cnt[to]);
				swap(v[x],v[to]);
			}
			merge(x,to);
		}
	}
	ans[x]=v[x].rbegin()->se;
}
int main()
{
	int n,i,a,b;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			v[i].clear();
			cnt[i].clear();
			scanf("%lld",&col[i]);
		}
		for(i=1;i<=n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		dfs(1,0);
		printf("%lld",ans[1]);
		for(i=2;i<=n;i++)
		{
			printf(" %lld",ans[i]);
		}
		puts("");
	}
	return 0;
}