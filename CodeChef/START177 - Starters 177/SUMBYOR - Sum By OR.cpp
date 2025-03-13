#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],tot,res[33];
int lowbit(int x){return x&(-x);}
void dfs(int x,int now)
{
	if(x==0)
	{
		if(now) res[tot++]=now;
		return;
	}
	dfs(x-lowbit(x),now);
	dfs(x-lowbit(x),now|lowbit(x));
}
int main()
{
	int T,n,i,j,bs;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		map<int,int> mp;
		ans=0;
		for(i=1;i<=n;i++)
		{
			ans+=i-1;
			tot=0;
			dfs(a[i],0);
			for(j=0;j<tot;j++)
			{
				bs=__builtin_popcount(res[j]);
				if(bs&1) ans+=mp[res[j]];
				else ans-=mp[res[j]];
			}
			for(j=0;j<tot;j++) mp[res[j]]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
