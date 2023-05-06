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
vector<int> mp[MAX];
int lk[MAX],used[MAX];
int dfs(int x,int tag)
{
	int i,to;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(used[to]<tag)
		{
			used[to]=tag;
			if(lk[to]==-1||dfs(lk[to],tag))
			{
				lk[to]=x;
				return 1;
			}
		}
	}
	return 0;
}
void go()
{
	int n,i,a,b,ans;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=10000;i++) mp[i].clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(i);
			mp[b].pb(i);
		}
		ans=0;
		mem(lk,-1);
		mem(used,0);
		for(i=1;i<=10000;i++)
		{
			if(dfs(i,i)) ans++;
			else break;
		}
		printf("%d\n",ans);
	}
}
