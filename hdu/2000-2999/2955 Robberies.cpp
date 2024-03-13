#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=10000+10;
int w[MAX];
long double v[MAX],dp[MAX];
int main()
{
	int t,n,i,j,sum,ans;
	long double p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%Lf%d",&p,&n);
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%Lf",&w[i],&v[i]);
			sum+=w[i];
		}
		for(i=0;i<=sum;i++) dp[i]=0;
		dp[0]=1;
		for(i=1;i<=n;i++)
		{
			for(j=sum;j>=w[i];j--)
			{
				dp[j]=max(dp[j],dp[j-w[i]]*(1-v[i]));
			}
		}
		ans=0;
		for(i=sum;~i;i--)
		{
	//		printf("%d %.10Lf\n",i,1-dp[i]);
			if(dp[i]>1-p)
			{
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
0.110000 40
7 0.280000
59 0.210000
26 0.150000
37 0.900000
50 0.910000
16 0.250000
25 0.180000
51 0.960000
37 0.890000
66 0.220000
29 0.010000
54 0.580000
89 0.430000
96 0.550000
18 0.720000
0 0.360000
9 0.250000
92 0.110000
2 0.360000
79 0.290000
6 0.040000
23 0.470000
95 0.320000
73 0.740000
97 0.320000
85 0.390000
98 0.780000
22 0.910000
46 0.390000
11 0.700000
6 0.640000
41 0.640000
75 0.160000
4 0.330000
15 0.290000
34 0.350000
82 0.730000
57 0.570000
31 0.770000
61 0.300000
*/
