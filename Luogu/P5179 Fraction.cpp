#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
ll dfs(ll a,ll b,ll c,ll d)
{
	ll k=a/b;
	a-=b*k;
	c-=d*k;
	if(c>d) return 1;
	return dfs(d,c,b,a)*d/c+1;
}
int main()
{
	int T;
	ll a,b,c,d,p,q;
	while(~scanf("%lld%lld%lld%lld",&a,&b,&c,&d))
	{
		q=dfs(a,b,c,d);
		p=a*q/b+1;
		printf("%lld/%lld\n",p,q);
	}
	return 0;
}

