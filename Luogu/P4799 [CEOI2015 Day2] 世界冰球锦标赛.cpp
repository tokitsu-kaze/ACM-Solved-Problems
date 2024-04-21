#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
void dfs(int p,vector<ll> &a,vector<ll> &res,ll now)
{
	if(p==a.size())
	{
		res.push_back(now);
		return;
	}
	dfs(p+1,a,res,now+a[p]);
	dfs(p+1,a,res,now);
}
int main()
{
	int n,i;
	ll m,x,ans;
	vector<ll> a,b,ra,rb;
	scanf("%d%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		if(i&1) a.push_back(x);
		else b.push_back(x);
	}
	dfs(0,a,ra,0);
	dfs(0,b,rb,0);
	sort(ra.begin(),ra.end());
	ans=0;
	for(auto &it:rb)
	{
		if(it>m) continue;
		ans+=upper_bound(ra.begin(),ra.end(),m-it)-ra.begin();
	}
	printf("%lld\n",ans);
	return 0;
}
