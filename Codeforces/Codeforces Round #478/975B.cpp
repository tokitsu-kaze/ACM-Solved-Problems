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
const int MAX=5e5+10;
const ll mod=1e9+7;
ll work(ll p,ll *a)
{
	ll b[22],tmp,i,res=0;
	for(i=0;i<14;i++) b[i]=a[i];
	tmp=b[p];
	b[p]=0;
	for(i=p+1;i<14;i++)
	{
		b[i]+=tmp/14;
		if(tmp%14)
		{
			b[i]++;
			tmp--;
		}
	}
	for(i=0;i<p+1;i++)
	{
		b[i]+=tmp/14;
		if(tmp%14)
		{
			b[i]++;
			tmp--;
		}
	}
	for(i=0;i<14;i++)
	{
		if(b[i]%2==0) res+=b[i];
	}
	return res;
}
int main()
{
	ll a[22],i;
	ll ans;
	while(~scanf("%lld",&a[0]))
	{
		for(i=1;i<14;i++) scanf("%lld",&a[i]);
		ans=0;
		for(i=0;i<14;i++)
		{
			ans=max(ans,work(i,a));
		}
		printf("%lld\n",ans);
	}
	return 0;
}