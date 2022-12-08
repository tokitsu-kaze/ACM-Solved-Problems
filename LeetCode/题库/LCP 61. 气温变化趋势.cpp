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
const int MAX=3e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
		int a[1101],b[1101];
		for(int i=1;i<sz(temperatureA);i++)
		{
			if(temperatureA[i]>temperatureA[i-1]) a[i]=1;
			else if(temperatureA[i]==temperatureA[i-1]) a[i]=0;
			else a[i]=-1;
		} 
		for(int i=1;i<sz(temperatureB);i++)
		{
			if(temperatureB[i]>temperatureB[i-1]) b[i]=1;
			else if(temperatureB[i]==temperatureB[i-1]) b[i]=0;
			else b[i]=-1;
		} 
		int res=0,now=0;
		for(int i=1;i<sz(temperatureB);i++)
		{
			if(a[i]==b[i]) now++;
			else now=0;
			res=max(res,now);
		}
		return res;
    }
};
