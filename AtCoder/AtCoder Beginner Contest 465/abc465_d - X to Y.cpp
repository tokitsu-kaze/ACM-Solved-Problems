#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int main()
{
	int T,ans,now;
	ll x,y,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&x,&y,&k);
		now=0;
		map<ll,int> mp;
		while(1)
		{
			mp[x]=now;
			if(x==0) break;
			now++;
			x/=k;
		}
		now=0;
		while(1)
		{
			if(mp.count(y))
			{
				ans=now+mp[y];
				break;
			}
			if(y==0) break;
			now++;
			y/=k;
		}
		printf("%d\n",ans);
	}
	return 0;
}
