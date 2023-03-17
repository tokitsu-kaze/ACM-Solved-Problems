#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
double a[1111],b[1111];
int n,m;
int check(double x)
{
	int i;
	for(i=1;i<=n;i++)
	{
		x-=(x+m)/a[i];
		if(x<0) return 0;
		x-=(x+m)/b[i];
		if(x<0) return 0;
	}
	return 1;
}
int main()
{
	int i;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++) scanf("%lf",&a[i]);
		scanf("%lf",&b[n]);
		for(i=1;i<n;i++) scanf("%lf",&b[i]);
		double l,r,mid;
		l=0;
		r=1e9+10;
		while(r-l>eps)
		{
			mid=(l+r)/2;
			if(!check(mid)) l=mid;
			else r=mid;
		}
		if(!check(l+eps)||l>1e9) puts("-1");
		else printf("%.10f\n",l+eps);
	} 
	return 0;
}