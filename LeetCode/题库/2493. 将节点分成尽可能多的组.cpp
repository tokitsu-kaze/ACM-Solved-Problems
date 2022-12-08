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
const int MAX=500+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct dsu
{
	int pre[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++) pre[i]=i;
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			return 1;
		}
		return 0;
	}
}dsu;

VI mp[MAX];
int h[MAX],now,flag[MAX];
void bfs(int x)
{
	queue<int> q;
	q.push(x);
	flag[x]=1;
	h[x]=1;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		now=max(now,h[x]);
		for(auto to:mp[x])
		{
			if(h[to]==-1) h[to]=h[x]+1;
			if(h[to]==h[x]-1) continue;
			if(h[to]!=h[x]+1)
			{
				now=-1;
				return;
			}
			if(!flag[to])
			{
				q.push(to);
				flag[to]=1;
			}
		}
	}
}
class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        int i;
        for(i=1;i<=n;i++)
        {
        	mp[i].clear();
		}
		dsu.init(n);
		for(auto &it:edges)
		{
			mp[it[0]].pb(it[1]);
			mp[it[1]].pb(it[0]);
			dsu.merge(it[0],it[1]);
		}
		int res[MAX];
		mem(res,-1);
		for(i=1;i<=n;i++)
		{
			mem(h,-1);
			mem(flag,0);
			h[0]=0;
			now=0;
			bfs(i);
			if(now==-1) return -1;
			else res[dsu.find(i)]=max(res[dsu.find(i)],now);
		}
		int ans=0;
		for(i=1;i<=n;i++)
		{
			if(res[i]!=-1) ans+=res[i];
		}
		return ans;
    }
};
