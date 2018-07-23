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
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int main()
{
	int t;
	scanf("%d",&t);
	ll a[66],f[66],i,n,m,pos,ans,now;
	a[0]=f[0]=1;
	for(i=1;i<=62;i++)
	{
		a[i]=a[i-1]*2+1;
		f[i]=f[i-1]*2;
	}
	ll inv2=(mod+1)/2;
	while(t--)
	{
		pos=0;
		ans=0;
		scanf("%lld",&n);
		m=n;
		for(i=62;~i;i--)
		{
			if(m-a[i]>=0)
			{
				m-=a[i];
				pos+=(1LL<<i);
			}
		}
		pos+=(m>0);
		m=pos-1;
		now=0;
		for(i=1;f[i-1]<=m;i++)
		{
			ll s=f[i-1],step=(m-s)/f[i]+1,e=(step-1)*f[i]+s;
			ll tmp=(s+e)%mod*(step%mod)%mod*inv2%mod;
			ans=(ans+tmp*i%mod)%mod;
			now+=step*i;
		}
		ans=(ans+1+(n-now-1)%mod*(pos%mod)%mod)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
