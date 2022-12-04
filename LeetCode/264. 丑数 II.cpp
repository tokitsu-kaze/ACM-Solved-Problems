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
const int MAX=1e4+10;
const ll mod=1e9+7;

class Solution {
public:
    int nthUglyNumber(int n) {
		set<ll> s;
		s.insert(1);
		map<ll,int> mp;
		ll ans;
		while(n--)
		{
			ans=*s.begin();
			s.erase(s.begin());
			if(!mp.count(ans*2))
			{
				s.insert(ans*2);
				mp[ans*2]=1;
			}
			if(!mp.count(ans*3))
			{
				s.insert(ans*3);
				mp[ans*3]=1;
			}
			if(!mp.count(ans*5))
			{
				s.insert(ans*5);
				mp[ans*5]=1;
			}
		}
		return ans;
    }
};
