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
const int MAX=1e6+10;
const ll mod=1e9+7;

VI mp[MAX];
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int i;
        for(i=1;i<MAX;i++) mp[i].clear();
        for(i=0;i<sz(nums);i++) mp[nums[i]].pb(i);
        for(auto it:operations)
        {
            for(auto it2:mp[it[0]])
            {
                nums[it2]=it[1];
                mp[it[1]].pb(it2);
            }
            mp[it[0]].clear();
        }
        return nums;
    }
};
