#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,m,i,f;
	ll x,sd;
	scanf("%d%d",&n,&m);
	x=0;
	sd=1;
	f=0;
	for(i=0;i<=m;i++)
	{
		x+=sd;
		sd*=n;
		if(x>1e9)
		{
			f=1;
			break;
		}
	}
	if(f) puts("inf");
	else printf("%lld\n",x);
	return 0;
}
