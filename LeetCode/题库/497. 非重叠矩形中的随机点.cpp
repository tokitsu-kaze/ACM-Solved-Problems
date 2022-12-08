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

vector<vector<int>> res;
mt19937 rd(time(0));
int sum;

class Solution {
public:
    Solution(vector<vector<int>>& rects) {
    	res.clear();
    	sum=0;
		for(auto it:rects)
		{
			res.pb(it);
			sum+=(it[2]-it[0]+1)*(it[3]-it[1]+1);
		}
    }
    
    vector<int> pick() {
		int pos=rd()%sum+1;
		int x,y,tmp;
		for(auto it:res)
		{
			tmp=(it[2]-it[0]+1)*(it[3]-it[1]+1);
			if(tmp<pos) pos-=tmp;
			else
			{
				y=it[1]+(pos+it[2]-it[0])/(it[2]-it[0]+1)-1;
				x=it[0]+pos-(y-it[1])*(it[2]-it[0]+1)-1;
				return VI{x,y};
			}
		}
        return VI{};
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
