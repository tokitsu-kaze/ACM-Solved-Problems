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
/***************************************  head  **********************************************/
namespace Tarjan
{
	int bcc,top,tot,n;
	vector<int> mp[MAX];
	int low[MAX],dfn[MAX],belong[MAX],fa[MAX];
	int stk[MAX];
	void dfs(int x,int pre)
	{
		int to,i,temp,k;
		stk[top++]=x;
		low[x]=dfn[x]=++tot;
		fa[x]=pre;
		k=0;
		for(auto to:mp[x])
		{
			if(to==pre&&!k)
			{
				k++;
				continue;
			}
			if(!low[to])
			{
				dfs(to,x);
				low[x]=min(low[x],low[to]);
			}
			else low[x]=min(low[x],dfn[to]);
		}
		if(low[x]==dfn[x])
		{
			bcc++;
			do
			{
				temp=stk[--top];
				belong[temp]=bcc;
			}while(temp!=x);
		}
	}
	void work(int _n,vector<int> e[])
	{
		n=_n;
		for(int i=1;i<=n;i++)
		{
			mp[i]=e[i];
			low[i]=dfn[i]=fa[i]=stk[i]=0;
		}
		bcc=top=tot=0;
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
	    }
	}
}
int Tree_Diameter(const vector<int> e[])
{
    static int h[MAX];
    int mx,rt;
    function<void(int,int)> dfs=[&](int x,int fa)
	{
		h[x]=h[fa]+1;
        for(auto to:e[x])
        {
			if(to==fa) continue;
            dfs(to,x);
        }
        if(h[x]>mx)
		{
            mx=h[x];
            rt=x;
        }
    };
    mx=rt=-1;
    dfs(1,0);
    dfs(rt,0);
    return mx;
}
vector<int> mp[MAX];
int main()
{
	int n,m,i,a,b;
	while(~scanf("%d%d",&n,&m)&&n+m)
	{
		for(i=1;i<=n;i++) mp[i].clear();
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		Tarjan::work(n,mp);
		Tarjan::rebuild(mp);
		printf("%d\n",Tarjan::bcc-1-(Tree_Diameter(mp)-1));
	}
	return 0;
}
