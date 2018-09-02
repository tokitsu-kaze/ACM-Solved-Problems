#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int MAX=5e4+10;
const ll mod=1e9+7;
/*
ull llrand()
{
	return (
	(((ull)rand()<<24)&0xFF000000ul)|
	(((ull)rand()<<12)&0x00FFF000ul)|
	(((ull)rand()    )&0x00000FFFul));
}
int main()
{
	srand(time(0));
	freopen("in.txt","w",stdout);
	int t=40,i,n,x;
	printf("%d\n",t);
	while(t--)
	{
		
		n=(int)(llrand()%(MAX-10))+1;
		x=(int)(llrand()%n)+1;
		printf("%d %d %d\n",n,(int)(llrand()%n)+1,(int)(llrand()%n)+1);
		vector<PII > res;
		for(i=1;i<=n;i++) res.pb(MP((int)(llrand()%mod),i));
		sort(all(res));
		for(i=1;i<sz(res);i++)
		{
			int temp=llrand()%i;
			printf("%d %d\n",res[temp].se,res[i].se);
		}
	}
	return 0;
}
*/

vector<int> mp[MAX];
int sz[MAX];
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
void dfs(int x,int pre)
{
	int i,to;
	sz[x]=1;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==pre) continue;
		dfs(to,x);
		sz[x]+=sz[to];
	}
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,i,a,b,t,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&x,&y);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<=n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		dfs(x,0);
		printf("%lld\n",pow2(2,sz[y]-1));
	}
	return 0;
}
/*
2
3 1 1
1 2
1 3
5 2 3
1 2
1 3
2 4
3 5
*/