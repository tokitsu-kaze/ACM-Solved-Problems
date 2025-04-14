#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T;
	ll x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&x,&y);
		if(x==y) puts("-1");
		else printf("%lld\n",(1LL<<50)-max(x,y));
	}
	return 0;
}
