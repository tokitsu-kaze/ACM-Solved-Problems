#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int ck(ll n,ll k)
{
	ll sq=sqrt(n);
	while((sq+1)*(sq+1)<=n) sq++;
	return n-sq>=k;
}
int main()
{
	int T;
	ll k,l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&k);
		l=1;
		r=2*k;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid,k)) r=mid;
			else l=mid+1;
		}
		printf("%lld\n",l);
	}
	return 0;
}

