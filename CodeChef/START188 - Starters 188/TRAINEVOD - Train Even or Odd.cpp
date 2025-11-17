#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int T,n,i,a[105],sa,sb;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sa=sb=0;
		for(i=1;i<=n;i+=2) sa+=a[i];
		for(i=2;i<=n;i+=2) sb+=a[i];
		printf("%d\n",max(sa,sb));
	}
	return 0;
}

