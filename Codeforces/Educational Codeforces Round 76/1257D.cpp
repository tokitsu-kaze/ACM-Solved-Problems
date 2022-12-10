#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
	//inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;} 
	inline char nc(){
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
		if(p1==pend){
			p1=buf;pend=buf+fread(buf,1,BUF_SIZE,stdin);
			if(pend==p1){IOerror=1;return -1;}
		}
		return *p1++;
	}
	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
	template<class T> inline bool read(T &x){
		bool sign=0;char ch=nc();x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		if(ch=='-')sign=1,ch=nc();
		for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(sign)x=-x;
		return true;
	}
	inline bool read(double &x){
		bool sign=0;char ch=nc();x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		if(ch=='-')sign=1,ch=nc();
		for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(ch=='.'){
			double tmp=1; ch=nc();
			for(;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
		}
		if(sign)x=-x;
		return true;
	}
	inline bool read(char *s){
		char ch=nc();
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		for(;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
		*s=0;
		return true;
	}
	inline bool read(char &c){
		for(c=nc();blank(c);c=nc());
		if(IOerror){c=-1;return false;}
		return true; 
	}
	template<class T,class... U>bool read(T& h,U&... t){return read(h)&&read(t...);}
	#undef OUT_SIZE
	#undef BUF_SIZE
};
using namespace fastIO;
/************* debug begin *************/
string to_string(string s){return '"'+s+'"';}
string to_string(const char* s){return to_string((string)s);}
string to_string(const bool& b){return(b?"true":"false");}
template<class T>string to_string(T x){ostringstream sout;sout<<x;return sout.str();}
template<class A,class B>string to_string(pair<A,B> p){return "("+to_string(p.first)+", "+to_string(p.second)+")";}
template<class A>string to_string(const vector<A> v){
	int f=1;string res="{";for(const auto x:v){if(!f)res+= ", ";f=0;res+=to_string(x);}res+="}";
	return res;
}
void debug_out(){puts("");}
template<class T,class... U>void debug_out(const T& h,const U&... t){cout<<" "<<to_string(h);debug_out(t...);}
#ifdef tokitsukaze 
#define debug(...) cout<<"["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__);
#else
#define debug(...) 233;
#endif
/*************  debug end  *************/
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
typedef vector<PII > VPII;
/************* define end  *************/
void read(int *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void read(ll *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void read(double *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
struct RMQ
{
	#define type int
	type v[MAX];
	int pmax(int a,int b){return v[a]>v[b]?a:b;}
	int pmin(int a,int b){return v[a]<v[b]?a:b;}
	int lg[MAX],bin[22];
	int pmx[MAX][22],pmn[MAX][22];
	type mx[MAX][22],mn[MAX][22];
	void work(int n,type *a)
	{
		int i,j;
		for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
		for(i=1;i<=n;i++)
		{
			v[i]=a[i];
			mx[i][0]=mn[i][0]=v[i];
			pmx[i][0]=pmn[i][0]=i;
		}
		for(j=1;1<<(j-1)<=n;j++)
		{
			for(i=1;i+bin[j]-1<=n;i++)
			{
				mx[i][j]=max(mx[i][j-1],mx[i+bin[j-1]][j-1]);
				mn[i][j]=min(mn[i][j-1],mn[i+bin[j-1]][j-1]);
				pmx[i][j]=pmax(pmx[i][j-1],pmx[i+bin[j-1]][j-1]);
				pmn[i][j]=pmin(pmn[i][j-1],pmn[i+bin[j-1]][j-1]);
			}
		}
	}
	type ask_max(int l,int r)
	{
		int t=lg[r-l+1];
		return max(mx[l][t],mx[r-bin[t]+1][t]);
	}
	type ask_min(int l,int r)
	{
		int t=lg[r-l+1];
		return min(mn[l][t],mn[r-bin[t]+1][t]);
	}
	type ask_pmax(int l,int r)
	{
		int t=lg[r-l+1];
		return pmax(pmx[l][t],pmx[r-bin[t]+1][t]);
	}
	type ask_pmin(int l,int r)
	{
		int t=lg[r-l+1];
		return pmin(pmn[l][t],pmn[r-bin[t]+1][t]);
	}
	#undef type
}rmq;
int a[MAX];
void go()
{
	int t,n,m,i,ans,p,s,l,r,mid;
	read(t);
	while(t--)
	{
		read(n);
		read(a,1,n);
		rmq.work(n,a);
		VPII res;
		read(m);
		for(i=1;i<=m;i++)
		{
			read(p,s);
			res.pb(MP(s,p));
		}
		sort(all(res));
		for(i=sz(res)-2;~i;i--) res[i].se=max(res[i].se,res[i+1].se);
		res.pb(MP(INF,0));
		ans=0;
		for(i=1;i<=n;i++)
		{
			l=1;
			r=n-i+1;
			while(l<r)
			{
				mid=(l+r)>>1;
				PII tmp=*lower_bound(all(res),MP(mid+1,-1));
				if(tmp.se>=rmq.ask_max(i,i+mid)) l=mid+1;
				else r=mid;
			}
			PII tmp=*lower_bound(all(res),MP(l,-1));
			if(tmp.se>=rmq.ask_max(i,i+l-1))
			{
				ans++;
				i=i+l-1;
			}
			else
			{
				ans=-1;
				break;
			}
		}
		printf("%d\n",ans);
	}
}
