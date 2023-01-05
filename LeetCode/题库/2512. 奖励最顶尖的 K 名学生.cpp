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
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        map<string,int> a,b;
        map<int,int> sc;
        for(auto &it:positive_feedback) a[it]=1;
        for(auto &it:negative_feedback) b[it]=1;
        int i;
		for(i=0;i<sz(student_id);i++)
		{
			string now;
			for(auto &it:report[i])
			{
				if(it==' ')
				{
					if(a.count(now)) sc[student_id[i]]+=3;
					else if(b.count(now)) sc[student_id[i]]--;
					now="";
				}
				else now+=it;
			}
			if(a.count(now)) sc[student_id[i]]+=3;
			else if(b.count(now)) sc[student_id[i]]--;
			else sc[student_id[i]]+=0;
		}
		VPII res;
		for(auto &it:sc) res.pb(MP(-it.se,it.fi));
		sort(all(res));
		VI ans;
		for(i=0;i<k;i++) ans.pb(res[i].se);
		return ans;
    }
};
