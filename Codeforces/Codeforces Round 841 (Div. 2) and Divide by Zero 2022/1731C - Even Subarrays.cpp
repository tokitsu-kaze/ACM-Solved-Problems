#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int cnt[MAX];
int main()
{
	int T,n,i,j,x,now;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<=2*n;i++) cnt[i]=0;
		now=0;
		cnt[now]=1;
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			now^=x;
			ans+=i;
			for(j=0;j*j<=2*n;j++)
			{
				if(((j*j)^now)<=2*n) ans-=cnt[(j*j)^now];
			}
			cnt[now]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
