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
#define VI vector<int>
#define VL vector<ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=998244353;
ll a[MAX],bit[MAX][2];
int main()
{
	ll n,i,ans,m,now;
	while(~scanf("%lld%lld",&n,&m))
	{
		mem(bit,0);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		a[0]=0;
		a[n+1]=m;
		n++;
		for(i=1;i<=n;i++)
		{
			bit[i][0]=bit[i-1][0];
			bit[i][1]=bit[i-1][1];
			bit[i][(i-1)&1]+=a[i]-a[i-1];
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			ans=max(ans,bit[i-1][0]+a[i]-1-a[i-1]+(bit[n][(i-1)&1]-bit[i][(i-1)&1]));
		}
		ans=max(ans,bit[n][0]);
		ans=max(ans,bit[n][1]);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3 10
4 6 7
2 12
1 10
*/