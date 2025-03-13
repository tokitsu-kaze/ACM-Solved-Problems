#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX];
int main()
{
	int k,n,i,q,l,r,ans;
	scanf("%d%d",&k,&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		ans=(r+1)/k*n-(l+k-1)/k*n;
		if(l%k)
		{
			l%=k;
			ans+=n-(lower_bound(a+1,a+1+n,l)-a)+1;
		}
		if(r%k!=k-1)
		{
			r%=k;
			ans+=upper_bound(a+1,a+1+n,r)-a-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}

