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
typedef vector<PLL > VPLL;
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

int flag[12];
class Solution {
public:
    string smallestNumber(string pattern) {
		string res;
		res+="0";
        for(int i=0;i<sz(pattern);i++)
        {
			res+="0";
		}
		mem(flag,0);
		int now=1,cnt,i,j;
		for(i=0;i<sz(pattern);i++)
        {
			while(flag[now]) now++;
			if(pattern[i]=='I')
			{
				res[i]+=now++;
				flag[now-1]=1;
			}
			else
			{
				cnt=0;
				for(j=i;j<sz(pattern);j++)
				{
					if(pattern[j]=='D') cnt++;
					else break;
				}
				j=i+cnt;
				int tmp=now;
				while(cnt>0)
				{
					if(!flag[tmp]) cnt--;
					tmp++;
				}
				while(i<j)
				{
					res[i]+=tmp;
					flag[tmp]=1;
					while(flag[tmp]) tmp--;
					i++;
				}
				i--;
			}
		}
		while(flag[now]) now++;
		res.back()+=now++;
		return res;
    }
};
