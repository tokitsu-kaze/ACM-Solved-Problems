#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,cnt[22],ans,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
		ans=0;
		for(i=1;i<=n;i++) ans+=cnt[i]/2;
		printf("%d\n",ans);
	}
	return 0;
}
