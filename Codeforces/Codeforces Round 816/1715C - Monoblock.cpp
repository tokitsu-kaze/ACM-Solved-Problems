#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int n,a[MAX];
ll cal(int x)
{
	if(x==1||x>n) return 0;
	if(a[x-1]==a[x]) return 0;
	return 1LL*(x-1)*(n-x+1);
}
int main()
{
	int m,i,x,v;
	ll ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=1LL*n*(n+1)/2;
	for(i=1;i<=n;i++) ans+=cal(i);
	while(m--)
	{
		scanf("%d%d",&x,&v);
		if(a[x]==v)
		{
			printf("%lld\n",ans);
			continue;
		}
		ans-=cal(x);
		ans-=cal(x+1);
		a[x]=v;
		ans+=cal(x);
		ans+=cal(x+1);
		printf("%lld\n",ans);
	}
	return 0;
}
