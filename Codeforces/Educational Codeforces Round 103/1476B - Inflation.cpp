#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,k,i,p;
	ll ans,sum,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		sum=ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&p);
			if(i>1) tmp=max(0LL,p*100LL-sum*k+k-1)/k;
			else tmp=0;
			ans+=tmp;
			sum+=p+tmp;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

