#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
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
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int ans;
namespace Tarjan
{
	int bcc,top,tot,n;
	vector<PII > mp[MAX];
	vector<PII > bridge;
	int low[MAX],dfn[MAX],belong[MAX],fa[MAX];
	int stk[MAX];
	int cut[MAX],add_block[MAX];
	void dfs(int x,int pre)
	{
		int to,i,tmp,k,son;
		stk[top++]=x;
		low[x]=dfn[x]=++tot;
		fa[x]=pre;
		son=k=0;
		for(auto it:mp[x])
		{
			to=it.fi;
			if(to==pre&&!k) 
			{
				k++;
				continue;
			}
			if(!dfn[to])
			{
				son++;
				dfs(to,x);
				low[x]=min(low[x],low[to]);
				if(x!=pre&&low[to]>=dfn[x])
				{
					cut[x]=1;
					add_block[x]++;
				}
				if(low[to]>dfn[x]) ans=min(ans,it.se);
			}
			else low[x]=min(low[x],dfn[to]);
		}
		if(x==pre&&son>1)
		{
			cut[x]=1;
			add_block[x]=son-1;
		}
		if(low[x]==dfn[x])
		{
			bcc++;
			do
			{
				tmp=stk[--top];
				belong[tmp]=bcc;
			}while(tmp!=x);
		}
	}
	void work(int _n,vector<PII > e[])
	{
		n=_n;
		for(int i=1;i<=n;i++)
		{
			mp[i]=e[i];
			low[i]=dfn[i]=fa[i]=stk[i]=0;
			cut[i]=add_block[i]=0;
		}
		bcc=top=tot=0;
		bridge.clear();
		dfs(1,1);
	}
	void rebuild(vector<int> e[]) 
	{
		int i,t;
		for(i=1;i<=n;i++) e[i].clear();
	    for(i=1;i<=n;i++)
		{
	        t=fa[i];
	        if(belong[i]!=belong[t])
			{
	            e[belong[i]].pb(belong[t]);
	            e[belong[t]].pb(belong[i]);
	        }
	    }
	}
}
vector<PII > mp[MAX];
int main()
{
	int n,m,i,a,b,w;
	while(~scanf("%d%d",&n,&m)&&n+m)
	{
		for(i=1;i<=n;i++) mp[i].clear();
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&w);
			mp[a].pb(MP(b,w));
			mp[b].pb(MP(a,w));
		}
		ans=INF;
		Tarjan::work(n,mp);
		if(ans==INF) ans=-1;
		if(ans==0) ans=1;
		for(i=1;i<=n;i++)
		{
			if(!Tarjan::dfn[i]) ans=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}
