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
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int n,k,a[MAX];
int ck(ll x)
{
	int i;
	ll res=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]<=x) continue;
		// t*k+x-t>=a[i]
		// (a[i]-x)/(k-1)<=t
		if(k==1) res+=a[i];
		else res+=(a[i]-x+k-2)/(k-1);
	}
	return res<=x;
}
void go()
{
	int i;
	ll l,r,mid;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		scanf("%d",&k);
		l=0;
		r=1e14;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		printf("%lld\n",l);
	}
}
