#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	ll n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		printf("%lld\n",(n-1)*(m-1)*2+n+m-2);
	}
	return 0;
}

