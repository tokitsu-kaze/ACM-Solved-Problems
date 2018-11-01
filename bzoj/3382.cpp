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
void go()
{
	int n,i,mx[2],mn[2],x,y;
	while(~scanf("%d",&n))
	{
		mem(mx,0);
		mem(mn,0x3f);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			mx[0]=max(mx[0],x+y);
			mx[1]=max(mx[1],x-y);
			mn[0]=min(mn[0],x+y);
			mn[1]=min(mn[1],x-y);
		}
		printf("%d\n",max(mx[0]-mn[0],mx[1]-mn[1]));
	}
}