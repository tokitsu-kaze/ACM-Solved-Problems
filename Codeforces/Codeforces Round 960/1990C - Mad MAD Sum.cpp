#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],cnt[MAX];
int main()
{
	int T,n,i,j;
	ll sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sum=0;
		for(j=0;j<2;j++)
		{
			a[0]=0;
			for(i=0;i<=n;i++) cnt[i]=0;
			for(i=1;i<=n;i++)
			{
				sum+=a[i];
				cnt[a[i]]++;
				if(cnt[a[i]]>=2) a[i]=max(a[i-1],a[i]);
				else a[i]=a[i-1];
			}
		}
		for(i=1;i<=n;i++) sum+=1LL*a[i]*(n-i+1);
		printf("%lld\n",sum);
	}
	return 0;
}
/*
1 1 1 2 2 2 3 3 3
0 1 1 1 2 2 2 3 3
0 0 1 1 1 2 2 2 3
0 0 0 1 1 1 2 2 2

1 2 3 1 1 2 3 1 1
0 0 0 1 1 2 3 3 3
0 0 0 0 1 1 1 3 3
0 0 0 0 0 1 1 1 3
*/
