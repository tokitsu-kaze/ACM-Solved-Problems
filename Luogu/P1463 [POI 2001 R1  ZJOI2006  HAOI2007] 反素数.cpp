#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX];
ll sum[MAX],pre[MAX],suf[MAX];
int main()
{
	int T,n,i,j,k;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		a[0]=0;
		for(i=2;i<=n;i++) scanf("%d",&a[i]);
		sum[0]=pre[0]=0;
		for(i=1;i<=n;i++)
		{
			sum[i]=sum[i-1]+a[i];
			pre[i]=pre[i-1]+(i-1)*a[i];
		}
		suf[n+1]=0;
		for(i=n;i;i--) suf[i]=suf[i+1]+(n-i+1)*a[i];
		printf("0 %lld",sum[n]);
		i=1;
		j=n;
		ans=sum[n];
		for(k=3;k<=n;k++)
		{
			if(k&1)
			{
				i++;
				ans+=pre[i]+suf[j+1];
				ans+=(sum[j]-sum[i])*(n-j+1);
			}
			else
			{
				j--;
				ans+=pre[i]+suf[j+1];
				ans+=(sum[j]-sum[i])*i;
			}
			printf(" %lld",ans);
		}
		puts("");
	}
	return 0;
}
/*
选了两端再选中间，中间点的贡献固定是两端点长度。
所以贪心地每次选一左一右即可。
*/
