#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,a,b,c,sd,tmp,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(c!=a+1)
		{
			puts("-1");
			continue;
		}
		sd=0;
		while(a>=(1<<sd))
		{
			a-=(1<<sd);
			sd++;
		}
		ans=sd;
		if(a)
		{
			ans++;
			tmp=(1<<sd)-a;
			b-=tmp;
			if(b>0)
			{
				tmp+=2*a;
				ans+=(b+tmp-1)/tmp;
			}
		}
		else
		{
			tmp=(1<<sd);
			ans+=(b+tmp-1)/tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}
