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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e4+10;
const ll mod=1e9+7;

int dp[MAX];

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        mem(dp,0x3f);
        int i;
        dp[0]=0;
        for(i=1;i<=amount;i++)
        {
            for(auto it:coins)
            {
                if(i-it>=0) dp[i]=min(dp[i-it]+1,dp[i]);
            }
        }
        if(dp[amount]==INF) return -1;
        return dp[amount];
    }
};
