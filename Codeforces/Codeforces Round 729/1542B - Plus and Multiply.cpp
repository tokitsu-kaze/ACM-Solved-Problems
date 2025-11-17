#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=1e9+7;
int main()
{
	int T,i,ok;
	ll n,a,b,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&a,&b);
		if(a==1)
		{
			if((n-a)%b==0) puts("Yes");
			else puts("No");
			continue;
		}
		now=1;
		ok=0;
		while(now<=n)
		{
			if((n-now)%b==0)
			{
				ok=1;
				break;
			}
			now*=a;
		}
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}
