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
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int sgn(double x)
{  
	if(fabs(x)<eps) return 0;
	else return x>0?1:-1;  
}
struct Point
{  
	double x,y;
	Point(){}
	Point(double a,double b)
	{
		x=a;
		y=b;
	}
	void input()
	{
		scanf("%lf%lf",&x,&y);
	}
};
typedef Point Vector;
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}  
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}  
Vector operator *(Vector a,double p){return Vector(a.x*p,a.y*p);}  
Vector operator /(Vector a,double p){return Vector(a.x/p,a.y/p);}
bool operator ==(Point a,Point b){return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double length(Vector a){return sqrt(dot(a,a));}
double TwoVectorAngle(Vector a,Vector b){return acos(dot(a,b)/length(a)/length(b));}
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
struct Circle  
{  
	Point c;  
	double r;  
	Circle(){}  
	Circle(Point a,double b)
	{
		c=a;
		r=b;
	}
	void input()
	{
		c.input();
		scanf("%lf",&r);
	} 
}; 
bool OnCircle(Point x,Circle c){return sgn(c.r-length(c.c-x))==0;}
int getCircleInter(Circle c1,Circle c2,Point *sol)
{
	double r1,r2,x1,y1,x2,y2,d;
	r1=c1.r;
	r2=c2.r;
	x1=c1.c.x;
	y1=c1.c.y;
	x2=c2.c.x;
	y2=c2.c.y;
	d=length(c1.c-c2.c);
	if(sgn(fabs(r1-r2)-d)>0) return -1;
	if(sgn(r1+r2-d)<0) return 0;
	double a,b,c,p,q,r;
	a=r1*(x1-x2)*2;
	b=r1*(y1-y2)*2;
	c=r2*r2-r1*r1-d*d;
	p=a*a+b*b;
	q=-a*c*2;
	r=c*c-b*b;
	double cosa,sina,cosb,sinb; 
	if(sgn(d-(r1+r2))== 0||sgn(d-fabs(r1-r2))==0)
	{
		cosa=-q/p/2;
		sina=sqrt(1-cosa*cosa);
		Point p(x1+c1.r*cosa,y1+c1.r*sina);
		if(!OnCircle(p,c2)) p.y=y1-c1.r*sina;
		sol[0]=p;
		return 1;
	}
	double delta=sqrt(q*q-p*r*4);
	cosa=(delta-q)/p/2;
	cosb=(-delta-q)/p/2;
	sina=sqrt(1-cosa*cosa);
	sinb=sqrt(1-cosb*cosb);
	Point p1(x1+c1.r*cosa,y1+c1.r*sina);
	Point p2(x1+c1.r*cosb,y1+c1.r*sinb);
	if(!OnCircle(p1,c2)) p1.y=y1-c1.r*sina;
	if(!OnCircle(p2,c2)) p2.y=y1-c1.r*sinb;
	if(p1==p2) p1.y=y1-c1.r*sina;
	sol[0]=p1;
	sol[1]=p2;
	return 2;
}

void go()
{
	int t,n,i;
	double r,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lf",&n,&r);
		Circle a;
		Point res[5];
		a=Circle(Point(0,0),r);
		ans=2*r*PI;
		for(i=0;i<n;i++)
		{
			Circle c;
			c.input();
			int cnt=getCircleInter(a,c,res);
			if(cnt<=0) continue;
			double d=dist(c.c,a.c);
			ans-=2*r*acos((r*r+d*d-c.r*c.r)/(2*r*d));
			ans+=2*c.r*acos((c.r*c.r+d*d-r*r)/(2*c.r*d));
		}
		printf("%.10f\n",ans);
	}
}
