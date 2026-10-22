#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int i,x,y,z;
	ll ans;
	scanf("%d%d%d",&x,&y,&z);
	ans=0;
	for(i=x;i<=y;i++) ans+=i/z;
	printf("%lld\n",ans);
	return 0;
}
