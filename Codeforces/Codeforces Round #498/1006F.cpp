#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=2e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
ll mp[33][33],ans,k;
map<ll,ll> cnt[33][33];
int n,m,limt;
void dfs1(int x,int y,ll now,int len)
{
	if(x<1||y<1||x>n||y>m) return;
	if(len==limt)
	{
		now^=mp[x][y];
		cnt[x][y][now]++;
//		cout<<x<<" "<<y<<" "<<now<<endl;
		return;
	}
	dfs1(x+1,y,now^mp[x][y],len+1);
	dfs1(x,y+1,now^mp[x][y],len+1);
}
void dfs2(int x,int y,ll now,int len)
{
	if(x<1||y<1||x>n||y>m) return;
	if(len==limt+1)
	{
		ans+=cnt[x][y][k^now];
	//	cout<<x<<" "<<y<<" "<<(now^k)<<endl;
		return;
	}
	dfs2(x-1,y,now^mp[x][y],len+1);
	dfs2(x,y-1,now^mp[x][y],len+1);
}
int main()
{
	int i,j;
	while(~scanf("%d%d%lld",&n,&m,&k))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%lld",&mp[i][j]);
				cnt[i][j].clear();
			}
		}
		if(n==1&&m==1)
		{
			if(mp[1][1]==k) puts("1");
			else puts("0");
			continue;
		}
		ans=0;
		limt=(n+m-1)/2;
		dfs1(1,1,0,1);
//		puts("**");
		limt=(n+m-1)-limt;
		dfs2(n,m,0,1);
		printf("%lld\n",ans);
	}
	return 0;
}