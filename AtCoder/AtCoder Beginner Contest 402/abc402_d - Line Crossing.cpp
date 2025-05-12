#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int n,m,i,l,r;
	ll ans;
	scanf("%d%d",&n,&m);
	map<int,int> mp;
	ans=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		ans+=i-mp[(l+r)%n]-1;
		mp[(l+r)%n]++;
	}
	printf("%lld\n",ans);
	return 0;
}
