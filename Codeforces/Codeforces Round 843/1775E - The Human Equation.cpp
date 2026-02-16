#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,i,x;
	ll mn,mx,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum=mn=mx=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			sum+=x;
			mn=min(mn,sum);
			mx=max(mx,sum);
		}
		printf("%lld\n",mx-mn);
	}
	return 0;
}
