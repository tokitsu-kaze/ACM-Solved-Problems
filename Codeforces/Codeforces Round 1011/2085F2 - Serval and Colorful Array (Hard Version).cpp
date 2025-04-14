#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+20;
int a[MAX],lst[MAX];
ll sum[MAX];
int main()
{
	int T,n,k,i,mid,l,r;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=k;i++) lst[i]=0;
		for(i=0;i<=n;i++) sum[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(!lst[a[i]])
			{
				sum[1]+=i-1;
				sum[2]-=i;
			}
			else
			{
				l=lst[a[i]];
				r=i;
				mid=(l+r)>>1;
				if((r-l+1)&1) sum[mid+1]-=2;
				else
				{
					sum[mid+1]--;
					sum[mid+2]--;
				}
			}
			sum[i+1]+=2;
			lst[a[i]]=i;
		}
		for(i=1;i<=n;i++) sum[i]+=sum[i-1];
		for(i=1;i<=n;i++) sum[i]+=sum[i-1];
//		for(i=1;i<=n;i++) printf("%lld%c",sum[i]," \n"[i==n]);
		ans=LLINF;
		for(i=1;i<=n;i++) ans=min(ans,sum[i]);
		for(i=1;i<=k;i++) ans-=abs(i-(k+1)/2);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
x x x 1 x x x 1 x x x x 1 x x 
3 2 1 0 1 2 1 0 1 2 2 1 0 1 2
3 -1 -1 -1 1 1 -1 -1 1 1 0 -1 -1 1 1
3 -4 0 0 2 0 -2 0 2 0 -1 -1 0 2 0
*/
