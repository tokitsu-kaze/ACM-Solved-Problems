#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
ll h,c,t;
double cal(ll x)
{
	if(x<=0) return LLINF;
	if(x&1) return 1.0*((h+c)*(x/2)+h)/x;
	else return 1.0*((h+c)*(x/2))/x;
}
bool ck(ll x)
{
	return cal(x)<=t;
}
int main()
{
	int T;
	ll l,r,mid;
	double ra,rb,rc;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&h,&c,&t);
		l=0;
		r=1e12;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid*2+1)) r=mid;
			else l=mid+1;
		}
		ra=abs(cal(2*l-1)-t);
		rb=abs(cal(2*l+1)-t);
		rc=abs(cal(2)-t);
//		cout<<ra<<" "<<rb<<" "<<rc<<endl;
		if(rc<min(ra,rb)) printf("%lld\n",2LL);
		else
		{
			if(ra<rb)
			{
				if(ra==rc) printf("%lld\n",min(2LL,2*l-1));
				else printf("%lld\n",2*l-1);
			}
			else if(rb<ra)
			{
				if(rb==rc) printf("%lld\n",min(2LL,2*l+1));
				else printf("%lld\n",2*l+1);
			}
			else
			{
				if(rc==ra) printf("%lld\n",min(2LL,2*l-1));
				else printf("%lld\n",2*l-1);
			}
		}
	}
	return 0;
}

