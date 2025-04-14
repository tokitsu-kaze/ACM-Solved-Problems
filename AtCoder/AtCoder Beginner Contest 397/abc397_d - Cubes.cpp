#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e6+10;
int main()
{
	int i,ra,rb;
	ll n,l,r,mid;
	scanf("%lld",&n);
	ra=rb=-1;
	for(i=1;i<MAX;i++)
	{
		if(n%i) continue;
		l=1;
		r=1e9;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(mid*mid+mid*(mid+i)+(mid+i)*(mid+i)>=n/i) r=mid;
			else l=mid+1;
		}
		if(l*l+l*(l+i)+(l+i)*(l+i)==n/i)
		{
			ra=l+i;
			rb=l;
			break;
		}
	}
	if(ra==-1) puts("-1");
	else printf("%d %d\n",ra,rb);
	return 0;
}
/*
(x-y)*(x^2+xy+y^2)
*/
