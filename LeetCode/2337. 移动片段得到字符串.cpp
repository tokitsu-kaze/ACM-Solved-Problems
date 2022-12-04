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
    bool canChange(string start, string target) {
        int cnt[333];
        mem(cnt,0);
        for(auto it:start) cnt[it]++;
        for(auto it:target) cnt[it]--;
        if(cnt['L']||cnt['R']||cnt['_']) return false;
        int i,j,ok;
        ok=1;
        for(i=0,j=0;i<sz(start);i++)
        {
			if(start[i]=='_') continue;
			while(j<sz(target) && target[j]=='_') j++;
			if(start[i]!=target[j]) ok=0;
			if(start[i]=='L')
			{
				if(i<j) ok=0;
			}
			else
			{
				if(i>j) ok=0;
			}
			j++;
		}
		if(ok) return true;
		return false;
    }
};
