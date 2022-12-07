#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<string> VS;
/************* define end  *************/
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
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
		int i,j,ans,s1,s2,ta,tb;
		sort(all(nums1));
		sort(all(nums2));
		s1=s2=ans=0;
		for(auto &it:nums1) s1+=it;
		for(auto &it:nums2) s2+=it;
		if(s1>s2)
		{
			swap(nums1,nums2);
			swap(s1,s2);
		}
		i=0;
		j=sz(nums2)-1;
		while(1)
		{
			if(s1>=s2) break;
			if(i==sz(nums1) && j<0) break;
			ta=tb=0;
			
			if(i<sz(nums1) && j>=0)
			{
				ta=6-nums1[i];
				tb=nums2[j]-1;
				if(ta>=tb)
				{
					s1+=ta;
					i++;
				}
				else
				{
					s2-=tb;
					j--;
				}
			}
			else if(i<sz(nums1))
			{
				s1+=6-nums1[i];
				i++;
			}
			else if(j>=0)
			{
				s2-=nums2[j]-1;
				j--;
			}
			else break;
			ans++;
		}
		if(s1<s2) return -1;
		return ans;
    }
};
