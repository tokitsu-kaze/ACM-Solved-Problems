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
const int MAX=1e4+10;
const ll mod=1e9+7;

int bitadd[MAX],bitdes[MAX];
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    	mem(bitadd,0);
    	mem(bitdes,0);
		for(auto it:intervals)
		{
			bitadd[it[0]]++;
			bitdes[it[1]+1]--;
		}
		vector<vector<int>> res;
		int l,r,now;
		l=-1;
		now=0;
		for(int i=0;i<MAX;i++)
		{
			now+=bitdes[i];
			if(now)
			{
				if(l==-1) l=i;
				r=i;
			}
			else
			{
				if(l!=-1)
				{
					res.pb(VI{l,r});
					l=-1;
				}
			}
			now+=bitadd[i];
			if(now)
			{
				if(l==-1) l=i;
				r=i;
			}
			else
			{
				if(l!=-1)
				{
					res.pb(VI{l,r});
					l=-1;
				}
			}
		}
		return res;
    }
};
