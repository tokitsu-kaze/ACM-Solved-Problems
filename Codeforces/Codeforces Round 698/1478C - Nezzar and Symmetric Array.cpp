#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll a[MAX],d[MAX];
int main()
{
	int T,n,i,ok;
	ll suf;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=2*n;i++) scanf("%lld",&d[i]);
		sort(d+1,d+1+2*n);
		ok=1;
		suf=0;
		for(i=n;i;i--)
		{
			if(d[2*i]!=d[2*i-1]) ok=0;
			if((d[2*i]-2*suf)%(2*i)) ok=0;
			if(!ok) break;
			a[i]=(d[2*i]-2*suf)/(2*i);
			suf+=a[i];
		}
//		for(i=1;i<=n;i++) printf("%lld%c",a[i]," \n"[i==n]);
		for(i=2;i<=n;i++)
		{
			if(a[i]<=a[i-1]) ok=0;
		}
		if(a[1]<=0) ok=0;
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
