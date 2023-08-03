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
const int MAX=1e4+10;
const ll mod=998244353;
/*********************************  head  *********************************/
typedef double db;
namespace Geometry
{
	#define type db
	int sgn(type x)
	{
		if(abs(x)<eps) return 0;
		else return x>0?1:-1;
	}
	struct Point
	{  
		type x,y;
		Point operator +(const Point &a){return {x+a.x,y+a.y};}
		Point operator -(const Point &a){return {x-a.x,y-a.y};}
		Point operator -(){return {-x,-y};}
		Point operator *(const type k){return {x*k,y*k};}
		Point operator /(const type k){return {x/k,y/k};}
		bool operator <(const Point &a){return sgn(x-a.x)==0?sgn(y-a.y)<0:sgn(x-a.x)<0;}
		bool operator ==(const Point &a){return sgn(x-a.x)==0&&sgn(y-a.y)==0;}
	};
	typedef Point Vector;
	
	type dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;} //点积
	type cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;} //叉积
	db length(Vector a){return sqrtl(dot(a,a));} //向量长度
	type length2(Vector a){return dot(a,a);} //向量长度的平方
	db dist(Point a,Point b){return sqrtl(dot(a-b,a-b));} //两点距离
	type dist2(Point a,Point b){return dot(a-b,a-b);} //两点距离的平方
	Vector normal(Vector a){return Point{-a.y,a.x}/length(a);} //垂直法向量
	Vector vecunit(Vector a){return a/length(a);} //单位向量
	db ang(Vector a,Vector b){return acosl(dot(a,b)/length(a)/length(b));}//两个向量夹角 
	db ang(Vector v){return atan2(v.y,v.x);}
	Vector rotate(Vector a,db rad) //逆时针旋转 
	{
		return {a.x*cos(rad)-a.y*sin(rad),
				a.x*sin(rad)+a.y*cos(rad)};
	}
	struct Segment{Point a,b;};
	db DisPointToSeg(Point p,Segment seg)
	{
		if(seg.a==seg.b) return length(p-seg.a);
		Vector v1,v2,v3;
		v1=seg.b-seg.a;
		v2=p-seg.a;
		v3=p-seg.b;
		if(sgn(dot(v1,v2))<0) return length(v2);
		else if(sgn(dot(v1,v3))>0) return length(v3);
		else return abs(cross(v1,v2))/length(v1);
	}
	#undef type
}
using namespace Geometry;
Point p[MAX],a;
void go()
{
	int n,m,i,j;
	db ans;
	read(n,m);
	for(i=1;i<=n;i++) read(p[i].x,p[i].y);
	for(i=1;i<=m;i++)
	{
		read(a.x,a.y);
		ans=LLINF;
		for(j=2;j<=n;j++)
		{
			ans=min(ans,DisPointToSeg(a,{p[j-1],p[j]}));
		}
		printf("%.4f\n",ans);
	}
}
