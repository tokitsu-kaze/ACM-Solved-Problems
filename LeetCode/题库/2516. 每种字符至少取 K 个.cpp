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
    int takeCharacters(string s, int k) {
    	int l,r,mid,cnt[5],i,j,ok;
    	l=0;
    	r=sz(s);
    	while(l<r)
    	{
    		mid=(l+r)>>1;
    		mem(cnt,0);
    		ok=0;
    		for(i=0;i<mid;i++) cnt[s[i]-'a']++;
    		if(cnt[0]>=k&&cnt[1]>=k&&cnt[2]>=k) ok=1;
    		j=sz(s)-1;
    		i=mid-1;
    		while(i>=0)
    		{
    			cnt[s[i]-'a']--;
    			i--;
    			cnt[s[j]-'a']++;
    			j--;
    			if(cnt[0]>=k&&cnt[1]>=k&&cnt[2]>=k) ok=1;
			}
			if(ok) r=mid;
			else l=mid+1;
		}
		mem(cnt,0);
		ok=0;
		for(i=0;i<l;i++) cnt[s[i]-'a']++;
		if(cnt[0]>=k&&cnt[1]>=k&&cnt[2]>=k) ok=1;
		j=sz(s)-1;
		i=l-1;
		while(i>=0)
		{
			cnt[s[i]-'a']--;
			i--;
			cnt[s[j]-'a']++;
			j--;
			if(cnt[0]>=k&&cnt[1]>=k&&cnt[2]>=k) ok=1;
		}
		if(ok) return l;
		return -1;
    }
};
