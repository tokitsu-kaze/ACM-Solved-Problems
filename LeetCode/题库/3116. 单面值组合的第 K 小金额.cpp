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
ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}
ll ans;
void dfs(int pos,vector<int>& coins,ll x,ll now,int f)
{
	if(now>x) return;
	if(pos==sz(coins))
	{
		ans+=(x/now)*f;
		return;
	}
	ll g=gcd(now,coins[pos]);
	if(now/g<=ll(2e18)/coins[pos]) dfs(pos+1,coins,x,now/g*coins[pos],f*(-1));
	dfs(pos+1,coins,x,now,f);
}
int ck(ll x,vector<int>& coins,int k)
{
	ans=0;
	dfs(0,coins,x,1,1);
	return ans+k<=x;
}
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        ll l,r,mid;
        l=0;
        r=1e18;
        while(l<r)
        {
        	mid=(l+r)>>1;
        	if(ck(mid,coins,k)) r=mid;
        	else l=mid+1;
		}
		return l;
    }
};
