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
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Discretization
{
	#define type ll
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.pb(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get(type x){return lower_bound(all(a),x)-a.begin()+1;}
	int size(){return a.size();}
	#undef type
}di;
struct node{ll x,y;}a[MAX];
ll lx[MAX],rx[MAX],ly[MAX],ry[MAX],dp[MAX][2];
ll dis(ll x,ll y,ll a,ll b){return abs(x-a)+abs(y-b);}
void go()
{
	int id,i,n;
	ll tmp1,tmp2;
	while(read(n))
	{
		di.init();
		for(i=1;i<=n;i++)
		{
			read(a[i].x,a[i].y);
			di.add(max(a[i].x,a[i].y));
		}
		di.work();
		mem(lx,0);
		mem(ly,0);
		mem(rx,0);
		mem(ry,0);
		for(i=1;i<=n;i++)
		{
			id=di.get(max(a[i].x,a[i].y));
			if(!lx[id]&&!ly[id]||a[i].x-a[i].y<lx[id]-ly[id]) lx[id]=a[i].x,ly[id]=a[i].y;
			if(!rx[id]&&!ry[id]||a[i].x-a[i].y>rx[id]-ry[id]) rx[id]=a[i].x,ry[id]=a[i].y;
		}
		mem(dp[0],0);
		for(i=1;i<=sz(di);i++)
		{
			tmp1=dp[i-1][0]+dis(lx[i-1],ly[i-1],rx[i],ry[i]);
			tmp2=dp[i-1][1]+dis(rx[i-1],ry[i-1],rx[i],ry[i]);
			dp[i][0]=min(tmp1,tmp2)+dis(lx[i],ly[i],rx[i],ry[i]);
			tmp1=dp[i-1][0]+dis(lx[i-1],ly[i-1],lx[i],ly[i]);
			tmp2=dp[i-1][1]+dis(rx[i-1],ry[i-1],lx[i],ly[i]);
			dp[i][1]=min(tmp1,tmp2)+dis(lx[i],ly[i],rx[i],ry[i]);
		}
		printf("%lld\n",min(dp[sz(di)][0],dp[sz(di)][1]));
	}
}