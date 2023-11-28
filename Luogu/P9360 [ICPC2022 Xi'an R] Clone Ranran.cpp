#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int t;
	ll a,b,c,i,ans,tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		ans=b*c;
		for(i=0;i<=30;i++)
		{
			tmp=(1LL<<i);
			ans=min(ans,i*a+(c+tmp-1)/tmp*b);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
