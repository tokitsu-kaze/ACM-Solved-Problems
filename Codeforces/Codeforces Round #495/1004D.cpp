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
const int MAX=1e6+10;
const ll mod=998244353;
ll a[MAX];
ll cal(ll n,ll m,ll i,ll j)
{
	return i*(i-1)*m/2
			+(n-i)*(n-i+1)*m/2
			+j*(j-1)*n/2
			+(m-j)*(m-j+1)*n/2;
}
int check(ll n,ll m,ll x,ll y)
{
	VL res;
	ll i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			res.pb(abs(i-x)+abs(j-y));
		}
	}
	sort(all(res));
	for(i=0;i<n*m;i++)
	{
		if(a[i]!=res[i]) return 0;
	}
	return 1;
}
int main()
{
	ll t,i,j,l,r,mid,tmp,ans;
	while(~scanf("%lld",&t))
	{
		ans=0;
		for(i=0;i<t;i++) scanf("%lld",&a[i]),ans+=a[i];
		sort(a,a+t);
		for(i=1;i*i<=t;i++)
		{
			if(t%i) continue;
			for(j=1;j<=(i+1)/2;j++)
			{
				l=1;
				r=(t/i+1)/2;
				while(l<=r)
				{
					mid=(l+r)>>1;
					tmp=cal(i,t/i,j,mid);
					if(tmp==ans)
					{
						if(check(i,t/i,j,mid))
						{
							printf("%lld %lld\n",i,t/i);
							printf("%lld %lld\n",j,mid);
							goto end;
						}
					}
					if(tmp>ans) l=mid+1;
					else r=mid-1;
				}
			}
		}
		puts("-1");
		end:;
	}
	return 0;
}
