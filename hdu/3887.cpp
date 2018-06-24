////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-29 09:49:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3887
////Problem Title: 
////Run result: Accept
////Run time:1216MS
////Run memory:17372KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
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
const int MAX=1e5+10;
const ll mod=1e9+7;
int bit[MAX],n;
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,int v)
{
	while(x<=n)
	{
		bit[x]+=v;
		x+=lowbit(x);
	}
}
int getsum(int x)
{
	int res=0;
	while(x)
	{
		res+=bit[x];
		x-=lowbit(x);
	}
	return res;
}
vector<int> mp[MAX];
int l[MAX],r[MAX],tot;
void dfs(int x,int pre)
{
	int i,to;
	tot++;
	l[x]=tot;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==pre) continue;
		dfs(to,x);
	}
	r[x]=tot;
}
int main()
{
	int rt,i,a,b;
	while(~scanf("%d%d",&n,&rt)&&n+rt)
	{
		mem(bit,0);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		tot=0;
		dfs(rt,-1);
		printf("%d",getsum(r[1])-getsum(l[1]-1));
		update(l[1],1);
		for(i=2;i<=n;i++)
		{
			printf(" %d",getsum(r[i])-getsum(l[i]-1));
			update(l[i],1);
		}
		puts("");
	}
	return 0;
}