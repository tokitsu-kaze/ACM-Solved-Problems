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

class Solution {
public:
    int minDistance(string word1, string word2) {
		int i,j,res;
		vector<VI > dp(sz(word1)+1,VI (sz(word2)+1,0));
		res=0;
		for(i=0;i<sz(word1);i++)
		{
			for(j=0;j<sz(word2);j++)
			{
				if(word1[i]==word2[j]) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
				else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
				res=max(res,dp[i+1][j+1]);
			}
		}
		return sz(word1)+sz(word2)-2*res;
    }
};
