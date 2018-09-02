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
const double eps=1e-8;
const int MAX=1e3+10;
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
	int t=30,i,n;
	printf("%d\n",t);
	t--;
	n=MAX-10;
	printf("%d\n",n);
	for(i=2;i<=n;i++) printf("%d %d\n",1,i);
	t--;
	n=MAX-10;
	printf("%d\n",n);
	for(i=2;i<=n;i++) printf("%d %d\n",i-1,i);
	while(t--)
	{
		
		n=(int)(llrand()%(MAX-11))+2;
		printf("%d\n",n);
		assert(n<=(int)MAX-10);
		vector<PII > res;
		for(i=1;i<=n;i++) res.pb(MP((int)(llrand()%mod),i));
		sort(all(res));
		for(i=1;i<sz(res);i++)
		{
			int temp=llrand()%i;
			assert(temp!=i);
			printf("%d %d\n",res[temp].se,res[i].se);
		}
	}
	return 0;
}
*/

vector<int> mp[MAX];
int h[MAX],be,ans;
void dfs(int x,int pre)
{
	int i,to;
	h[x]=h[pre]+1;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==pre) continue;
		dfs(to,x);
	}
	if(h[x]>ans)
	{
		ans=h[x];
		be=x;
	}
}
int main()
{
	int t,n,i,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		ans=0;
		h[0]=0;
		dfs(1,0);
		ans=0;
		dfs(be,0);
		printf("%d\n",ans+2*(n-ans)-1);
	}
	return 0;
}
/*
1
6
1 2
1 3
3 4
3 5
3 6


7
2 1 3 5 3 6 3 4
*/