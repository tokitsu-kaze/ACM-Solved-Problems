#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,m,k,mx,mn;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		mx=min(n/k,m);
		mn=max(0,(m-mx+k-2)/(k-1));
		printf("%d\n",mx-mn);
	}
	return 0;
}
