#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,j,k,ans,cnt,a[55];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=INF;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if((a[i]+a[j])%2) continue;
				cnt=0;
				for(k=1;k<=n;k++)
				{
					if(k==i||k==j) continue;
					if(a[k]<a[i] || a[k]>a[j]) cnt++;
				}
				ans=min(ans,cnt);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

