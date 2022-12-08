/*************  debug end  *************/
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
typedef vector<PLL > VPLL;
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
const int MAX=3e5+10;
const ll mod=1e9+7;

VI mp[MAX];
int flag[MAX],ans,dis[MAX],now;
void dfs(int x,int d)
{
	if(flag[x]) return;
	flag[x]=2;
	dis[x]=d;
	for(auto to:mp[x])
	{
		if(flag[to]==2)
		{
			ans=max(ans,d-dis[to]+1);
			continue;
		}
		dfs(to,d+1);
	}
	flag[x]=1;
}
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int i;
		for(i=0;i<sz(edges);i++)
		{
			mp[i].clear();
			flag[i]=0;
			dis[i]=0;
		}
		for(i=0;i<sz(edges);i++)
		{
			if(edges[i]==-1) continue;
			mp[i].pb(edges[i]);
		}
		ans=-1;
		for(i=0;i<sz(edges);i++) dfs(i,0);
		return ans;
    }
};
