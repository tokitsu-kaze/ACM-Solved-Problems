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
const int MAX=1e4+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
const int DIG=22+2;
ll dp[DIG][205];
ll gao(string x,int l,int r)
{
	memset(dp,-1,sizeof dp);
	const int base=10;
	int p[DIG],tot=0;
	reverse(all(x));
	while(tot<sz(x))
	{
		p[tot]=x[tot]-'0';
		tot++;
	}
	function<ll(int,int,int,int)> dfs=[&](int pos,int lead,int sta,int limt)->ll
	{
		if(sta>r) return 0;
		if(pos==-1) return sta>=l&&sta<=r;
		if(!limt&&!lead&&dp[pos][sta]!=-1) return dp[pos][sta];
		ll res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			res+=dfs(pos-1,lead&&i==0&&pos,sta+i,limt&&i==p[pos]);
			if(res>=mod) res-=mod;
		}
		if(!limt&&!lead) dp[pos][sta]=res;
		return res;
	};
	return dfs(tot-1,1,0,1);
}
class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
    	if(num1.back()>'0') num1.back()--;
    	else
    	{
    		reverse(all(num1));
    		for(auto &it:num1)
    		{
    			if(it=='0') it='9';
    			else
    			{
    				it--;
    				break;
				}
			}
			if(num1.back()=='0') num1.pop_back();
			reverse(all(num1));
		}
	//	cout<<num1<<" "<<num2<<endl;
        return (gao(num2,min_sum,max_sum)-gao(num1,min_sum,max_sum)+mod)%mod;
    }
};
