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
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int ck(vector<string> &ra,vector<string> &rb)
{
	int i,j,cnt,pre;
	j=0;
	VI res;
	for(i=0;i<sz(ra);i++)
	{
		if(j<sz(rb))
		{
			if(ra[i]==rb[j])
			{
				j++;
				res.pb(i);
			}
		}
	}
	cnt=0;
	pre=-1;
	for(i=0;i<sz(res);i++)
	{
		if(res[i]!=pre+1) cnt++;
		pre=res[i];
	}
	if(pre<sz(ra)-1) cnt++;
	if(j==sz(rb)&&cnt<=1) return 1;
	return 0;
}
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
		vector<string> ra,rb;
		string tmp;
		for(auto &ch:sentence1)
		{
			if(ch==' ')
			{
				if(sz(tmp)) ra.pb(tmp);
				tmp="";
			}
			else tmp+=ch;
		}
		if(sz(tmp)) ra.pb(tmp);
		tmp="";
		for(auto &ch:sentence2)
		{
			if(ch==' ')
			{
				if(sz(tmp)) rb.pb(tmp);
				tmp="";
			}
			else tmp+=ch;
		}
		if(sz(tmp)) rb.pb(tmp);
		
		if(ck(ra,rb)) return true;
		if(ck(rb,ra)) return true;
		
		reverse(all(ra));
		reverse(all(rb));
		if(ck(ra,rb)) return true;
		if(ck(rb,ra)) return true;
		
		return false;
    }
};
