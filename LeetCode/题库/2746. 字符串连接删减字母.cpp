#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VS> VVS;
typedef vector<VPII> VVPII;
/************* define end  *************/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/********* gp_hash_table end  **********/
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
    int minimizeConcatenatedLength(vector<string>& words) {
        int i,j,k,f,x,y;
        int dp[2][26][26],ans;
        f=0;
        mem(dp[f],0x3f);
        dp[f][words[0][0]-'a'][words[0].back()-'a']=sz(words[0]);
        for(i=1;i<sz(words);i++)
        {
        	x=words[i][0]-'a';
        	y=words[i].back()-'a';
        	f^=1;
        	mem(dp[f],0x3f);
        	for(j=0;j<26;j++)
        	{
        		for(k=0;k<26;k++)
        		{
        			dp[f][j][y]=min(dp[f][j][y],dp[f^1][j][k]+sz(words[i])-(x==k));
        			dp[f][x][k]=min(dp[f][x][k],dp[f^1][j][k]+sz(words[i])-(y==j));
				}
			}
		}
		ans=INF;
		for(i=0;i<26;i++)
		{
			for(j=0;j<26;j++)
			{
				ans=min(ans,dp[f][i][j]);
			}
		}
		return ans;
    }
};
