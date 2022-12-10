#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int sgn(double x)
{  
	if(fabs(x)<eps) return 0;
	else return x>0?1:-1;  
}
int main()
{
	int n,i;
	double w,v,u,l,r,a,b;
	while(~scanf("%d%lf%lf%lf",&n,&w,&v,&u))
	{
		l=1e18;
		r=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf",&a,&b);
			l=min(l,a-b/(u/v));
			r=max(r,a-b/(u/v));
		}
		printf("%.10lf\n",sgn(l)>=0?w/u:r/v+w/u);
	}
	return 0;
}