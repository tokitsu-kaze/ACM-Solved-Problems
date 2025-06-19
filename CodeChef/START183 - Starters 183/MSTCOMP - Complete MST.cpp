#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,l,r;
	ll m,tot;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&m);
		tot=1LL*n*(n-1)/2;
		l=max(0LL,n-1-(tot-m));
		r=max(1,(int)sqrt(2*(tot-m)));
		while(1LL*r*(r-1)/2>tot-m) r--;
		while(1LL*r*(r-1)/2<tot-m) r++;
		r=n-r;
		printf("%lld\n",1LL*(l+r)*(r-l+1)/2);
	}
	return 0;
}

