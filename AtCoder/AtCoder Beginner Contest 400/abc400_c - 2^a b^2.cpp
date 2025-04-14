#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int i,j;
	ll n,ans,sq;
	scanf("%lld",&n);
	ans=0;
	for(i=1;i<=60;i++)
	{
		sq=sqrt(n>>i);
		while((1LL<<i)*sq*sq<=n) sq++;
		while((1LL<<i)*sq*sq>n) sq--;
		ans+=sq;
		ans-=sq/2;
	}
	printf("%lld\n",ans);
	return 0;
}
