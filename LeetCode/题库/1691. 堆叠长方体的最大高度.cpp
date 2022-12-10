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
bool cmp(VI a,VI b)
{
	if(a[0]==b[0]&&a[1]==b[1]) return a[2]<b[2];
	if(a[0]==b[0]) return a[1]<b[1];
	return a[0]<b[0];
}
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
    	for(auto &it:cuboids) sort(all(it));
    	sort(all(cuboids),cmp);
		int i,j,ans;
		int dp[102]={0};
		ans=0;
		for(i=0;i<sz(cuboids);i++)
		{
			dp[i]=cuboids[i][2];
			for(j=0;j<i;j++)
			{
				if(cuboids[j][0]>cuboids[i][0]) continue;
				if(cuboids[j][1]>cuboids[i][1]) continue;
				if(cuboids[j][2]>cuboids[i][2]) continue;
				dp[i]=max(dp[i],dp[j]+cuboids[i][2]);
			}
			ans=max(ans,dp[i]);
		}
		return ans;
    }
};
