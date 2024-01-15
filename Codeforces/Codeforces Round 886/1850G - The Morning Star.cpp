#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int t,n,i,x,y;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		map<int,int> mp[4];
		scanf("%d",&n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			ans+=mp[0][x];
			ans+=mp[1][y];
			ans+=mp[2][x-y];
			ans+=mp[3][x+y];
			mp[0][x]++;
			mp[1][y]++;
			mp[2][x-y]++;
			mp[3][x+y]++;
		}
		printf("%lld\n",ans*2);
	}
	return 0;
}
