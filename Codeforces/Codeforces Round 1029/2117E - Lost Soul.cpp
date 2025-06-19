#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX],cnt[MAX];
int main()
{
	int T,n,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		for(i=1;i<=n;i++) cnt[i]=0;
		ans=0;
		for(i=n-1;i;i--)
		{
			if(cnt[a[i]]||cnt[b[i]]||a[i]==b[i]||a[i]==a[i+1]||b[i]==b[i+1])
			{
				ans=i;
				break;
			}
			cnt[a[i+1]]++;
			cnt[b[i+1]]++;
		}
		if(a[n]==b[n]) ans=n;
		printf("%d\n",ans);
	}
	return 0;
}
