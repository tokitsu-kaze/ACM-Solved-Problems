#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX];
int main()
{
	int n,i,x;
	ll ans;
	scanf("%d",&n);
	map<int,int> mp[2];
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]%5==0)
		{
			x=a[i]/5;
			ans+=1LL*mp[0][x]*mp[1][x];
		}
		if(a[i]%7==0) mp[0][a[i]/7]++;
		if(a[i]%3==0) mp[1][a[i]/3]++;
	}
	mp[0].clear();
	mp[1].clear();
	for(i=n;i;i--)
	{
		if(a[i]%5==0)
		{
			x=a[i]/5;
			ans+=1LL*mp[0][x]*mp[1][x];
		}
		if(a[i]%7==0) mp[0][a[i]/7]++;
		if(a[i]%3==0) mp[1][a[i]/3]++;
	}
	printf("%lld\n",ans);
	return 0;
}
