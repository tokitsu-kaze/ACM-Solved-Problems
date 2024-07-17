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
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int a[MAX],cnt[MAX];
int ck(int ans,int n)
{
	ll res=0;
	int i,j,now;
	now=0;
	memset(cnt,0,sizeof cnt);
	for(i=1,j=0;i<=n;i++)
	{
		while(j+1<=n)
		{
			if(cnt[a[j+1]])
			{
				j++;
				cnt[a[j]]++;
			}
			else
			{
				if(now+1<=ans)
				{
					now++;
					j++;
					cnt[a[j]]++;
				}
				else break;
			}
		}
	//	cout<<i<<" "<<j<<endl;
		if(now<=ans) res+=j-i+1;
		cnt[a[i]]--;
		if(cnt[a[i]]==0) now--;
	}
//	cout<<res<<endl;
	return res*2>=1LL*n*(n+1)/2;
}
class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int i,l,r,mid;
        for(i=0;i<sz(nums);i++) a[i+1]=nums[i];
        l=1;
        r=sz(nums);
        while(l<r)
        {
        	mid=(l+r)>>1;
        	if(ck(mid,sz(nums))) r=mid;
        	else l=mid+1;
		}
		return l;
    }
};
/*
[15,86,69,20,20,69,86,20,86]
*/
