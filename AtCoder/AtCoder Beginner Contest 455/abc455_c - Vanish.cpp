#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
int main()
{
	int n,k,i,x;
	ll sum;
	scanf("%d%d",&n,&k);
	map<int,ll> mp;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		mp[x]+=x;
	}
	vector<ll> res;
	for(auto &it:mp) res.push_back(it.second);
	sort(res.begin(),res.end());
	while(k--)
	{
		if(res.size()>0) res.pop_back();
	}
	sum=0;
	for(auto &it:res) sum+=it;
	printf("%lld\n",sum);
	return 0;
}
