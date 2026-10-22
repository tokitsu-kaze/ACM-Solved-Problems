#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int x[MAX],y[MAX];
int main()
{
	int T,n,i,rx,ry;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
		sort(x+1,x+1+n);
		sort(y+1,y+1+n);
		if(n&1) rx=ry=1;
		else
		{
			rx=x[n/2+1]-x[n/2]+1;
			ry=y[n/2+1]-y[n/2]+1;
		}
		printf("%lld\n",1LL*rx*ry);
	}
	return 0;
}
