#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
ll cnt[MAX];
int main()
{
	int n,m,i,j;
	ll ans;
	scanf("%d%d",&n,&m);
	for(i=max(n,m);i;i--)
	{
		cnt[i]=1LL*(n/i)*(m/i);
		for(j=i+i;j<=max(n,m);j+=i) cnt[i]-=cnt[j];
	}
	ans=0;
	for(i=1;i<=max(n,m);i++) ans+=i*cnt[i];
	printf("%lld\n",ans*2-1LL*n*m);
	return 0;
}

