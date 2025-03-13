#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int cnt[MAX];
int main()
{
	int T,n,i,x,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
		ans=n-cnt[0];
		for(i=1;i<=n;i++)
		{
			if(cnt[i]>=2) ans-=cnt[i]/2*2;
		}
		if(ans<n) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
