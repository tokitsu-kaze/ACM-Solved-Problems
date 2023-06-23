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
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VS> VVS;
typedef vector<VPII> VVPII;
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
const int MAX=400+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Bipartite_Matching
{
	static const int N=200+10;
	static const int M=200+10;
	int n,m;
	vector<int> mp[N];
	int flag[N],s[N],link[M],used[M];
	void init(int _n,int _m)
	{
		n=_n;
		m=_m;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int a,int b){mp[a].push_back(b);}
	bool dfs(int x,int timetag)
	{
		int i,to;
		flag[x]=1;
		for(i=0;i<mp[x].size();i++)
		{
			to=mp[x][i];
			if(used[to]==timetag) continue;
			used[to]=timetag;
			if(link[to]==-1||dfs(link[to],timetag))
			{
				link[to]=x;
				s[x]=to;
				return 1;
			}
		}
		return 0;
	}
	int max_match()
	{
		int i,res;
		memset(link,-1,sizeof link);
		memset(s,-1,sizeof s);
		memset(used,0,sizeof used);
		res=0;
		for(i=1;i<=n;i++)
		{
			if(mp[i].size()==0) continue;
			if(dfs(i,i)) res++;
		}
		return res;
	}
}bpm;
/*
O(n*m)
bpm.init(n,m);
bpm.add_edge(a,b); a:left,1-n   b:right,1-m
*/
void go()
{
	int n,m,k,i,x;
	while(~scanf("%d%d",&n,&m))
	{
		bpm.init(n,m);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d",&x);
				bpm.add_edge(i,x);
			}
		}
		printf("%d\n",bpm.max_match());
	}
}
