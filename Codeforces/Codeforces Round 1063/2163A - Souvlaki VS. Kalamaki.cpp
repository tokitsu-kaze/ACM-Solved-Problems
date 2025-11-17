#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
const int mod=998244353;
int main()
{
	int T,n,i,a[105],ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		ok=1;
		for(i=2;i<=n;i+=2)
		{
			if(i+1<=n && a[i]!=a[i+1]) ok=0;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
