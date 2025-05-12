#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
ll up[MAX],down[MAX];
int main()
{
	int T,n,i;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		ans=0;
		up[0]=down[0]=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				up[i]=down[i-1]+1;
				down[i]=0;
			}
			else
			{
				up[i]=up[i-1]+(i-1);
				down[i]=down[i-1]+(n-i);
			}
			ans=max({ans,up[i],down[i]});
		}
		printf("%lld\n",ans);
	}
	return 0;
}
