#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<string> VS;
/************* define end  *************/
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct dominator_tree
{
	int n,tot,dfn[MAX],best[MAX],semi[MAX],idom[MAX],id[MAX],fa[MAX];
	VI nex[MAX],pre[MAX],tmp[MAX],son[MAX];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++)
		{
			nex[i].clear();
			pre[i].clear();
			tmp[i].clear();
			son[i].clear();
			dfn[i]=0; 
			idom[i]=semi[i]=best[i]=fa[i]=i;
		}
	}
	void add_edge(int x,int y)
	{
	//	printf("%d %d\n",x,y);
		nex[x].pb(y);
		pre[y].pb(x);
	}
	int ckmin(int x,int y){return dfn[semi[x]]<dfn[semi[y]]?x:y;}
	int getfa(int k)
	{
		if(k==fa[k]) return k;
		int ret=getfa(fa[k]);
		best[k]=ckmin(best[fa[k]],best[k]);
		return fa[k]=ret;
	}
	void dfs(int x)
	{
		dfn[x]=++tot;
		id[tot]=x;
		for(auto to:nex[x])
		{
			if(dfn[to]) continue;
			dfs(to);
			son[x].pb(to);
		}
	}
	void tarjan(VI mp[])
	{
		int i,j,k;
		for(i=tot;i;i--)
		{
			k=id[i];
			for(auto to:pre[k])
			{
				if(!dfn[to]) continue;
				if(dfn[to]<dfn[k])
				{
					if(dfn[to]<dfn[semi[k]]) semi[k]=to;
				}
				else
				{
					getfa(to);
					semi[k]=semi[ckmin(best[to],k)];
				}
			}
			if(k!=semi[k]) tmp[semi[k]].pb(k);
			for(auto to:tmp[k])
			{
				getfa(to);
				if(semi[best[to]]==k) idom[to]=k;
				else idom[to]=best[to];
			}
			for(auto to:son[k]) fa[to]=k;
		}
		for(i=2;i<=tot;i++)
		{
			k=id[i];
			if(idom[k]!=semi[k]) idom[k]=idom[idom[k]];
			if (k!=idom[k])
			{
				mp[idom[k]].pb(k);  //add edge
				
			}
		}
	}
	void work(int rt,VI mp[])
	{
		for(int i=0;i<=n;i++) mp[i].clear();
		tot=0;
		dfs(rt);
		tarjan(mp);
	}
}dt;
int n,m;
VI mp[MAX];
int getid(int x,int y)
{
	return (x-1)*m+y;
}

void dfs(int x)
{
	printf("%d\n",x);
	for(auto &to:mp[x]) printf("%d ",to);
	puts("");
	for(auto &to:mp[x]) dfs(to);
}

class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
    	int i,j;
    	n=sz(grid);
    	m=sz(grid[0]);
        if(n==1&&m==1) return false;
        dt.init(n*m);
        for(i=1;i<=n;i++)
        {
        	for(j=1;j<=m;j++)
        	{
        		if(grid[i-1][j-1]==0) continue;
				if(i<n&&grid[i][j-1]) dt.add_edge(getid(i+1,j),getid(i,j));
				if(j<m&&grid[i-1][j]) dt.add_edge(getid(i,j+1),getid(i,j));
			}
		}
		int rt=n*m;
		dt.work(rt,mp);
	//	dfs(rt);
		for(auto to:mp[rt])
		{
			if(to==1) return false;
		}
		return true;
    }
};
