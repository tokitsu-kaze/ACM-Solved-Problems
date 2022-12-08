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
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        int ha[33],flag[33];
		for(auto it:words)
        {
            int ok=1;
            mem(ha,-1);
            mem(flag,0);
            for(int i=0;i<sz(pattern);i++)
            {
                if(ha[it[i]-'a']==-1)
                {
                    if(flag[pattern[i]-'a']) ok=0;
                    else
                    {
                        ha[it[i]-'a']=pattern[i]-'a';
                        flag[pattern[i]-'a']=1;
                    }
                }
                else
                {
                    if(ha[it[i]-'a']!=int(pattern[i]-'a')) ok=0;
                } 
            }
            if(ok) res.pb(it);
        }
        return res;
    }
};

