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
const int MAX=1e5+10;
const ll mod=1e9+7;

VI mp[MAX];
int degree[MAX];

bool topsort(int n,VI &toplist)
{
	int i,x;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(!degree[i]) q.push(i);
	}
	toplist.clear();
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		toplist.pb(x);
		for(auto to:mp[x])
		{
			degree[to]--;
			if(!degree[to]) q.push(to);
		}
	}
    println(toplist);
	return (sz(toplist)==n);
}

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        int i,j;
        VI x,y;
        vector<vector<int>> res;
		for(i=1;i<=k;i++)
		{
			mp[i].clear();
			degree[i]=0;
		}
		for(auto it:rowConditions)
		{
			mp[it[0]].pb(it[1]);
			degree[it[1]]++;
		}
		if(!topsort(k,x)) return res;
		for(i=1;i<=k;i++)
		{
			mp[i].clear();
			degree[i]=0;
		}
		for(auto it:colConditions)
		{
			mp[it[0]].pb(it[1]);
			degree[it[1]]++;
		}
		if(!topsort(k,y)) return res;
		VI tmp;
		for(i=0;i<k;i++) tmp.pb(0);
		for(i=0;i<k;i++) res.pb(tmp);
		for(i=0;i<k;i++) res[i][0]=x[i];
        
		for(i=0;i<k;i++)
		{
			for(j=0;j<k;j++)
			{
				if(res[i][0]==y[j]&&j)
				{
					res[i][j]=res[i][0];
					res[i][0]=0;
				}
			}
		}
		return res;
    }
};
