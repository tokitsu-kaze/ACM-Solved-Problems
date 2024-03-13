#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int t,n,i,x,ok;
	ll s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		map<ll,int> mp;
		mp[0]=1;
		s=0;
		ok=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(i&1) s+=x;
			else s-=x;
			if(mp.count(s)) ok=1;
			mp[s]=1;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}

