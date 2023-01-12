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
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
    	int t;
        VI id,rank(sz(time),0);
        int i;
        for(i=0;i<sz(time);i++) id.pb(i);
        sort(all(id),[&](int x,int y){
        	if(time[x][0]+time[x][2] == time[y][0]+time[y][2]) return x<y;
        	return time[x][0]+time[x][2]<time[y][0]+time[y][2];
		});
		priority_queue<PII > l,r,nowl,nowr;
		for(i=0;i<sz(time);i++)
		{
			l.push(MP(i,id[i]));
			rank[id[i]]=i;
		}
		int worker;
		t=0;
		while(n>0)
		{
			while(sz(nowl)&&-nowl.top().fi<=t)
			{
				l.push(MP(rank[nowl.top().se],nowl.top().se));
				nowl.pop();
			}
			while(sz(nowr)&&-nowr.top().fi<=t)
			{
				r.push(MP(rank[nowr.top().se],nowr.top().se));
				nowr.pop();
			}
			if(sz(r))
			{
				worker=r.top().se;
				r.pop();
				t+=time[worker][2];
				nowl.push(MP(-(t+time[worker][3]),worker));
			}
			else if(sz(l))
			{
				worker=l.top().se;
				l.pop();
				t+=time[worker][0];
				n--;
				nowr.push(MP(-(t+time[worker][1]),worker));
			}
			else t++;
		//	printf("%d\n",t);
		}
		while(sz(nowr)||sz(r))
		{
			while(sz(nowr)&&-nowr.top().fi<=t)
			{
				r.push(MP(rank[nowr.top().se],nowr.top().se));
				nowr.pop();
			}
			if(sz(r))
			{
				worker=r.top().se;
				r.pop();
				t+=time[worker][2];
			}
			else
			{
				t=-nowr.top().fi;
			}
		}
		return t;
    }
};
