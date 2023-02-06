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
int a[MAX],n,m,b[MAX];
ll bit[MAX];
int ck(int x)
{
	int i;
	ll mn;
	bit[0]=0;
	for(i=1;i<=n;i++)
	{
		b[i]=a[i]-x;
		bit[i]=bit[i-1]+b[i];
	}
	mn=LLINF;
	for(i=m;i<=n;i++)
	{
		mn=min(mn,bit[i-m]);
		if(bit[i]-mn>=0) return 1;
	}
	return 0;
}
void go()
{
	int i,l,r,mid;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) a[i]*=10000;
		l=0;
		r=20000000;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1)) l=mid+1;
			else r=mid;
		}
		printf("%d\n",l/10);
	}
}
