#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,x;
	ll ans;
	scanf("%d",&n);
	map<int,int> mp;
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(mp.count(i-x)) ans+=mp[i-x];
		mp[i+x]++;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
j-i=ai+aj
j-aj=i+ai
*/
