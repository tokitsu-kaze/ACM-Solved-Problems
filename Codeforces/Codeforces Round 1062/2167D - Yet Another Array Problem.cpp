#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
ll a[MAX];
int main()
{
	int T,n,i;
	ll x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(x=2;;x++)
		{
			for(i=1;i<=n;i++)
			{
				if(__gcd(x,a[i])==1)
				{
					printf("%d\n",x);
					goto end;
				}
			}
		}
		end:;
	}
	return 0;
}
