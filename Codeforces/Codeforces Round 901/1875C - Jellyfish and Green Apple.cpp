#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,m,i;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		if(n%m==0)
		{
			puts("0");
			continue;
		}
		if(m&1)
		{
			puts("-1");
			continue;
		}
		ans=0;
		for(i=0;i<100;i++)
		{
			if(n==0) break;
			while(n<m)
			{
				ans+=n;
				n*=2;
			}
			n%=m;
		}
		if(n) ans=-1;
		printf("%lld\n",ans);
	}
	return 0;
}
