#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<string> VS;
/************* define end  *************/
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Monotone_queue
{
	#define type int
	type v[MAX];
	int p[MAX];
	int l,r;
	void clear()
	{
		l=r=0;
	}
	void insert(int pos,type x)
	{
		while(r-l&&v[r-1]>=x) r--;
		v[r]=x;
		p[r++]=pos;
	}
	void erase(int pos)
	{
		while(r-l&&p[l]<=pos) l++;
	}
	type get_min(){return v[l];}
	#undef type
}dq;
class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
		dq.clear();
		int i,j,now,dp,sum;
		now=dp=sum=0;
		dq.insert(0,0);
		for(i=0,j=0;i<sz(boxes);i++)
		{
			sum+=boxes[i][1];
			while(sum>maxWeight || i-j+1>maxBoxes)
			{
				dq.erase(j);
				sum-=boxes[j][1];
				j++;
			}
			dp=dq.get_min()+now+2;
			if(i+1<sz(boxes) && boxes[i][0]!=boxes[i+1][0]) now++;
			dq.insert(i+1,dp-now);
		}
		return dp;
    }
};
