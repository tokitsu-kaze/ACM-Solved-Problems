#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int cnt[MAX],sum[MAX];
int main()
{
	int T,x,i,l,r;
	sum[0]=0;
	for(i=1;i<=MAX-10;i++)
	{
		cnt[i]=0;
		x=i;
		while(x>0)
		{
			cnt[i]++;
			x/=3;
		}
		sum[i]=sum[i-1]+cnt[i];
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",cnt[l]+(sum[r]-sum[l-1]));
	}
	return 0;
}
