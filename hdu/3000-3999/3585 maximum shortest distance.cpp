#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
//	inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;} 
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Max_Clique
{
	static const int N=55;
	vector<int> sol;
	int el[N][N/30+1],s[N][N/30+1];
	int n,ans,dp[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++)
		{
			dp[i]=0;
			mem(el[i],0);
		}
	}
	/* Zero Base */
	void add_edge(int a,int b)
	{
		if(a>b) swap(a,b);
		if(a==b) return;
		el[a][b/32]|=(1<<(b%32));
	}
	bool dfs(int x,int k)
	{
		int c=0,d=0;
		for(int i=0;i<(n+31)/32;i++)
		{
			s[k][i]=el[x][i];
			if(k!=1) s[k][i]&=s[k-1][i];
			c+=__builtin_popcount(s[k][i]);
		}
		if(c==0)
		{
			if(k>ans)
			{
				ans=k;
				sol.clear();
				sol.pb(x);
				return 1;
			}
			return 0;
		}
		for(int i=0;i<(n+31)/32;i++)
		{
			for(int a=s[k][i];a;d++)
			{
				if(k+(c-d)<=ans) return 0;
				int lb=a&(-a),lg=0;
				a^=lb;
				while(lb!=1)
				{
					lb=(unsigned int)(lb)>>1;
					lg++;
				}
				int u=i*32+lg;
				if(k+dp[u]<=ans) return 0;
				if(dfs(u,k+1))
				{
					sol.pb(x);
					return 1;
				}
			}
		}
		return 0;
	}
	int solve()
	{
		ans=0;
		for(int i=n-1;i>=0;i--)
		{
			dfs(i,1);
			dp[i]=ans;
		}
		return ans;
	}
}mcp;
/*
mcp.init(n);
mcp.add_edge(a,b); a,b: 0~n-1
*/
int x[55],y[55];
double dist(int a,int b){return sqrt(1.0*(x[a]-x[b])*(x[a]-x[b])+1.0*(y[a]-y[b])*(y[a]-y[b]));}
int check(double d,int n)
{
	int i,j;
	mcp.init(n);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(dist(i,j)>=d) mcp.add_edge(i,j);
		}
	}
	return mcp.solve();
}
void go()
{
	int n,k,i;
	double l,r,mid;
	while(read(n,k))
	{
		for(i=0;i<n;i++) read(x[i],y[i]);
		l=0;
		r=1e6;
		while(r-l>eps)
		{
			mid=(l+r)/2;
			if(check(mid,n)>=k) l=mid;
			else r=mid;
		}
		printf("%.2f\n",l);
	}
}
