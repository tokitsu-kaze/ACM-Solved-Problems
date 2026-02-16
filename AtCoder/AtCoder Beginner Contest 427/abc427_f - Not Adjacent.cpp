#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[62],m;
unordered_map<int,int> mp[2];
ll ans;
void dfs1(int x,int en,int now,int ban)
{
	if(x==en)
	{
		mp[ban][now]++;
		return;
	}
	dfs1(x+1,en,now,0);
	if(!ban) dfs1(x+1,en,(now+a[x])%m,1);
}
void dfs2(int x,int en,int now,int ban)
{
	if(x==en)
	{
		now=(m-now)%m;
		if(ban==0)
		{
			if(mp[0].count(now)) ans+=mp[0][now];
			if(mp[1].count(now)) ans+=mp[1][now];
		}
		else
		{
			if(mp[0].count(now)) ans+=mp[0][now];
		}
		return;
	}
	dfs2(x-1,en,now,0);
	if(!ban) dfs2(x-1,en,(now+a[x])%m,1);
}
int main()
{
	int n,i;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	mp[0].clear();
	mp[1].clear();
	dfs1(0,(n+1)/2,0,0);
	ans=0;
	dfs2(n-1,(n+1)/2-1,0,0);
	printf("%lld\n",ans);
	return 0;
}
/*
3 4
1 0 3
*/
