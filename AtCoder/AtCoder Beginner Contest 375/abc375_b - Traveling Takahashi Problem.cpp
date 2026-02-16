#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int x[MAX],y[MAX];
ll sqr(ll x){return x*x;}
int main()
{
	int n,i;
	double ans;
	scanf("%d",&n);
	ans=0;
	x[0]=y[0]=0;
	for(i=1;i<=n+1;i++)
	{
		if(i==n+1) x[i]=y[i]=0;
		else scanf("%d%d",&x[i],&y[i]);
		ans+=sqrt(sqr(x[i]-x[i-1])+sqr(y[i]-y[i-1]));
	}
	printf("%.10f\n",ans);
	return 0;
}
