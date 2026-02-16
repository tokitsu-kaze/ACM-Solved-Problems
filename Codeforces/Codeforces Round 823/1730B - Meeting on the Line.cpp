#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int x[MAX],t[MAX],n;
int ck(double mid)
{
	int i;
	double lmx,rmx;
	lmx=rmx=0;
	for(i=1;i<=n;i++)
	{
		if(x[i]<=mid) lmx=max(lmx,mid-x[i]+t[i]);
		else rmx=max(rmx,x[i]-mid+t[i]);
	}
	return rmx>=lmx;
}
int main()
{
	int T,i;
	double l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&x[i]);
		for(i=1;i<=n;i++) scanf("%d",&t[i]);
		l=0;
		r=1e8;
		for(i=0;i<100;i++)
		{
			mid=(l+r)/2;
			if(ck(mid)) l=mid;
			else r=mid;
		}
		printf("%.10f\n",l);
	}
	return 0;
}
