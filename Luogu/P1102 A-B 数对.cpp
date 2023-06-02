#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,c,i,x;
	ll ans;
	scanf("%d%d",&n,&c);
	map<int,int> mp;
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(mp.count(x+c)) ans+=mp[x+c];
		if(mp.count(x-c)) ans+=mp[x-c];
		mp[x]++;
	}
	printf("%lld\n",ans);
	return 0;
}
