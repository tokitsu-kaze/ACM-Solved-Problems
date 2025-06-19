#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int x[MAX],y[MAX];
int main()
{
	int T,n,i,a,b;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		multiset<int> sx,sy;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			sx.insert(x[i]);
			sy.insert(y[i]);
		}
		if(n==1)
		{
			puts("1");
			continue;
		}
		ans=LLINF;
		for(i=1;i<=n;i++)
		{
			sx.erase(sx.find(x[i]));
			sy.erase(sy.find(y[i]));
			a=(*sx.rbegin())-(*sx.begin())+1;
			b=(*sy.rbegin())-(*sy.begin())+1;
			sx.insert(x[i]);
			sy.insert(y[i]);
			if(1LL*a*b==n-1) ans=min(ans,1LL*a*b+min(a,b));
			else ans=min(ans,1LL*a*b);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
