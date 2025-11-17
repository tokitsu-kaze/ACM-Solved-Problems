#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T;
	ll a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
		if(b&1)
		{
			a*=b;
			b=1;
		}
		else
		{
			a*=b/2;
			b=2;
		}
		if((a+b)%2==0) printf("%lld\n",a+b);
		else puts("-1");
	}
	return 0;
}
