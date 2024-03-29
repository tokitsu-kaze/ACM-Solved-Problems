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
void go()
{
	int t,n,i;
	ll x,pre;
	scanf("%d",&t);
	while(t--)
	{
		VL res[2];
		scanf("%d",&n);
		pre=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			pre+=x;
			res[0].pb(pre);
		}
		pre=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			pre+=x;
			res[1].pb(pre);
		}
		sort(all(res[0]));
		sort(all(res[1]));
		if(res[0]==res[1]) puts("YES");
		else puts("NO");
	}
}
