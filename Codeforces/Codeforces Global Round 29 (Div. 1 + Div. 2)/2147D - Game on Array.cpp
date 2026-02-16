#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,x,f;
	ll ra,rb,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		map<int,int> mp;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			mp[x]++;
		}
		vector<int> res;
		ra=rb=0;
		for(auto &it:mp)
		{
			if(it.first&1) res.push_back(it.second);
			tmp=it.first/2LL*it.second;
			ra+=tmp;
			rb+=tmp;
		}
		sort(res.begin(),res.end());
		reverse(res.begin(),res.end());
		for(i=0;i<res.size();i++)
		{
			if(i&1) rb+=res[i];
			else ra+=res[i];
		}
		printf("%lld %lld\n",ra,rb);
	}
	return 0;
}
