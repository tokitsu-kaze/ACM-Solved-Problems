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
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
set<int> x[MAX],y[MAX],xx,yy;
int n,m,k,a,b,nowx,nowy,dir,tmp;
ll res;
bool ck()
{
	int ok=0;
	if(dir==1)
	{
		tmp=min(*x[nowx].upper_bound(nowy),*yy.upper_bound(nowy));
		if(tmp-1-nowy>0)
		{
			ok=1;
			res+=tmp-1-nowy;
			nowy=tmp-1;
			xx.insert(nowx);
		}
	}
	else if(dir==2)
	{
		tmp=min(*y[nowy].upper_bound(nowx),*xx.upper_bound(nowx));
		if(tmp-1-nowx>0)
		{
			ok=1;
			res+=tmp-1-nowx;
			nowx=tmp-1;
			yy.insert(nowy);
		}
	}
	else if(dir==3)
	{
		auto it1=x[nowx].lower_bound(nowy);
		it1--;
		auto it2=yy.lower_bound(nowy);
		it2--;
		tmp=max(*it1,*it2);
		if(nowy-tmp-1>0)
		{
			ok=1;
			res+=nowy-tmp-1;
			nowy=tmp+1;
			xx.insert(nowx);
		}
	}
	else if(dir==4)
	{
		auto it1=y[nowy].lower_bound(nowx);
		it1--;
		auto it2=xx.lower_bound(nowx);
		it2--;
		tmp=max(*it1,*it2);
		if(nowx-tmp-1>0)
		{
			ok=1;
			res+=nowx-tmp-1;
			nowx=tmp+1;
			yy.insert(nowy);
		}
	}
//	debug(nowx,nowy,ok,dir)
	dir++;
	if(dir==5) dir=1;
	return ok;
}
void go()
{
	int i;
	while(read(n,m,k))
	{
		for(i=0;i<=100000;i++)
		{
			x[i].clear();
			y[i].clear();
			x[i].insert(m+1);
			x[i].insert(0);
			y[i].insert(n+1);
			y[i].insert(0);
		}
		xx.clear();
		yy.clear();
		for(i=1;i<=k;i++)
		{
			read(a,b);
			x[a].insert(b);
			y[b].insert(a);
		}
		xx.insert(n+1);
		xx.insert(0);
		yy.insert(m+1);
		yy.insert(0);
		res=1;
		nowx=1;
		nowy=1;
		dir=1;
		ck();
		while(1)
		{
			if(!ck()) break;
		}
	//	debug(res)
		if(res+k==1ll*n*m) puts("Yes");
		else puts("No");
	}
}
/*
3 3 6
1 2
1 3
2 2
2 3
3 2
3 3
*/
