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
    int kthSmallest(vector<vector<int>>& mat, int k) {
		priority_queue<pair<int,VI>> q;
		map<VI,int> mp;
		int i,j,n,m,now;
		n=sz(mat);
		m=sz(mat[0]);
		now=0;
		VI tmp;
		for(i=0;i<n;i++)
		{
			now+=mat[i][0];
			tmp.pb(0);
		}
		q.push({-now,tmp});
		mp[tmp]=1;
		k--;
		while(k--)
		{
			auto t=q.top();
			q.pop();
	//		printf("%d\n",-t.fi);
	//		println(t.se);
			for(i=0;i<n;i++)
			{
				if(t.se[i]+1<m)
				{
					auto nex=t;
					nex.fi=-nex.fi;
					nex.fi-=mat[i][nex.se[i]];
					nex.fi+=mat[i][nex.se[i]+1];
					nex.se[i]++;
					nex.fi=-nex.fi;
					if(!mp.count(nex.se))
					{
						q.push(nex);
						mp[nex.se]=1;
					}
				}
			}
		}
		return -q.top().fi;
    }
};
