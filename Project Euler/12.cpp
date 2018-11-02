#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
template<class T>string to_string(T x){ostringstream sout;sout<<x;return sout.str();}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int check(ll x)
{
	ll sq=sqrt(x+0.5);
	int res=0;
	for(ll i=1;i<=sq;i++)
	{
		if(x%i==0)
		{
			res++;
			if(x/i!=i) res++;
		}
	}
	return res;
} 
int main()
{
	ll d=2,now=1;
	while(1)
	{
		now+=d;
		d++;
		if(check(now)>500) break;
	}
	printf("%lld\n",now);
	return 0;
}
/*

76576500

*/