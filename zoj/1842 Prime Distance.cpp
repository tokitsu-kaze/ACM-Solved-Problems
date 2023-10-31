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
const int MAX=1e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
ll p[MAX],tot;
bool flag[MAX],prime[MAX];
void init(ll l,ll r)
{
	ll i,j,sq=sqrt(r+0.5);
	tot=0;
	for(i=0;i<=sq;i++) flag[i]=1;
	for(i=l;i<=r;i++) prime[i-l]=1;
	if(l==0) prime[0]=prime[1]=0;
	if(l==1) prime[0]=0;
	for(i=2;i<=sq;i++)
    {
		if(!flag[i]) continue;
    	for(j=i+i;j<=sq;j+=i) flag[j]=0;
        for(j=max(2LL,(l+i-1)/i)*i;j<=r;j+=i) prime[j-l]=0;
    }
    for(i=l;i<=r;i++)
    {
		if(prime[i-l]) p[tot++]=i;
	}
}
void go()
{
	ll l,r,mn,mx,mnl,mnr,mxl,mxr,i;
	while(~scanf("%lld%lld",&l,&r))
	{
		init(l,r);
		if(tot<=1)
		{
			puts("There are no adjacent primes.");
			continue;
		}
		mn=LLINF;
		mx=-LLINF;
		for(i=1;i<tot;i++)
		{
			if(mn>p[i]-p[i-1])
			{
				mn=p[i]-p[i-1];
				mnl=p[i-1];
				mnr=p[i];
			}
			if(mx<p[i]-p[i-1])
			{
				mx=p[i]-p[i-1];
				mxl=p[i-1];
				mxr=p[i];
			}
		}
		printf("%lld,%lld are closest, %lld,%lld are most distant.\n",mnl,mnr,mxl,mxr);
	}
}
