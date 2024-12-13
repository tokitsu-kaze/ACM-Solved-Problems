#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int T,n,i,x,cnt[1010],ans,cnt1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
		ans=cnt1=0;
		for(i=1;i<=n;i++)
		{
			if(cnt[i]==1) cnt1++;
			else if(cnt[i]>0) ans++;
		}
		ans+=(cnt1+1)/2*2;
		printf("%d\n",ans);
	}
	return 0;
}
