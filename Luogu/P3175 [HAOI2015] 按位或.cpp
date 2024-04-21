#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps=1e-8;
const int MAX=(1<<20)+10;
double dp[MAX];
void sosdp(int n)
{
	int i,j;
	for(j=0;j<n;j++)
	{
		for(i=0;i<(1<<n);i++)
		{
			if((i>>j)&1) dp[i]+=dp[i^(1<<j)];
		}
	}
}
int main()
{
	int n,i,cnt,s;
	double ans;
	scanf("%d",&n);
	for(i=0;i<(1<<n);i++) scanf("%lf",&dp[i]);
	sosdp(n);
	ans=0;
	for(i=1;i<(1<<n);i++)
	{
		cnt=__builtin_popcount(i);
		s=((1<<n)-1)^i;
		if(1-dp[s]<eps) return 0*puts("INF");
		if(cnt&1) ans+=1/(1-dp[s]);
		else ans+=-1/(1-dp[s]);
	}
	printf("%.10f\n",ans);
	return 0;
}
