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
const int MAX=2e4+10;
const ll mod=1e9+7;

int ck(int x, vector<int>& nums, int k)
{
	int i,j,res;
    int n=sz(nums);
	res=0;
	for(i=0,j=0;i<n;i++)
	{
		while(j<sz(nums)&&nums[j]-nums[i]<=x) j++;
		res+=j-i-1;
	}
	return res>=k;
}

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
		int l,r,mid;
        sort(all(nums));
		l=0;
		r=nums.back()-nums[0];
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid,nums,k)) r=mid;
			else l=mid+1;
		}
		return l;
    }
};
