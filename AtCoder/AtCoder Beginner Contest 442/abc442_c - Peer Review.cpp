#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int cnt[MAX];
ll cal(ll x)
{
	return x*(x-1)*(x-2)/6;
}
int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	memset(cnt,0,sizeof cnt);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		cnt[a]++;
		cnt[b]++;
	}
	for(i=1;i<=n;i++) printf("%lld%c",max(0LL,cal(n-1-cnt[i]))," \n"[i==n]);
	return 0;
}
