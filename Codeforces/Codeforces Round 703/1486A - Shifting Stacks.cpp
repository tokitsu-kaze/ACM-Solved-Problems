#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,i,h[105],ok;
	ll cnt,tot;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&h[i]);
		cnt=tot=0;
		ok=1;
		for(i=1;i<=n;i++)
		{
			cnt+=h[i];
			tot+=i-1;
			if(tot>cnt) ok=0;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
