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
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
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
const int MAX=1e5+10;
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
ll linear_equation(ll a,ll b,ll c,ll &x,ll &y)
{
	ll g,t;
	g=exgcd(a,b,x,y);
	if(!c) x=y=0;
	else if((!a&&!b&&c)||c%g) return -1;//no solution 
	else if(!a&&b) x=1,y=c/b;
	else if(a&&!b) x=c/a,y=-c/a;
	else
	{
		a/=g,b/=g,c/=g;
		x*=c,y*=c;
		t=x;
		x%=b;
		if(x<=0) x+=b;
		ll k=(t-x)/b;
		y+=k*a;
	}
	return g;
}
void go()
{
	ll x,y,m,n,L,g,a,b,c,ra,rb;
	while(~scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L))
	{
		a=m-n;
		b=L;
		c=y-x;
		if(a<0) a=-a,c=-c;
		g=linear_equation(a,b,c,ra,rb);
		if(g==-1) puts("Impossible");
		else printf("%lld\n",ra);
	}
}
