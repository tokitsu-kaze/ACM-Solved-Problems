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
struct Base
{
	#define type ll
	#define mx 60
	type d[mx+3],p[mx+3],cnt;
	Base()
	{
		memset(d,0,sizeof(d));
		memset(p,0,sizeof(p));
		cnt=0;
	}
	bool insert(type x)
	{
		int i;
		for(i=mx;~i;i--)
		{
			if(!(x&(1LL<<i))) continue;
			if(!d[i])
			{
				d[i]=x;
				break;
			}
			x^=d[i];
		}
		return x>0;
	}
	type query_max()
	{
		int i;
		type res=0;
		for(i=mx;~i;i--)
		{
			if((res^d[i])>res) res^=d[i];
		}
		return res;
	}
	type query_min()
	{
		for(int i=0;i<=mx;i++)
		{
			if(d[i]) return d[i];
		}
		return 0;
	}
	void rebuild()
	{
		int i,j;
		for(i=60;~i;i--)
		{
			for(j=i-1;~j;j--)
			{
				if(d[i]&(1LL<<j)) d[i]^=d[j];
			}
		}
		for(i=0;i<=60;i++)
		{
			if(d[i]) p[cnt++]=d[i];
		}
	}
	type kth(type k)
	{
		type ret=0;
		if (k>=(1LL<<cnt))
			return -1;
		for (type i=60;i>=0;i--)
			if (k&(1LL<<i))
				ret^=p[i];
		return ret;
	}
	void merge(Base x)
	{
		for(int i=mx;~i;i--)
		{
			if(x.d[i]) insert(x.d[i]);
		}
	}
};
int main()
{
	ll n,i,a[111];
	while(~scanf("%lld",&n))
	{
		Base b;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			b.insert(a[i]);
		}
		printf("%lld\n",b.query_max());
	}
	return 0;
}
