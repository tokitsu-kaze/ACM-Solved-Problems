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

vector<string> res;
string now,st;
void dfs(int x,int y)
{
    if(x==0&&y==0)
    {
        res.pb(now);
        return;
    }
    if(x)
    {
        now+="(";
        st+="(";
        dfs(x-1,y);
        now.pop_back();
        st.pop_back();
    }
    if(y)
    {
        if(sz(st)&&st.back()=='(')
        {
            now+=")";
            st.pop_back();
            dfs(x,y-1);
            now.pop_back();
            st+="(";
        }
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        res.clear();
        now="";
        dfs(n,n);
        return res;
    }
};
