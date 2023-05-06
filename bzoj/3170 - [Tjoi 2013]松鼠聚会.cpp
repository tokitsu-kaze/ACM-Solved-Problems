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
int x[MAX],y[MAX];
int nx[MAX],ny[MAX];
ll bitx[MAX],bity[MAX];
void go()
{
	int n,i,px,py;
	ll ans;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
		for(i=1;i<=n;i++)
		{
			nx[i]=x[i]+y[i];
			ny[i]=x[i]-y[i];
		}
		sort(nx+1,nx+1+n);
		sort(ny+1,ny+1+n);
		bitx[0]=bity[0]=0;
		for(i=1;i<=n;i++)
		{
			bitx[i]=bitx[i-1]+nx[i];
			bity[i]=bity[i-1]+ny[i];
		}
		ans=LLINF;
		for(i=1;i<=n;i++)
		{
			px=lower_bound(nx+1,nx+1+n,x[i]+y[i])-nx;
			py=lower_bound(ny+1,ny+1+n,x[i]-y[i])-ny;
			ans=min(ans,1LL*px*(x[i]+y[i])-bitx[px]+
						(bitx[n]-bitx[px])-1LL*(n-px)*(x[i]+y[i])+
						1LL*py*(x[i]-y[i])-bity[py]+
						(bity[n]-bity[py])-1LL*(n-py)*(x[i]-y[i]));
		}
		printf("%lld\n",ans/2);
	}
}