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
const int MAX=5e5+10;
const ll mod=1e9+7;
ll n,h;
int check(ll x)
{
	if(x<=h)
	{
		if((1+x)*x/2>=n) return 1;
	}
	else
	{
		if(h%2)
		{
			/*
			3 4 5 4 3 2 1
			3 4 3 2 1
			3 3 2 1
			3 4 4 3 2 1
			
			22 3
			13 3
			9 3
			17 3
			*/
			if(x%2)
			{
				ll tmp=(x-h+1)/2;
				if((1+h+tmp)*(h+tmp)/2+tmp*(h+h+tmp-1)/2>=n) return 1;
			}
			else
			{
				ll tmp=(x-h)/2;
				if((1+h+tmp)*(h+tmp)/2+(h+h+tmp)*(tmp+1)/2>=n) return 1;
			}
		}
		else
		{
			/*
			4 5 4 3 2 1
			4 5 5 4 3 2 1
			4 5 6 5 4 3 2 1
			
			19 4
			24 4
			30 4
			*/
			if(x%2)
			{
				ll tmp=(x-h-1)/2;
				if((1+h+tmp)*(h+tmp)/2+(tmp+1)*(h+h+tmp)/2>=n) return 1;
			}
			else
			{
				ll tmp=(x-h-1)/2;
				if((1+h+tmp)*(h+tmp)/2+(tmp+1)*(h+h+tmp)/2+(h+tmp+1)>=n) return 1;
			}
		}	
	}
	return 0;
}
int main()
{
	ll l,r,mid;
	while(~scanf("%lld%lld",&n,&h))
	{
		r=2e9;
		l=1;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(!check(mid)) l=mid+1;
			else r=mid;
		}
		printf("%lld\n",l);
	}
	return 0;
}