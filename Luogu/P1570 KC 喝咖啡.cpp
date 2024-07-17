#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=200+10;
int v[MAX],c[MAX],n,m;
double tmp[MAX];
int ck(double x)
{
	int i;
	double res;
	for(i=1;i<=n;i++) tmp[i]=v[i]-c[i]*x;
	sort(tmp+1,tmp+1+n);
	reverse(tmp+1,tmp+1+n);
	res=0;
	for(i=1;i<=m;i++) res+=tmp[i];
	return res>=0;
}
int main()
{
	int i;
	double l,r,mid;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&v[i]);
	for(i=1;i<=n;i++) scanf("%d",&c[i]);
	l=0;
	r=2e6;
	for(i=0;i<100;i++)
	{
		mid=(l+r)/2;
		if(ck(mid)) l=mid;
		else r=mid;
	}
	printf("%.3f\n",l);
	return 0;
}
