#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
const int mod=998244353;
int a[MAX],cnt1[MAX];
ll sum[MAX];
int main()
{
	int T,n,q,i,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		cnt1[0]=sum[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
			cnt1[i]=cnt1[i-1];
			if(a[i]==1) cnt1[i]++;
		}
		while(q--)
		{
			scanf("%d%d",&l,&r);
			if(l==r) puts("NO");
			else if(cnt1[r]-cnt1[l-1]>sum[r]-sum[l-1]-(r-l+1)) puts("NO");
			else puts("YES");
		}
	}
	return 0;
}
/*
1
5 1
1 1 1 2 2
1 5
*/
