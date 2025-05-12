#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e7+10;
int main()
{
	int n,i,x;
	ll ans,cnt;
	scanf("%d",&n);
	map<int,int> mp;
	vector<int> res;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		mp[x]++;
		res.push_back(x);
	}
	sort(res.begin(),res.end());
	ans=0;
	for(auto &it:mp)
	{
		cnt=lower_bound(res.begin(),res.end(),it.first*2)-res.begin();
		cnt-=it.second;
		ans+=cnt*(it.second*(it.second-1)/2);
	}
	printf("%lld\n",ans);
	return 0;
}
