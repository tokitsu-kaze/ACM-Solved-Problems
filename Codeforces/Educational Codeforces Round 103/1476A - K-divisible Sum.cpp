#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int T,n,k,tar;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		tar=(n+k-1)/k*k;
		printf("%lld\n",(1LL*tar+n-1)/n);
	}
	return 0;
}
