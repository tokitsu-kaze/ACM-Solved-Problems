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

int flag[MAX];
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	int i,j;
		mem(flag,0);
        sort(all(nums));
		for(auto it:nums) flag[it+100000]++;
		vector<VI > res;
		set<PII > s;
		for(i=0;i<sz(nums);i++)
		{
			flag[nums[i]+100000]--;
            if(i>0&&nums[i]==nums[i-1]) continue;
			for(j=i+1;j<sz(nums);j++)
			{
				flag[nums[j]+100000]--;
                if(j>i+1&&nums[j]==nums[j-1]) continue;
				if(100000-(nums[i]+nums[j])>=0&&100000-(nums[i]+nums[j])<MAX)
				{
					if(flag[100000-(nums[i]+nums[j])])
					{
						VI tmp=VI{nums[i],nums[j],-(nums[i]+nums[j])};
						sort(all(tmp));
						if(!s.count(MP(tmp[0],tmp[1])))s.insert(MP(tmp[0],tmp[1]));
					}
				}
			}
			for(j=i+1;j<sz(nums);j++) flag[nums[j]+100000]++;
		}
		for(auto it:s) res.pb(VI{it.fi,it.se,-(it.fi+it.se)});
		return res;
    }
};
