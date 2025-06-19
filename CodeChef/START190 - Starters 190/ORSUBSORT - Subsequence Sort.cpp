#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for(i=2;i<=n;i++)
		{
			if(a[i]>=a[i-1]) continue;
			ans=max(ans,a[i-1]-(a[i]&a[i-1]));
			a[i]|=a[i-1];
		}
		for(i=30;~i;i--)
		{
			if((ans>>i)&1)
			{
				ans=(1<<i);
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

