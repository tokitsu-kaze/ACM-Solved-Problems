#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	ll x,cnt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&x);
		if(x<=3)
		{
			puts("3");
			continue;
		}
		cnt=1;
		while(1)
		{
			if((1LL<<cnt)+(1LL<<(cnt-1))>=x)
			{
				break;
			}
			else cnt++;
		}
		printf("%d\n",cnt+2);
	}
	return 0;
}
