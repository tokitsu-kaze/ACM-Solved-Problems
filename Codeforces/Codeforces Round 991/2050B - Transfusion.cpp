#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i;
	ll sum[2],cnt[2];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum[0]=sum[1]=0;
		cnt[0]=cnt[1]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum[i&1]+=a[i];
			cnt[i&1]++;
		}
		if(sum[0]%cnt[0]==0 && sum[1]%cnt[1]==0 &&
			sum[0]/cnt[0]==sum[1]/cnt[1]) puts("YES");
		else puts("NO");
	}
	return 0;
}
