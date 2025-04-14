#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll a[MAX];
int main()
{
	int T,i,n;
	ll k,sum,mx,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&k);
		sum=0;
		mx=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
			mx=max(mx,a[i]);
		}
		for(i=n;i;i--)
		{
			tmp=(i-sum%i)%i;
			if(tmp>k) continue;
			if((sum+k)/i<mx) continue;
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}

