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
const int MAX=5000+10;
const ll mod=998244353;
/*********************************  head  *********************************/
int a[MAX],b[MAX],prea[MAX],preb[MAX],nexa[MAX],nexb[MAX];
ll dp[MAX][MAX],dp2[MAX][MAX];
ll getdp(int x,int y)
{
	if(x<0||y<0) return 0ll;
	return dp[x][y];
}
ll getdp2(int x,int y)
{
	if(x<0||y<0) return 0ll;
	return dp2[x][y];
}
void go()
{
	int n,m,i,j,last[111];
	ll ans;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=100;i++) last[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			prea[i]=last[a[i]];
			last[a[i]]=i;
		}
		for(i=1;i<=100;i++) last[i]=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d",&b[i]);
			preb[i]=last[b[i]];
			last[b[i]]=i;
		}
		for(i=1;i<=100;i++) last[i]=n+1;
		for(i=n;i;i--)
		{
			nexa[i]=last[a[i]];
			last[a[i]]=i;
		}
		for(i=1;i<=100;i++) last[i]=m+1;
		for(i=m;i;i--)
		{
			nexb[i]=last[b[i]];
			last[b[i]]=i;
		}
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				dp[i][j]=0;
			}
		}
		mem(last,0);
		for(i=1;i<=n;i++)
		{
			dp[i][1]=dp[i-1][1]+(last[a[i]]==0);
			for(j=2;j<=i;j++)
			{
				dp[i][j]=dp[i-1][j]+dp[i-1][j-1]-getdp(prea[i]-1,j-1);
				dp[i][j]%=mod;
				if(dp[i][j]<0) dp[i][j]+=mod;
			}
			last[a[i]]=i;
		}
		for(i=0;i<=max(n,m);i++)
		{
			for(j=0;j<=max(n,m);j++)
			{
				dp2[i][j]=0;
			}
		}
		mem(last,0);
		for(i=1;i<=m;i++)
		{
			dp2[i][1]=dp2[i-1][1]+(last[b[i]]==0);
			for(j=2;j<=i;j++)
			{
				dp2[i][j]=dp2[i-1][j]+dp2[i-1][j-1]-getdp2(preb[i]-1,j-1);
				dp2[i][j]%=mod;
				if(dp2[i][j]<0) dp2[i][j]+=mod;
			}
			last[b[i]]=i;
		}
		ans=0;
		for(i=2;i<=n;i++)
		{
			ans+=dp[n][i]*dp2[m][i-1];
			ans%=mod;
			dp2[m][i]+=dp2[m][i-1];
			dp2[m][i]%=mod;
		}
		for(i=0;i<=n+3;i++)
		{
			for(j=0;j<=m+3;j++)
			{
				dp[i][j]=dp2[i][j]=0;
			}
		}
		for(i=0;i<=n+1;i++) dp[i][0]=dp2[i][m+1]=1;
		for(j=0;j<=m+1;j++) dp[0][j]=dp2[n+1][j]=1;
		for(i=n;i;i--)
		{
			for(j=m;j;j--)
			{
				dp2[i][j]=dp2[i+1][j]+dp2[i][j+1]-dp2[i+1][j+1];
				dp2[i][j]+=dp2[i+1][j+1];
				if(nexa[i]!=n+1) dp2[i][j]-=dp2[nexa[i]+1][j+1];
				if(nexb[j]!=m+1) dp2[i][j]-=dp2[i+1][nexb[j]+1];
				if(nexa[i]!=n+1&&nexb[j]!=m+1) dp2[i][j]+=dp2[nexa[i]+1][nexb[j]+1];
				dp2[i][j]%=mod;
				if(dp2[i][j]<0) dp2[i][j]+=mod;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
				dp[i][j]%=mod;
				if(a[i]>b[j])
				{
					ans+=((dp[i-1][j-1]-getdp(prea[i]-1,j-1)-getdp(i-1,preb[j]-1)+getdp(prea[i]-1,preb[j]-1))%mod+mod)%mod*dp2[i+1][j+1];
					ans%=mod;
				}
				else if(a[i]==b[j])
				{
					dp[i][j]+=dp[i-1][j-1]-getdp(prea[i]-1,j-1)-getdp(i-1,preb[j]-1)+getdp(prea[i]-1,preb[j]-1);
					dp[i][j]%=mod;
				}
			}
		}
		if(ans<0) ans+=mod;
		printf("%lld\n",ans);
	}
}
