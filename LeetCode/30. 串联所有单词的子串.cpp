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
    vector<int> findSubstring(string s, vector<string>& words) {
    	if(sz(words)==0) return VI{};
		map<string,int> mp,nowmp;
		int len=sz(words[0]);
		for(auto it:words) mp[it]++;
		VI res;
		for(int i=0,now;i<sz(s)-sz(words)*len+1;i++)
		{
			now=i;
			nowmp.clear();
			int ok=1;
			for(int j=0;j<sz(words);j++)
			{
				string tmp;
				for(int k=0;k<len;k++)
				{
					tmp+=s[now++];
				}
				if(!mp.count(tmp))
				{
					ok=0;
					break;
				}
				if(mp[tmp]==0)
				{
					ok=0;
					break;
				}
				nowmp[tmp]++;
				mp[tmp]--;
			}
			for(auto it:nowmp) mp[it.fi]+=it.se;
			if(ok) res.pb(i);
		}
		return res;
    }
};
