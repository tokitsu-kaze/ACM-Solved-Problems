#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,i;
	ll a,b,c,d;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&b,&c,&d);
		a=0;
		for(i=0;i<=61;i++)
		{
			if((d>>i)&1)
			{
				if((b>>i)&1);
				else
				{
					if((c>>i)&1)
					{
						a=-1;
						break;
					}
					a|=(1LL<<i);
				}
			}
			else
			{
				if((c>>i)&1) a|=(1LL<<i);
				else
				{
					if((b>>i)&1)
					{
						a=-1;
						break;
					}
				}
			}
		}
		printf("%lld\n",a);
	}
	return 0;
}

