#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll a[MAX];
int main()
{
	int n,i,q,pos;
	ll sum,x,y,ra,rb;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	sum=0;
	for(i=1;i<=n;i++) sum+=a[i];
	scanf("%d",&q);
	while(q--)
	{
		scanf("%lld%lld",&x,&y);
		pos=lower_bound(a+1,a+1+n,x)-a;
		ra=rb=LLINF;
		if(pos>1) ra=(x-a[pos-1])+max(0LL,y-(sum-a[pos-1]));
		if(pos<=n) rb=max(0LL,y-(sum-a[pos]));
		printf("%lld\n",min(ra,rb));
	}
	return 0;
}
