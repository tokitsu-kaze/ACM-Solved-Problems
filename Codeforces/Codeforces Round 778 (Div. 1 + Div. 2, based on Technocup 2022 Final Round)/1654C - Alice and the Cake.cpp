#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i;
	ll sum,x,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		map<ll,int> mp;
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			mp[x]++;
			sum+=x;
		}
		if(n==1)
		{
			puts("YES");
			continue;
		}
		vector<ll> res;
		res.push_back(sum);
		for(i=1;i<n;i++)
		{
			x=res.back();
			res.pop_back();
			a=x/2;
			b=(x+1)/2;
			if(!mp.count(a)) res.push_back(a);
			else
			{
				mp[a]--;
				if(mp[a]==0) mp.erase(a);
			}
			if(!mp.count(b)) res.push_back(b);
			else
			{
				mp[b]--;
				if(mp[b]==0) mp.erase(b);
			}
		}
		if(mp.size()) puts("NO");
		else puts("YES");
	}
	return 0;
}
/*
操作并不会有损耗，所以最初的数是 sum{a}。
模拟操作即可。
*/
