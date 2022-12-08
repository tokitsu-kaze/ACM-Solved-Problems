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

string tel[11],dig;
void init()
{
	tel[2]="abc";
	tel[3]="def";
	tel[4]="ghi";
	tel[5]="jkl";
	tel[6]="mno";
	tel[7]="pqrs";
	tel[8]="tuv";
	tel[9]="wxyz";
}
vector<string> res;
void dfs(int x,string now)
{
	if(x==sz(dig))
	{
		res.pb(now);
		return;
	}
	for(int i=0;i<sz(tel[dig[x]-'0']);i++)
	{
		dfs(x+1,now+tel[dig[x]-'0'][i]);
	}
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	if(sz(digits)==0) return vector<string>{};
		init();
		res.clear();
		dig=digits;
		dfs(0,"");
		return res;
    }
};
