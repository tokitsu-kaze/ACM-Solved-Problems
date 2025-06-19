#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,x,i;
	ll s,ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld%d",&n,&s,&x);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		vector<ll> tmp;
		map<ll,int> mp;
		now=0;
		tmp.push_back(now+s);
		ans=0;
		for(i=1;i<=n;i++)
		{
			now+=a[i];
			if(a[i]>x)
			{
				tmp.clear();
				mp.clear();
			}
			else if(a[i]==x)
			{
				for(auto &it:tmp) mp[it]++;
				tmp.clear();
			}
			if(mp.count(now)) ans+=mp[now];
			tmp.push_back(now+s);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
