#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=6e4+10;
int x[MAX],v[MAX],n;
int ck(double t)
{
	int i;
	double lmx,rmn;
	lmx=-1e18;
	rmn=1e18;
	for(i=1;i<=n;i++)
	{
		lmx=max(lmx,x[i]-t*v[i]);
		rmn=min(rmn,x[i]+t*v[i]);
	}
	return lmx<=rmn;
}
int main()
{
	int i;
	double l,r,mid;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&x[i]);
	for(i=1;i<=n;i++) scanf("%d",&v[i]);
	l=0;
	r=2e9;
	for(i=0;i<100;i++)
	{
		mid=(l+r)/2;
		if(ck(mid)) r=mid;
		else l=mid;
	}
	printf("%.10f\n",l);
	return 0;
}
