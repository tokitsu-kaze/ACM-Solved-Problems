#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,j,k,ans,sq,ok,g;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		sq=sqrt(n);
		for(k=1;k<=sq;k++)
		{
			if(n%k) continue;
			ok=1;
			g=0;
			for(i=1;i<=k;i++)
			{
				for(j=i;j<=n;j+=k) g=__gcd(g,abs(a[j]-a[i]));
			}
			if(g==1) ok=0;
//			printf("%d %d\n",k,ok);
			ans+=ok;
			
			if(n/k==k) continue;
			
			ok=1;
			g=0;
			for(i=1;i<=n/k;i++)
			{
				for(j=i;j<=n;j+=n/k) g=__gcd(g,abs(a[j]-a[i]));
			}
			if(g==1) ok=0;
//			printf("%d %d\n",n/k,ok);
			ans+=ok;
		}
		printf("%d\n",ans);
	}
	return 0;
}

