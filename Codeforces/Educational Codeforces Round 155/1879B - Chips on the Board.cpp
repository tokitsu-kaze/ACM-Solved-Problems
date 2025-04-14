#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX],b[MAX];
int main()
{
	int T,n,i,mna,mnb;
	ll suma,sumb;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		suma=sumb=0;
		mna=mnb=1e9;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			suma+=a[i];
			mna=min(mna,a[i]);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			sumb+=b[i];
			mnb=min(mnb,b[i]);
		}
		printf("%lld\n",min(suma+1LL*n*mnb,sumb+1LL*n*mna));
	}
	return 0;
}

