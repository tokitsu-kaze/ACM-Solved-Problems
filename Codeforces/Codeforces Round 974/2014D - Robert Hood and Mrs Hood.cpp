#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int sum[MAX],suml[MAX];
int main()
{
	int T,n,d,k,i,l,r,ra,rb,pa,pb,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&d,&k);
		for(i=0;i<=n;i++) sum[i]=suml[i]=0;
		for(i=1;i<=k;i++)
		{
			scanf("%d%d",&l,&r);
			sum[l]++;
			sum[r+1]--;
			suml[l]++;
		}
		for(i=1;i<=n;i++)
		{
			sum[i]+=sum[i-1];
			suml[i]+=suml[i-1];
		}
		ra=0;
		rb=INF;
		for(i=d;i<=n;i++)
		{
			tmp=sum[i-d+1]+(suml[i]-suml[i-d+1]);
			if(tmp>ra)
			{
				ra=tmp;
				pa=i-d+1;
			}
			if(tmp<rb)
			{
				rb=tmp;
				pb=i-d+1;
			}
		}
		printf("%d %d\n",pa,pb);
	}
	return 0;
}
