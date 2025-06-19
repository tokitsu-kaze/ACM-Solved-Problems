#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
int main()
{
	int T,n,q,i,x,y;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for(i=1;i<n;i++)
		{
			b[i]=min(a[i],a[i+1]);
			ans+=b[i];
		}
		while(q--)
		{
			scanf("%d%d",&x,&y);
			if(x>1) ans-=b[x-1];
			if(x<n) ans-=b[x];
			a[x]=y;
			if(x>1)
			{
				b[x-1]=min(a[x-1],a[x]);
				ans+=b[x-1];
			}
			if(x<n)
			{
				b[x]=min(a[x],a[x+1]);
				ans+=b[x];
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}

