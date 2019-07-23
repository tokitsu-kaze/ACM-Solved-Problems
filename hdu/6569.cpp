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
const int MAX=1e6+10;
const ll mod=998244353;
/*********************************  head  *********************************/
int mo[MAX],p[MAX],tot;
bool flag[MAX];
void initmo(int n)
{
	int i,j;
	mem(flag,0);
	mem(mo,0);
	tot=0;
	mo[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!flag[i])
		{
			p[tot++]=i;
			mo[i]=-1;
		}
		for(j=0;j<tot&&p[j]*i<=n;j++)
		{
			flag[i*p[j]]=1;
			if(i%p[j]==0)
			{
				mo[p[j]*i]=0;
				break;
			}
			mo[p[j]*i]=-mo[i];
		}
	}
}
int cnt[MAX];
ll dp[MAX];
void go()
{
	int n,i,j,k,a[2020],d,l,r;
	ll ans;
	initmo(MAX-10);
	while(read(n))
	{
		read(a,1,n);
		mem(dp,0);
		mem(cnt,0);
		for(i=1;i<=n;i++) cnt[a[i]]++;
		VI res;
		for(i=1;i<=10000;i++)
		{
			res.clear();
			for(j=i;j<=10000;j+=i)
			{
				if(cnt[j]) res.pb(j);
			}
			dp[i]=0;
			for(j=0;j<sz(res);j++)
			{
				if(cnt[res[j]]<2) continue;
				for(k=0;k<sz(res);k++)
				{
					if(j==k)
					{
						if(cnt[res[j]]-3<0) continue;
					}
					cnt[res[j]]-=2;
					cnt[res[k]]--;
					l=res[k]+i;
					r=res[k]+2*res[j]-i;
					dp[i]+=upper_bound(all(res),r)-lower_bound(all(res),l);
					if(res[k]>=l&&res[k]<=r&&cnt[res[k]]==0) dp[i]--;
					if(res[j]>=l&&res[j]<=r&&cnt[res[j]]==0) dp[i]--;
					if(res[k]>=l&&res[k]<=r&&cnt[res[k]]==0&&j==k) dp[i]++;
					cnt[res[j]]+=2;
					cnt[res[k]]++;
				}
			}
	//		if(dp[i]) debug(i,dp[i])
		}
		ans=0;
		for(d=1;d<=10000;d++) ans+=1ll*mo[d]*dp[d];
		printf("%lld\n",ans);
	}
}
