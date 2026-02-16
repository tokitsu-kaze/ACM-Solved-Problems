#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,c,i,a,cnt[105],ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&c);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			cnt[a]++;
		}
		ans=0;
		for(i=1;i<=100;i++)
		{
			if(cnt[i]==0) continue;
			ans+=min(cnt[i],c);
		}
		printf("%d\n",ans);
	}
	return 0;
}
