#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int res[MAX];
ll ha[MAX],base,p,tar;
map<ll,int> flag;
vector<int> mp[MAX];
void dfs0(int x,int fa)
{
	ha[x]=1;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs0(to,x);
		ha[x]=(ha[x]+ha[to]*base)%p;
	}
}
void dfs(int x,int fa)
{
	if(flag.count((ha[x]-tar+p)%p)) res[x]++;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		ha[x]-=ha[to]*base;
		ha[x]=(ha[x]%p+p)%p;
		ha[to]+=ha[x]*base;
		ha[to]=(ha[to]%p+p)%p;
		dfs(to,x);
		ha[to]-=ha[x]*base;
		ha[to]=(ha[to]%p+p)%p;
		ha[x]+=ha[to]*base;
		ha[x]=(ha[x]%p+p)%p;
	}
}
int n,cnt[MAX];
void work(ll _base,ll _p)
{
	int i;
	ll now;
	base=_base;
	p=_p;
	flag.clear();
	now=1;
	tar=0;
	for(i=0;i<=n;i++)
	{
		tar=(tar+now*cnt[i])%p;
		flag[now]=1;
		now=now*base%p;
	}
	dfs0(1,0);
	dfs(1,0);
}
int main()
{
	int i,x,a,b;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		mp[i].clear();
		cnt[i]=res[i]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	work(1333331,1e9+9);
	work(2333333,998244353);
	vector<int> ans;
	for(i=1;i<=n;i++)
	{
		if(res[i]==2) ans.push_back(i);
	}
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();i++) printf("%d%c",ans[i]," \n"[i+1==ans.size()]);
	return 0;
}
