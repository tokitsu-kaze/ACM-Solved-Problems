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
struct node
{
	ll a,b;
	friend bool operator <(node a,node b)
	{
		return a.b<b.b;
	}
	void input()
	{
		scanf("%lld%lld",&a,&b);
	}
}a[MAX];
int main()
{
	ll n,r,avg,i;
	ll ans,s;
	while(~scanf("%lld%lld%lld",&n,&r,&avg))
	{
		s=0;
		for(i=0;i<n;i++)
		{
			a[i].input();
			s+=a[i].a;
		}
		avg*=n;
		sort(a,a+n);
		ans=0;
		for(i=0;i<n&&s<avg;i++)
		{
			ll tmp=min(r-a[i].a,avg-s);
			ans+=tmp*a[i].b;
			s+=tmp;
		}
		printf("%lld\n",ans);
	}
	return 0;
}