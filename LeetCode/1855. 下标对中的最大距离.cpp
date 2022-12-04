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
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i,j;
        int ans=0;
        for(j=sz(nums2)-1,i=sz(nums1)-1;~j;j--)
        {
            while(i>=0&&nums1[i]<=nums2[j]) i--;
            if(i<sz(nums1)-1) i++;
            if(nums1[i]<=nums2[j]) ans=max(ans,j-i);
        }
        return ans;
    }
};
