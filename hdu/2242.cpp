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
const int MAX=1e4+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
namespace Tarjan
{
	int bcc,top,tot,n;
	vector<int> mp[MAX];
	vector<PII > bridge;
	int low[MAX],dfn[MAX],belong[MAX],fa[MAX];
	int stk[MAX];
	int cut[MAX],add_block[MAX];
	int val[MAX],v[MAX];
	void dfs(int x,int pre)
	{
		int to,i,tmp,k,son;
		stk[top++]=x;
		low[x]=dfn[x]=++tot;
		fa[x]=pre;
		son=k=0;
		for(auto to:mp[x])
		{
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
				if(low[to]>dfn[x]) bridge.pb(MP(x,to));
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
	void work(int _n,vector<int> e[])
	{
		n=_n;
		for(int i=1;i<=n;i++)
		{
			mp[i]=e[i];
			low[i]=dfn[i]=fa[i]=stk[i]=0;
			cut[i]=add_block[i]=0;
			v[i]=0;
		}
		bcc=top=tot=0;
		bridge.clear();
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i]) dfs(i,i);
		}
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
	        v[belong[i]]+=val[i];
	    }
	}
}
VI mp[MAX];
int dp[MAX],s,ans;
void dfs(int x,int fa)
{
	dp[x]=Tarjan::v[x];
	for(auto to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		dp[x]+=dp[to];
	}
	ans=min(ans,abs(dp[x]-(s-dp[x])));
}
int main()
{
	int n,m,i,a,b;
	while(~scanf("%d%d",&n,&m))
	{
		s=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&Tarjan::val[i]);
			s+=Tarjan::val[i];
			mp[i].clear();
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			a++;
			b++;
			mp[a].pb(b);
			mp[b].pb(a);
		}
		Tarjan::work(n,mp);
		if(Tarjan::bcc==1)
		{
			puts("impossible");
			continue;
		}
		Tarjan::rebuild(mp);
		ans=INF;
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
