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
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
		priority_queue<PII > sell,buy;
		for(auto &it:orders)
		{
			if(it[2]==0)
			{
				while(it[1]>0 && sz(sell) && -sell.top().fi<=it[0])
				{
					PII tmp=sell.top();
					sell.pop();
					if(tmp.se<=it[1]) it[1]-=tmp.se;
					else
					{
						tmp.se-=it[1];
						it[1]=0;
						sell.push(tmp);
					}
				}
				if(it[1]>0) buy.push(MP(it[0],it[1]));
			}
			else
			{
				while(it[1]>0 && sz(buy) && buy.top().fi>=it[0])
				{
					PII tmp=buy.top();
					buy.pop();
					if(tmp.se<=it[1]) it[1]-=tmp.se;
					else
					{
						tmp.se-=it[1];
						it[1]=0;
						buy.push(tmp);
					}
				}
				if(it[1]>0) sell.push(MP(-it[0],it[1]));
			}
		}
		ll ans=0;
		while(!buy.empty())
		{
			ans=(ans+buy.top().se)%mod;
			buy.pop();
		}
		while(!sell.empty())
		{
			ans=(ans+sell.top().se)%mod;
			sell.pop();
		}
		return ans;
    }
};
