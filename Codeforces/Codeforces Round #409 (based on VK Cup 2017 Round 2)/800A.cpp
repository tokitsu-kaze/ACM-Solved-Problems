#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
double p,a[MAX],b[MAX];
int n;
bool check(double t)
{
	int i;
	double s=0;
	for(i=0;i<n;i++)
	{
		s+=(a[i]*t-b[i]>0?a[i]*t-b[i]:0);
	}
	return s<=p*t;
}
int main()
{
	int i;
	double s;
	while(~scanf("%d%lf",&n,&p))
	{
		s=0;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&a[i],&b[i]);
			s+=a[i];
		}
		if(s<=p)
		{
			puts("-1");
			continue;
		}
		double l,r,mid;
		l=0;
		r=1e15;
		while(r-l>eps)
		{
			mid=(l+r)/2;
			if(check(mid)) l=mid;
			else r=mid;
		}
		printf("%.10lf\n",(l+r)/2);
	}
	return 0;
}