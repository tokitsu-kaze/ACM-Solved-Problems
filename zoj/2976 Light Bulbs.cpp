#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int t;
	int n,i,a,b;
	double ans,x[111],y[111],z[111],I[111],r,xx,yy,res;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		res=-1;
		for(i=0;i<n;i++) scanf("%lf%lf%lf%lf",&x[i],&y[i],&z[i],&I[i]);
		for(a=-100;a<=100;a++)
		{
			for(b=-100;b<=100;b++)
			{
				ans=0;
				for(i=0;i<n;i++)
				{
					xx=x[i]-a;
					yy=y[i]-b;
					r=sqrt(xx*xx+yy*yy+z[i]*z[i]);
					ans+=I[i]/(r*r)*(z[i]/r);
				}
				res=max(res,ans);
			}
		}
		printf("%.2lf\n",res);
	}
	return 0;
}