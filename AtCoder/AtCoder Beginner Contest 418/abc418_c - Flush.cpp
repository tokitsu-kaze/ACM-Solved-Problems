#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
int cnt[MAX],sumcnt[MAX];
ll sum[MAX];
int main()
{
	int n,q,i,x;
	memset(cnt,0,sizeof cnt);
	memset(sumcnt,0,sizeof sumcnt);
	memset(sum,0,sizeof sum);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	for(i=1;i<=MAX-10;i++)
	{
		sum[i]=sum[i-1]+1LL*i*cnt[i];
		sumcnt[i]=sumcnt[i-1]+cnt[i];
	}
	while(q--)
	{
		scanf("%d",&x);
		if(sumcnt[x-1]==n)
		{
			puts("-1");
			continue;
		}
		printf("%lld\n",sum[x-1]+1LL*(n-sumcnt[x-1])*(x-1)+1);
	}
	return 0;
}
