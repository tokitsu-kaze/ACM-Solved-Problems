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
    int longestSubsequence(string s, int k) {
        int i,j,kk,ans,now,f;
        string tmp="";
        while(k)
        {
            tmp+='0'+k%2;
            k/=2;
        }
        reverse(all(tmp));
        printf("sz tmp:%d, sz s:%d\n",sz(tmp),sz(s));
        cout<<tmp<<endl;
        ans=0;
        for(auto it:s) ans+=(it=='0');
        for(i=0;i<sz(s);i++)
        {
            now=0;
            f=0;
            for(j=0;j<i;j++) now+=(s[j]=='0');
            for(j=i,kk=0;j<sz(s);j++)
            {
                if(kk<sz(tmp)&&f) kk++;
                if(!f&&kk<sz(tmp)&&s[j]==tmp[kk]) kk++;
                else if(!f&&kk<sz(tmp)&&s[j]<tmp[kk])
                {
                    f=1;
                    kk++;
                }
            }
            ans=max(ans,now+max(min(sz(s)-i,sz(tmp)-1),kk));
        }
        return ans;
    }
};
