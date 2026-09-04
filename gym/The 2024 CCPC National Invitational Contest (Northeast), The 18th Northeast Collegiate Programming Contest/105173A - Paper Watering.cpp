#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
const double eps=1e-6;
int main()
{
	int x,k,sq;
	ll ans;
	scanf("%d%d",&x,&k);
	if(x==1) ans=1;
	else ans=k+1;
	while(k>0)
	{
		if(x==1) break;
		sq=sqrt(x);
		while(sq*sq<=x) sq++;
		while(sq*sq>x) sq--;
		ans++;
		k--;
		if(sq*sq!=x && sq!=1) ans+=k;
		x=sq;
	}
	printf("%lld\n",ans);
	return 0;
}
