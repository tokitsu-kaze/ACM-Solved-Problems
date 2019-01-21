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
struct Bron_Kerbosch
{
	static const int N=130;
	bitset<N> MASK,ZERO,mp[N],max_clique;
	int n,cnt_clique;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].reset();
		ZERO.reset();
		MASK=ZERO;
		MASK.flip();
	}
	void add_edge(int a,int b) //0~n-1 , undir
	{
		if(a==b) return;
		mp[a][b]=mp[b][a]=1;
	}
	void dfs(bitset<N> now,bitset<N> some,bitset<N> none)
	{
		if(some.none()&&none.none())
		{
			cnt_clique++;
			return;
		}
		if(cnt_clique>1000) return;
		bitset<N> r=some;
		bool fi=1;
		for(int i=0;i<n;i++)
		{
			if(!r[i]) continue;
			if(fi)
			{
				fi=0;
				r&=mp[i]^MASK;
			}
			now[i]=1;
			dfs(now,some&mp[i],none&mp[i]);
			now[i]=0;
			some[i]=0;
			none[i]=1;
		}
	}
	int count_clique()
	{
		cnt_clique=0;
		bitset<N> now;
		dfs(now,MASK,ZERO);
		return cnt_clique;
	}
}bk;
void go()
{
	int n,m,i,a,b;
	while(~scanf("%d%d",&n,&m))
	{
		bk.init(n);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			bk.add_edge(a-1,b-1);
		}
		int ans=bk.count_clique();
		if(ans>1000) puts("Too many maximal sets of friends.");
		else printf("%d\n",ans);
	}
}
