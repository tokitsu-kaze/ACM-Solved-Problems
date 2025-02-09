#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int a[MAX],cnt[MAX];
int main()
{
	int T,n,k,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=2*n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		ans=0;
		for(i=2*n;i;i--)
		{
			while(cnt[i]>0)
			{
				cnt[i]--;
				if(k-i>=0 && cnt[k-i]>0)
				{
					cnt[k-i]--;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

