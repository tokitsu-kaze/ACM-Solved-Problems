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
//		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct node{int x,y;};
char mp[105][105];
int n;
void out(int x,int y,char c)
{
	cout<<"! "<<x<<" "<<y<<" "<<c<<endl;
}
node ask(int x,int y)
{
	cout<<"? "<<x<<" "<<y<<endl;
	for(int i=1;i<=n;i++)
	{
		mp[i][n+1]='\0';
		cout<<(mp[i]+1)<<endl;
	}
	cin>>x>>y;
	return {x,y};
}
void make1()
{
	int i,j;
	/*
	>>>>>v
	v<<<<<
	>>>>>v
	v<<<<<
	*/
	for(i=1;i<=n;i++)
	{
		if(i&1)
		{
			for(j=1;j<n;j++) mp[i][j]='>';
			mp[i][n]='v';
		}
		else
		{
			for(j=n;j>=2;j--) mp[i][j]='<';
			mp[i][1]='v';
		}
	}
}
void make2()
{
	int i,j;
	/*
	^<<<<<
	>>>>>^
	^<<<<<
	>>>>>^
	*/
	for(i=1;i<=n;i++)
	{
		if(!(i&1))
		{
			for(j=1;j<n;j++) mp[i][j]='>';
			mp[i][n]='^';
		}
		else
		{
			for(j=n;j>=2;j--) mp[i][j]='<';
			mp[i][1]='^';
		}
	}
}
void make3(int x,int y)
{
	/*
	>>^>>>
	>>^>>>
	<<x>>>
	>>v>>>
	>>v>>>
	*/
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			mp[i][j]='>';
		}
	}
	for(i=1;i<=x;i++) mp[i][y]='^';
	for(i=x+1;i<=n;i++) mp[i][y]='v';
	for(j=1;j<=y;j++) mp[x][j]='<';
	for(j=y+1;j<=n;j++) mp[x][j]='>';
}
void go()
{
	node ra,rb,res,ans;
	int i,j,l,r,mid;
	cin>>n;
	make1();
	ra=ask(1,1);
	make2();
	rb=ask(n,n&1?n:1);
	if(ra.x==rb.x&&ra.y==rb.y)
	{
		if(ra.x==0) out(1,ra.y,'^');
		else if(ra.y==0) out(ra.x,1,'<');
		else if(ra.x==n+1) out(n,ra.y,'v');
		else if(ra.y==n+1) out(ra.x,n,'>');
		return;
	}
	if(ra.x==-1)
	{
		make1();
		l=1;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			res=ask(mid+1,(mid+1)&1?1:n);
			if(res.x==-1) l=mid+1;
			else r=mid;
		}
		ans.x=l;
		l=1;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ans.x&1)
			{
				res=ask(ans.x,mid+1);
				if(res.x==-1) l=mid+1;
				else r=mid;
			}
			else
			{
				res=ask(ans.x,mid);
				if(res.x==-1) r=mid;
				else l=mid+1;
			}
		}
		ans.y=l;
	}
	else if(rb.x==-1)
	{
		make2();
		l=1;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			res=ask(mid,mid&1?n:1);
			if(res.x==-1) r=mid;
			else l=mid+1;
		}
		ans.x=l;
		l=1;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(!(ans.x&1))
			{
				res=ask(ans.x,mid+1);
				if(res.x==-1) l=mid+1;
				else r=mid;
			}
			else
			{
				res=ask(ans.x,mid);
				if(res.x==-1) r=mid;
				else l=mid+1;
			}
		}
		ans.y=l;
	}
	else assert(0);
	debug(ans.x,ans.y)
	make3(ans.x,ans.y);
	res=ask(ans.x,ans.y);
	if(res.x==0) out(ans.x,ans.y,'^');
	else if(res.x==n+1) out(ans.x,ans.y,'v');
	else if(res.y==0) out(ans.x,ans.y,'<');
	else if(res.y==n+1) out(ans.x,ans.y,'>');
}
