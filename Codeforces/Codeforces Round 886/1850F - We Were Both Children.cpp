#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int cnt[MAX],res[MAX];
int main()
{
	int t,n,i,j,x,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) cnt[i]=res[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x<=n) cnt[x]++;
		}
		for(i=1;i<=n;i++)
		{
			if(!cnt[i]) continue;
			for(j=i;j<=n;j+=i) res[j]+=cnt[i];
		}
		ans=0;
		for(i=1;i<=n;i++) ans=max(ans,res[i]);
		printf("%d\n",ans);
	}
	return 0;
}
