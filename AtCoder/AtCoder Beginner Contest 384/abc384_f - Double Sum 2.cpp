#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int N=2e7+10;
int a[MAX],cnt[N][2];
ll sum[N][2];
int cal(int x)
{
	while(x%2==0) x>>=1;
	return x;
}
int main()
{
	int n,i,s,x,t;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(cnt,0,sizeof cnt);
	memset(sum,0,sizeof sum);
	ans=0;
	for(i=1;i<=n;i++) ans+=cal(a[i]);
	for(s=0;(1<<s)<N;s++)
	{
		for(i=1;i<=n;i++)
		{
			x=(a[i]&((1<<s)-1));
			t=(a[i]>>s)&1;
			ans+=1LL*((a[i]>>s)+1)*cnt[(1<<s)-x][t];
			ans+=sum[(1<<s)-x][t];
			if(x==0)
			{
				ans+=1LL*(a[i]>>s)*cnt[x][t^1];
				ans+=sum[x][t^1];
			}
			sum[x][t]+=(a[i]>>s);
			cnt[x][t]++;
		}
		for(i=1;i<=n;i++)
		{
			x=(a[i]&((1<<s)-1));
			t=(a[i]>>s)&1;
			sum[x][t]=cnt[x][t]=0;
		}
//		cout<<s<<" "<<ans<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}

