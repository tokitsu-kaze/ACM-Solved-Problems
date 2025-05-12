#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T;
	ll a,b,c;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		if((a+b+c)%3) puts("NO");
		else
		{
			if(b>(a+b+c)/3) puts("NO");
			else puts("YES");
		}
	}
	return 0;
}
