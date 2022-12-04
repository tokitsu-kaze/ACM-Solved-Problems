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
const int MAX=2e5+10;
const ll mod=1e9+7;

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int i,j,ok,ook;
        vector<char> mp[333];
        for(i=0;i<333;i++) mp[i].clear();
        for(auto it:mappings) mp[it[0]].pb(it[1]);
		for(i=0;i+sz(sub)-1<sz(s);i++)
		{
			ook=1;
			for(j=i;j<i+sz(sub);j++)
			{
				if(s[j]==sub[j-i]) continue;
				ok=0;
				for(auto it:mp[sub[j-i]])
				{
					if(it==s[j])
					{
						ok=1;
						break;
					}
				}
				if(!ok)
				{
					ook=0;
					break;
				}
			}
			if(ook) return true;
		}
		return false;
    }
};
