#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,i,cnt[105],x,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			cnt[x]=1;
		}
		ans=0;
		for(i=1;i<=n;i++) ans+=cnt[i];
		printf("%d\n",ans);
	}
	return 0;
}
