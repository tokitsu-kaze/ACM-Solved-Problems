#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
int cnt,flag[MAX],res[MAX];
vector<int> mp[MAX];
void dfs(int x,int pre,int col)
{
	int i;
	if(flag[x]) return;
	flag[x]=col;
	for(i=0;i<sz(mp[x]);i++)
	{
		if(mp[x][i]==pre) continue;
		dfs(mp[x][i],x,col);
	}
}
int main()
{
	int n,m,i,a,b,tot;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);		
		}
		mem(flag,0);
		tot=0;
		for(i=1;i<=n;i++)
		{
			if(flag[i]) continue;
			tot++;
			dfs(i,0,tot);
		}
		for(i=1;i<=tot;i++) res[i]=1;
		for(i=1;i<=n;i++)
		{
			if(sz(mp[i])!=2) res[flag[i]]=0;
		}
		cnt=0;
		for(i=1;i<=tot;i++) cnt+=res[i];
		printf("%d\n",cnt);
	}
	return 0;
}
/*
3 3
1 2
2 3
3 1

17 7
15 5
5 11
11 9
9 15
7 10
7 16
16 10
*/