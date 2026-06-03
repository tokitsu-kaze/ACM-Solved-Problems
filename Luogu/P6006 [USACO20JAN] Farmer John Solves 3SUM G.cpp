#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
const int D=2e6;
const int V=2*D+10;
int cnt[V],a[MAX];
ll sum[MAX][MAX];
ll ask(int x1,int y1,int x2,int y2) // (x1,y1)-(x2,y2)
{
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int main()
{
	int n,q,i,j,l,r;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(sum,0,sizeof sum);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		cnt[-a[i+1]+D]=1;
		for(j=i+2;j<=n;j++)
		{
			sum[i][j]=cnt[a[i]+a[j]+D];
			cnt[-a[j]+D]++;
		}
		for(j=i+1;j<=n;j++) cnt[-a[j]+D]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}
	while(q--)
	{
		scanf("%d%d",&l,&r);
		printf("%lld\n",ask(l,l,r,r));
	}
	return 0;
}
/*
枚举i,k，O(n^2)预处理区间[i,k]里有几个。
然后做二维前缀和，查询的矩形是(l,l)-(r,r)。
*/
