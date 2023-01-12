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
    bool isItPossible(string word1, string word2) {
        int cnt1[333],cnt2[333];
        mem(cnt1,0);
        mem(cnt2,0);
        for(auto &ch:word1) cnt1[ch]++;
        for(auto &ch:word2) cnt2[ch]++;
        int ra,rb,i,j,ta,tb;
        ra=rb=0;
        for(i=0;i<256;i++) ra+=(cnt1[i]>0);
        for(i=0;i<256;i++) rb+=(cnt2[i]>0);
    	for(i=0;i<256;i++)
    	{
    		if(cnt1[i]==0) continue;
    		for(j=0;j<256;j++)
    		{
    			if(cnt2[j]==0) continue;
    			if(i==j)
    			{
    				if(ra==rb) return true;
    				continue;
				}
    			ta=ra;
    			tb=rb;
    			if(cnt2[i]==0) tb++;
    			if(cnt1[i]==1) ta--;
    			
    			if(cnt1[j]==0) ta++;
    			if(cnt2[j]==1) tb--;
    			
    			if(ta==tb) return true;
			}
		}
		return false;
    }
};
