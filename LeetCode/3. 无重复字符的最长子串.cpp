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
    int lengthOfLongestSubstring(string s) {
        int i,j,cnt[333],ans;
        mem(cnt,0);
        ans=0;
        for(i=0,j=0;i<sz(s);i++)
        {
            while(j<sz(s))
            {
                if(cnt[s[j]]) break;
                cnt[s[j]]++;
                j++;
            }
            ans=max(ans,j-i);
            cnt[s[i]]--;
        }
        return ans;
    }
};
