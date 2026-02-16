#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=8e5+10;
ll c[MAX];
int main()
{
	int T,n,w,i,x;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&w);
		for(i=0;i<=2*w;i++) c[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			c[i%(2*w)]+=x;
		}
		for(i=2*w;i<4*w;i++) c[i]=c[i-2*w];
		for(i=1;i<4*w;i++) c[i]+=c[i-1];
		ans=c[w-1];
		for(i=w;i<4*w;i++) ans=min(ans,c[i]-c[i-w]);
		printf("%lld\n",ans);
	}
	return 0;
}
