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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll a[MAX];
ll check(ll x,ll n)
{
	int i;
	for(i=0;i<n;i++)
	{
		x=x/a[i]*a[i];
	}
	return x;
}
int main()
{
	ll n,i,ans[2];
	while(~scanf("%lld",&n))
	{
		mem(ans,0);
		for(i=0;i<n;i++) scanf("%lld",&a[i]);
		ll l,r,mid;
		l=2;
		r=(ll)1e18;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(check(mid,n)<2) l=mid+1;
			else r=mid;
		}
		if(check(l,n)==2) ans[0]=l;
		else
		{
			puts("-1");
			continue;
		}
		l=2;
		r=(ll)1e18;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(check(mid+1,n)<=2) l=mid+1;
			else r=mid;
		}
		if(check(l,n)==2) ans[1]=l;
		else ans[1]=ans[0];
		printf("%lld %lld\n",ans[0],ans[1]);
	}
	return 0;
}
/*
2 2 3
3 3 5
4 4 7
3 6 8
6 6 11

3
2 3 2
5
6 3 4 3 2
4
3 4 3 2
5
3 4 100 3 2
10
2 2 2 2 2 2 2 2 2 2
*/
