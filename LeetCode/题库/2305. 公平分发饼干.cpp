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

VI tmp;
int res[11],ans;
void dfs(int x,int k)
{
	int i;
	int cnt=0;
	for(i=1;i<=k;i++)
	{
		if(res[i]==0) cnt++;
	}
	if(cnt>sz(tmp)-x) return;
	if(x==sz(tmp))
	{
		int mx=0;
		for(i=1;i<=k;i++)
		{
			mx=max(mx,res[i]);
			if(res[i]==0) return;
		}
		ans=min(ans,mx);
		return;
	}
	for(i=1;i<=k;i++)
	{
		res[i]+=tmp[x];
		dfs(x+1,k);
		res[i]-=tmp[x];
	}
}

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        ans=INF;
    	tmp=cookies;
        dfs(0,k);
        return ans;
    }
};
