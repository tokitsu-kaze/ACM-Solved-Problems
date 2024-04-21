#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int t,n,i,j,x,ans;
	ll tmp=(1LL<<31)-1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		map<ll,int> mp;
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(mp.count(tmp-x))
			{
				mp[tmp-x]--;
				if(mp[tmp-x]==0) mp.erase(tmp-x);
				ans++;
			}
			else mp[x]++;
		}
		for(auto &it:mp) ans+=it.second;
		printf("%d\n",ans);
	}
	return 0;
}
