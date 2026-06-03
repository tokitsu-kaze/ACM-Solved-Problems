#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,i,j,a[105],b[105],ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
		ok=1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(abs(b[i]-b[j])%__gcd(a[i],a[j])) ok=0;
			}
		}
		if(ok) puts("possible");
		else puts("impossible");
	}
	return 0;
}

