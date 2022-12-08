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
typedef vector<string> VS;
/************* define end  *************/
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
void assert_lr(ll x,ll l,ll r) {assert(x>=l&&x<=r);};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
int flag[MAX];
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        ll ans;
        mem(flag,0);
        priority_queue<int,VI,greater<int>> qa,qb;
        int i,l,r;
        for(i=0;i<candidates;i++)
        {
        	qa.push(costs[i]);
        	flag[i]=1;
		}
        l=candidates-1;
        r=sz(costs)-candidates;
        for(i=sz(costs)-1;i>=sz(costs)-candidates;i--)
        {
        	if(flag[i])
        	{
        		r=i+1;
        		break;
			}
        	qb.push(costs[i]);
        	flag[i]=1;
		}
		ans=0;
		while(k--)
		{
			if(sz(qa)==0)
			{
				ans+=qb.top();
				qb.pop();
				if(r-1>=0&&flag[r-1]==0)
				{
					qb.push(costs[--r]);
					flag[r]=1;
				}
			}
			else if(sz(qb)==0)
			{
				ans+=qa.top();
				qa.pop();
				if(l+1<sz(costs)&&flag[l+1]==0)
				{
					qa.push(costs[++l]);
					flag[l]=1;
				}
			}
			else
			{
				if(qa.top()<=qb.top())
				{
					ans+=qa.top();
					qa.pop();
					if(l+1<sz(costs)&&flag[l+1]==0)
					{
						qa.push(costs[++l]);
						flag[l]=1;
					}
				}
				else
				{
					ans+=qb.top();
					qb.pop();
					if(r-1>=0&&flag[r-1]==0)
					{
						qb.push(costs[--r]);
						flag[r]=1;
					}
				}
			}
		}
		return ans;
    }
};
