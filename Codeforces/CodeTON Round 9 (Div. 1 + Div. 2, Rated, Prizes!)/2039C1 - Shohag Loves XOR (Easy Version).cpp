#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
const int mod=1e9+7;
int main()
{
	int T,i,ans;
	ll x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&x,&y);
		ans=0;
		for(i=1;i<=min(3*x,y);i++)
		{
			if((i^x)==0) continue;
			if(x%(i^x)==0 || i%(i^x)==0) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

