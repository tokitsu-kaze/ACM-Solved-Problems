#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int to,w;};
vector<node> mp[MAX];
int n,v[MAX],dp[MAX];
int ck(int x)
{
	int i;
	for(i=1;i<=n;i++) dp[i]=-1;
	dp[1]=min(v[1],x);
	for(i=1;i<=n;i++)
	{
		for(auto &it:mp[i])
		{
			if(dp[i]>=it.w)
			{
				dp[it.to]=max(dp[it.to],min(x,dp[i]+v[it.to]));
			}
		}
	}
	return dp[n]>=0;
}
int main()
{
	int T,m,i,l,r,mid,a,b,c;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			mp[i].clear();
		}
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			mp[a].push_back({b,c});
		}
		l=0;
		r=1e9;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		if(ck(l)) printf("%d\n",l);
		else puts("-1");
	}
	return 0;
}

