#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <bitset>
#include <limits>
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll g,t;
	g=exgcd(b,a%b,x,y);
	t=x;
	x=y;
	y=t-a/b*y;
	return g;
}
namespace exCRT
{
	ll excrt(VL a,VL b)//res=a_i(mod b_i)
	{
	    ll x,y,k,g,c,p,res,bg;
	    assert(sz(a)==sz(b));
	    assert(sz(a)>0);
	    p=b[0];
		res=a[0];
	    for(int i=1;i<sz(a);i++)
	    {
	        c=(a[i]-res%b[i]+b[i])%b[i];
	        g=exgcd(p,b[i],x,y);
			bg=b[i]/g;
	        if(c%g!=0) return -1;
	        x=(x*(c/g))%bg;
	        res+=x*p;
	        p*=bg;
	        res=(res%p+p)%p;
	    }
	    return (res%p+p)%p;
	}
};
void go()
{
	int n,i;
	ll x,y;
	while(~scanf("%d",&n))
	{
		VL a,b;
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&x,&y);
			a.pb(y);
			b.pb(x);
		}
		printf("%lld\n",exCRT::excrt(a,b));
	}
}
