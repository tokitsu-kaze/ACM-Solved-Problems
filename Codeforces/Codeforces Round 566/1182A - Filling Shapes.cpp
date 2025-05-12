#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n;
	scanf("%d",&n);
	if(n&1) puts("0");
	else printf("%lld\n",1LL<<(n>>1));
	return 0;
}

