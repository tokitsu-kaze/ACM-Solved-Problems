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
	inline bool read_line(char *s){
		char ch=nc();
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		for(;ch!='\n'&&!IOerror;ch=nc())*s++=ch;
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
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VS> VVS;
typedef vector<VPII> VVPII;
/************* define end  *************/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/********* gp_hash_table end  **********/
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
const int MAX=5e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
/*
void go()
{
	int i,j;
	for(i=0;i<(1<<12);i++)
	{
		puts("1 12");
		for(j=0;j<12;j++)
		{
			printf("%d",(i>>j)&1);
		}
		puts("");
	}
}
*/

char s[MAX];
int flag[MAX];
void go()
{
//	freopen("out2.txt","w",stdout);
	int n,m,i,j,mn,mx,ret;
	while(read(n,m))
	{
		mn=mx=0;
		for(i=1;i<=n;i++)
		{
			read(s+1);
//			puts(s+1);
			ret=m/4;
			for(j=0;j<=m;j++) flag[j]=0;
			for(j=2;j<=m;j++)
			{
				if(flag[j] || flag[j-1]) continue;
				if(ret>0 && s[j]=='1' && s[j]==s[j-1])
				{
					ret--;
					mn++;
					flag[j-1]=flag[j]=1;
				}
			}
			for(j=2;j<=m;j++)
			{
				if(flag[j] || flag[j-1]) continue;
				if(ret>0 && s[j]!=s[j-1])
				{
					ret--;
					mn++;
					flag[j-1]=flag[j]=1;
				}
			}
			for(j=2;j<=m;j++)
			{
				if(flag[j] || flag[j-1]) continue;
				if(ret>0)
				{
					ret--;
					flag[j-1]=flag[j]=1;
					if(s[j-1]=='1' || s[j]=='1') mn++;
				}
			}
			for(j=1;j<=m;j++)
			{
				if(!flag[j]) mn+=s[j]-'0';
			}
			
			ret=m/4;
			for(j=0;j<=m;j++) flag[j]=0;
			for(j=2;j<=m;j++)
			{
				if(flag[j] || flag[j-1]) continue;
				if(ret>0 && s[j]=='0')
				{
					ret--;
					flag[j-1]=flag[j]=1;
					if(s[j-1]=='1') mx++;
				}
				else if(ret>0 && s[j]=='1' && s[j-1]=='0')
				{
					ret--;
					flag[j-1]=flag[j]=1;
					mx++;
				}
			}
			for(j=2;j<=m;j++)
			{
				if(flag[j] || flag[j-1]) continue;
				if(ret>0)
				{
					ret--;
					flag[j-1]=flag[j]=1;
					if(s[j-1]=='1' || s[j]=='1') mx++;
				}
			}
			for(j=1;j<=m;j++)
			{
				if(!flag[j]) mx+=s[j]-'0';
			}
		}
		printf("%d %d\n",mn,mx);
	}
}

/*
char s[MAX];
int dp[22][22];
void go()
{
	freopen("out.txt","w",stdout);
	int n,m,i,j,k,mn,mx;
	while(read(n,m))
	{
		mn=mx=0;
		for(i=1;i<=n;i++)
		{
			read(s+1);
			puts(s+1);
			mem(dp,0x3f);
			dp[0][0]=0;
			for(j=1;j<=m;j++)
			{
				dp[j][0]=dp[j-1][0]+(s[j]=='1');
				for(k=1;k<=min(m/4,j/2);k++)
				{
					dp[j][k]=dp[j-1][k]+(s[j]=='1');
					if(j>1) dp[j][k]=min(dp[j][k],dp[j-2][k-1]+(s[j-1]=='1'||s[j]=='1'));
				}
			}
			mn+=dp[m][m/4];
			
			mem(dp,0);
			for(j=1;j<=m;j++)
			{
				dp[j][0]=dp[j-1][0]+(s[j]=='1');
				for(k=1;k<=min(m/4,j/2);k++)
				{
					dp[j][k]=dp[j-1][k]+(s[j]=='1');
					if(j>1) dp[j][k]=max(dp[j][k],dp[j-2][k-1]+(s[j-1]=='1'||s[j]=='1'));
				}
			}
			mx+=dp[m][m/4];
		}
		printf("%d %d\n",mn,mx);
	}
}*/
