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
    bool strongPasswordCheckerII(string password) {
        if(sz(password)<8) return false;
        int cnt[333];
        mem(cnt,0);
		for(auto it:password)
		{
			cnt[it]++;
		} 
		int res=0;
		for(int i='a';i<='z';i++) res+=cnt[i];
		if(!res) return false;
		res=0;
		for(int i='A';i<='Z';i++) res+=cnt[i];
		if(!res) return false;
		res=0;
		for(int i='0';i<='9';i++) res+=cnt[i];
		if(!res) return false;
		string tmp="!@#$%^&*()-+";
		res=0;
		for(auto it:tmp) res+=cnt[it];
		if(!res) return false;
		for(int i=1;i<sz(password);i++)
		{
			if(password[i]==password[i-1]) return false;
		}
		return true;
    }
};
