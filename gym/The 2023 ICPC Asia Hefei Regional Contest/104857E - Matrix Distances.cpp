#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,m,i,j,c;
	ll ans,now,cnt;
	map<int,vector<int>> x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&c);
			x[c].push_back(i);
			y[c].push_back(j);
		}
	}
	ans=0;
	for(auto &it:x)
	{
		sort(it.second.begin(),it.second.end());
		now=cnt=0;
		for(auto &it2:it.second)
		{
			now+=it2;
			cnt++;
			ans+=cnt*it2-now;
		}
	}
	for(auto &it:y)
	{
		sort(it.second.begin(),it.second.end());
		now=cnt=0;
		for(auto &it2:it.second)
		{
			now+=it2;
			cnt++;
			ans+=cnt*it2-now;
		}
	}
	printf("%lld\n",ans*2);
	return 0;
}
