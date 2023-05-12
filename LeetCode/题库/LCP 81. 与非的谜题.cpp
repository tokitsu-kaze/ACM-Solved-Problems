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
class Solution {
public:
    int getNandResult(int k, vector<int>& arr, vector<vector<int>>& operations) {
		int i,j,n,x,t,ans,res=0;
		n=sz(arr);
		set<int> s[32];
		for(i=1;i<=n;i++)
		{
			x=arr[i-1];
			for(j=0;j<k;j++)
			{
				t=(x>>j)&1;
				if(t==0) s[j].insert(i);
			}
		}
		for(auto &it:operations)
		{
			if(it[0]==0)
			{
				x=arr[it[1]];
				for(j=0;j<k;j++)
				{
					if(((x>>j)&1)==((it[2]>>j)&1)) continue;
					if(((x>>j)&1)==0) s[j].erase(it[1]+1);
					if(((it[2]>>j)&1)==0) s[j].insert(it[1]+1);
				}
				arr[it[1]]=it[2];
			}
			else
			{
				ans=0;
				for(j=0;j<k;j++)
				{
					if(sz(s[j])==0)
					{
						t=(it[2]>>j)&1;
						t=(t+1ll*n*it[1])&1;
						if(t) ans^=(1<<j);
					}
					else if((*s[j].rbegin())==n)
					{
						ans^=(1<<j);
					}
					else
					{
						t=1;
						t=(t+(n-*s[j].rbegin()))&1;
						if(t) ans^=(1<<j);
					}
				}
				res^=ans;
	//			printf("%d\n",ans);
			}
		}
		return res;
    }
};

