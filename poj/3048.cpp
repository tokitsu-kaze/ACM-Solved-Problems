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
const int MAX=2e4+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int prime[MAX];
void init(int n)
{
	int i,j;
	mem(prime,0);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(prime[i]) continue;
		for(j=i;j<=n;j+=i)
		{
			prime[j]=i;
		}
	}
}
void go()
{
	init(MAX-10);
	int n,i,x,ans;
	while(~scanf("%d",&n))
	{
		ans=0;
		while(n--)
		{
			scanf("%d",&x);
			if(prime[ans]<prime[x]) ans=x;
		}
		printf("%d\n",ans);
	}
}
