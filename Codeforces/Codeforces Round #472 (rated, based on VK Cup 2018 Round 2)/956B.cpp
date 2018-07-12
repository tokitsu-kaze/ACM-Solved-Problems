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
int a[MAX];
int main()
{
	int n,t,i,j,flag;
	double ans;
	while(~scanf("%d%d",&n,&t))
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=-1;
		flag=0;
		for(i=1;i<=n;i++)
		{
			j=upper_bound(a+i,a+1+n,a[i]+t)-a-1;
			if(j>i+1) ans=max(ans,(a[j]-a[i+1])*1.0/(a[j]-a[i])),flag=1;
		}
		if(!flag) puts("-1");
		else printf("%.10lf\n",ans);
	}
	return 0;
}