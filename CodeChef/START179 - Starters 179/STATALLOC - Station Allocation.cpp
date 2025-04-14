#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll a[MAX];
int main()
{
	int T,n,i,q;
	ll sum,x,y,c,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		sort(a+1,a+1+n);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%lld%lld",&x,&y);
			ans=LLINF;
			c=*upper_bound(a+1,a+n,sum-y);
			ans=min(ans,max(0LL,x-c)+max(0LL,y-(sum-c)));
			c=*(upper_bound(a+2,a+1+n,sum-y)-1);
			ans=min(ans,max(0LL,x-c)+max(0LL,y-(sum-c)));
			c=*lower_bound(a+1,a+n,x);
			ans=min(ans,max(0LL,x-c)+max(0LL,y-(sum-c)));
			c=*(lower_bound(a+2,a+1+n,x)-1);
			ans=min(ans,max(0LL,x-c)+max(0LL,y-(sum-c)));
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
x<=ci
y<=sum-ci
ci<=sum-y

1
4
1 2 3 5
1
4 7
*/
