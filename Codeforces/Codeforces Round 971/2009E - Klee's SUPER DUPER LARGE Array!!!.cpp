#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
ll k,n;
ll cal(ll x)
{
	return abs((k+k+x-1)*x/2-((k+x+k+n-1)*(n-x)/2));
}
int main()
{
	int T;
	ll l,r,lm,rm,tl,tr;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		l=1;
		r=n;
		while(l<r)  
		{  
			lm=l+(r-l)/3;
			rm=r-(r-l)/3;
			tl=cal(lm);
			tr=cal(rm);
			if(tl>tr) l=lm+1;
			else r=rm-1;
		}
		printf("%lld\n",cal(l));
	}
	return 0;
}
