#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+10;
int a[MAX];
int main()
{
	int T,n,i;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for(i=2;i<=n;i++)
		{
			if(a[i-1]>a[i]) ans+=1LL*(i-1)*(n-i+1);
		}
		ans+=1LL*n*(n+1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}
