#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int a[MAX];
int main()
{
	int T,n,i;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=2*n;i++) scanf("%d",&a[i]);
		map<pair<int,int>,int> mp;
		ans=0;
		for(i=2;i<=2*n;i++)
		{
			if(i+1<=2*n && a[i]==a[i+1]) continue;
			if(mp.count({a[i-1],a[i]}) && mp[{a[i-1],a[i]}]<i-2) ans++;
			else if(mp.count({a[i],a[i-1]}) && mp[{a[i],a[i-1]}]<i-2) ans++;
			if(!mp.count({a[i-1],a[i]})) mp[{a[i-1],a[i]}]=i-1;
			if(!mp.count({a[i],a[i-1]})) mp[{a[i],a[i-1]}]=i-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
2
2
1 2 1 2
2
1 2 2 1
*/
