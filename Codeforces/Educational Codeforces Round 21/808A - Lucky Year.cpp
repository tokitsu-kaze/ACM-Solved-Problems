#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,sd,res;
	scanf("%lld",&n);
	sd=1;
	while(sd*10<=n) sd*=10;
	res=0;
	while(res<=n) res+=sd;
	printf("%lld\n",res-n);
	return 0;
}
