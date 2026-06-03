#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int sum[MAX],a[MAX];
int main()
{
	int n,i,q,l,r,pl,pr,ans;
	scanf("%d",&n);
	a[0]=sum[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1];
		if(i&1) sum[i]+=a[i]-a[i-1];
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		pl=lower_bound(a+1,a+1+n,l)-a;
		pr=upper_bound(a+1,a+1+n,r)-a-1;
//		printf("%d %d\n",pl,pr);
		ans=sum[pr]-sum[pl];
		if(pr%2==0) ans+=r-a[pr];
		if(pl&1) ans+=a[pl]-l;
		printf("%d\n",ans);
	}
	return 0;
}
