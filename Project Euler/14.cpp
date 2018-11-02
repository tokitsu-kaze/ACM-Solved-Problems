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
ll gao(ll n)
{
	ll res=0;
	while(n>1)
	{
		if(n&1) n=n*3+1;
		else n>>=1;
		res++;
	}
	return res;
}
int main()
{
	PLL ans=MP(0,0);
	for(ll i=1;i<=1000000;i++)
	{
		ans=max(ans,MP(gao(i),i));
	}
	printf("%lld\n",ans.se);
	return 0;
}
/*

837799

*/