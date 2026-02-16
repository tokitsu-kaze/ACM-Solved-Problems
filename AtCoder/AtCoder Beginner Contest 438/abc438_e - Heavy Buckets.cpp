#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],to[33][MAX];
ll s[33][MAX];
int main()
{
	int n,q,t,b,i,j;
	ll ans;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[0][i]=i;
		to[0][i]=a[i];
	}
	for(j=1;j<=30;j++)
	{
		for(i=1;i<=n;i++)
		{
			s[j][i]=s[j-1][i]+s[j-1][to[j-1][i]];
			to[j][i]=to[j-1][to[j-1][i]];
		}
	}
	while(q--)
	{
		scanf("%d%d",&t,&b);
		ans=0;
		for(j=0;j<=30;j++)
		{
			if((t>>j)&1)
			{
				ans+=s[j][b];
				b=to[j][b];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
