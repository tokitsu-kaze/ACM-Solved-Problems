#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX];
int main()
{
	int T,n,i;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		map<int,ll> mp;
		ans=0;
		for(i=n;i;i--)
		{
			ans+=1LL*i*mp[a[i]];
			mp[a[i]]+=n-i+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
6
1 1 2 2 1 1
ans=28

*/
