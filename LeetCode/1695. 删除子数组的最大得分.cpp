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
const int MAX=1e4+10;
int flag[MAX];
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i,j;
        int ans=0;
        int now=0;
        mem(flag,0);
        for(i=0,j=0;i<sz(nums);i++)
        {
            while(j<i)
            {
                j++;
                now=0;
            }
            while(j<sz(nums))
            {
                if(flag[nums[j]]) break;
                now+=nums[j];
                flag[nums[j]]=1;
                j++;
            }
            ans=max(ans,now);
            now-=nums[i];
            flag[nums[i]]--;
        }
        return ans;
    }
};

