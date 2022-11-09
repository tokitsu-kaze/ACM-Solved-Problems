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
const int MAX=2e6+10;
const ll mod=1e9+7;
vector<int> mp[MAX],dag[MAX];
int h[MAX],be,ans,tag[MAX],ans1[3],flag[MAX],m;
void dfs(int x,int pre,int f)
{
	int i,to;
	h[x]=h[pre]+1;
	for(i=0;i<sz(dag[x]);i++)
	{
		to=dag[x][i];
		if(to==pre) continue;
		dfs(to,x,f);
	}
	if(h[x]>ans)
	{
		ans=h[x];
		be=x;
		ans1[f]=x;
	}
	else if(h[x]==ans) ans1[f]=min(ans1[f],x);
}
void gao(int x,int pre)
{
	int i,to;
	flag[x]=tag[x];
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==pre) continue;
		gao(to,x);
		tag[x]+=tag[to];
		if(tag[to]!=m&&flag[to])
		{
			flag[x]=1;
			dag[to].pb(x);
			dag[x].pb(to);
			be=x;
		}
	}
}
void work(int x,int pre)
{
	int i,to;
	cout<<x<<endl;
	for(i=0;i<sz(dag[x]);i++)
	{
		to=dag[x][i];
		if(to==pre) continue;
		work(to,x);
	}
}
int main()
{
	int n,i,a,b;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			dag[i].clear();
			tag[i]=0;
			flag[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d",&a);
			tag[a]=1;
			ans1[0]=a;
		}
		if(m==1)
		{
			printf("%d\n%d\n",ans1[0],0);
			continue;
		}
		gao(1,0);
		
	//	work(be,0);
		
		ans=0;
		h[0]=0;
		dfs(be,0,0);
		ans=0;
		dfs(be,0,1);
		
		
		int cnt=0;
		for(i=1;i<=n;i++)
		{
			cnt+=(flag[i]==1);
		}
		
		
		printf("%d\n%d\n",min(ans1[0],ans1[1]),ans+2*(cnt-ans)-1);
	}
	return 0;
}