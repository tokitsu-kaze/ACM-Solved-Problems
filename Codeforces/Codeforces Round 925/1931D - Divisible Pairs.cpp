#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int t,n,i,x,y;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&x,&y);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		map<pair<int,int>,int> mp;
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(mp.count({a[i]%x,((y-a[i])%y+y)%y}))
			{
				ans+=mp[{a[i]%x,((y-a[i])%y+y)%y}];
			}
			mp[{((x-a[i])%x+x)%x,((y-a[i])%y+y)%y}]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
