#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,cnt,ans,i,p[]={2,3,5,7};
	while(~scanf("%lld",&n))
	{
		if(n==0) break;
		ans=1;
		for(i=0;i<4;i++)
		{
			cnt=0;
			while(n%p[i]==0)
			{
				n/=p[i];
				cnt++;
			}
			ans*=(cnt+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
