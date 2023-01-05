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
const int MAX=4e4+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
namespace FWT
{
	ll inv2;//2对p的逆元 
	const ll p=1e9+7;
	ll pow2(ll a,ll b)
	{
		ll res=1;
		while(b)
		{
			if(b&1) res=res*a%p;
			a=a*a%p;
			b>>=1;
		}
		return res;
	}
	void fwt(ll *a,int n,int f,int v)
	{  
		for(int d=1;d<n;d<<=1)
		{
			for(int m=d<<1,i=0;i<n;i+=m)
			{
				for(int j=0;j<d;j++)
				{  
					ll x=a[i+j],y=a[i+j+d];
					if(!v)
					{
						if(f==1) a[i+j]=(x+y)%p,a[i+j+d]=(x-y+p)%p;//xor
						else if(f==2) a[i+j]=(x+y)%p;//and
						else if(f==3) a[i+j+d]=(x+y)%p;//or
					}
					else
					{
						if(f==1) a[i+j]=(x+y)*inv2%p,a[i+j+d]=(x-y+p)%p*inv2%p;//xor
						else if(f==2) a[i+j]=(x-y+p)%p;//and
						else if(f==3) a[i+j+d]=(y-x+p)%p;//or
					}
				}
			}
		}
	}
	
	//结果存在a 
	void XOR(ll *a,ll *b,int n)
	{
		int len;
		for(len=1;len<=n;len<<=1);
		fwt(a,len,1,0);
		fwt(b,len,1,0);
		for(int i=0;i<len;i++) a[i]=a[i]*b[i]%p;
		inv2=pow2(2,p-2);
		fwt(a,len,1,1);
	}
};
ll cnta[MAX],cntb[MAX];
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
		mem(cnta,0);
		mem(cntb,0);
		for(auto &it:nums)
		{
			cnta[it]++;
			cntb[it]++;
		}
		FWT::XOR(cnta,cntb,2e4);
		int ans=0;
		for(int i=low;i<=high;i++) ans+=cnta[i];
		return ans/2;
    }
};
