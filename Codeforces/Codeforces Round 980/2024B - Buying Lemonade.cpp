#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,ans;
	ll k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		ans=k;
		a[0]=0;
		for(i=1;i<=n;i++)
		{
			k-=1LL*(a[i]-a[i-1])*(n-i+1);
			if(k<=0) break;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

