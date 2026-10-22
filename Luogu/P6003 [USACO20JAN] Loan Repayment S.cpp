#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
ll n,k,m;
int ck(ll x)
{
	ll g,y,t,now;
	g=0;
	now=0;
	while(now<k)
	{
		y=(n-g)/x;
		if(y<=m) return g+(k-now)*m>=n;
		t=min(k-now,((n-g)-x*y)/y+1);
		g+=t*y;
		now+=t;
	}
	return g>=n;
}
int main()
{
	ll l,r,mid;
	scanf("%lld%lld%lld",&n,&k,&m);
	l=1;
	r=n;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid+1)) l=mid+1;
		else r=mid;
	}
	printf("%lld\n",l);
	return 0;
}
/*
显然 x 越小越容易满足条件。考虑二分答案。
因为 k*m<n，所以 x 最大不超过 n，
超过的话每次算出来 y=0，每次都给 m，是永远不合法的。

然后就是看怎么快速 check。
对 y=(n-g)/x，每种 y 只计算一次，类似整除分块。
这样的话，每次 y 都会不同且减少，y 的总类数是根号级别的。
*/
