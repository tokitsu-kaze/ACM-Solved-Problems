#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e3+10;
void bf(ll p,ll m)
{
	int i;
	set<int> s;
	for(i=0;i<=m;i++) s.insert((p-1)^i);
	for(auto &it:s) printf("%d ",it);
	puts("");
}
ll gao(ll x,ll p)
{
	x--;
	if(x<0) return 0;
	return x/p+1;
}
ll cal(ll l,ll r,ll p)
{
	return gao(r,p)-gao(l-1,p);
}
int main()
{
	int T,i;
	ll p,m,l,r,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&p,&m);
//		bf(p,m);
		ans=0;
		for(i=60;~i;i--)
		{
			if(!((m>>i)&1)) continue;
			l=(m>>i)^1;
			l^=((p-1)>>i);
			l<<=i;
			r=l+(1LL<<i)-1;
			ans+=cal(l,r,p);
//			printf("%lld %lld\n",l,r);
		}
//		printf("%lld %lld\n",m^(p-1),m^(p-1));
		if((m^(p-1))%p==1) ans++;
		printf("%lld\n",ans);
	}
	return 0;
}

