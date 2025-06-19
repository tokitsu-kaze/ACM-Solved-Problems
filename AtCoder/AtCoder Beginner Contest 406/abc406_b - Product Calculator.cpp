#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2.5e5+10;
const ll limt=1e18;
int main()
{
	int n,k,i;
	ll now,x;
	scanf("%d%d",&n,&k);
	now=1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		if(now>limt/x) now=1;
		else now*=x;
		string tmp=to_string(now);
		if(tmp.size()>k) now=1;
	}
	printf("%lld\n",now);
	return 0;
}
