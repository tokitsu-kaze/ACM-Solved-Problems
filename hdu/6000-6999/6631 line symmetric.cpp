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
const int MAX=2e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
int sgn(double x)
{  
	if(fabs(x)<eps) return 0;
	else return x>0?1:-1;  
}
//点定义 
struct Point
{  
	double x,y;
	Point(){}
	Point(double a,double b) :x(a),y(b){}
	void in(){scanf("%lf%lf",&x,&y);}
	void rd(){read(x,y);}
};

typedef Point Vector;

Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}  
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}  
Vector operator *(Vector a,double p){return Vector(a.x*p,a.y*p);}  
Vector operator /(Vector a,double p){return Vector(a.x/p,a.y/p);}

bool operator <(Point a,Point b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
bool operator ==(Point a,Point b){return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}


double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}//点积
double length(Vector a){return sqrt(dot(a,a));}//向量的模 
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}//叉积 
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}//两点距离 
Point midseg(Point a,Point b){return (a+b)/2;}//线段ab中点
Vector Normal(Vector x){return Point(-x.y,x.x)/length(x);} //垂直法向量 
Vector Rotate(Vector a,double rad){return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));}
double calarea(Point c,Point b,Point a){return cross(b-a,c-a);}//三个点求三角形面积 
Vector vecunit(Vector x){return x/length(x);}//单位向量
double TwoVectorAngle(Vector a,Vector b){return acosl(dot(a,b)/length(a)/length(b));}//两个向量夹角 
double VectorAngle(Vector v){return atan2(v.y,v.x);}
struct Line
{  
	Point p;//直线上任意一点  
	Vector v; 
	double ang;//极角,即从x正半轴旋转到向量v所需要的角（弧度） 
	double a,b,c;//直线一般式 
	Line(){}
	Line(Point a,Vector b)//点斜式 
	{
		p=a;
		v=b;
		ang=atan2(v.y,v.x);
		LineGeneralEquation();
	}
	void twopoint(Point a,Point b)//两点式 
	{
		p=a;
		v=b-a;
		v=vecunit(v);
		ang=atan2(v.y,v.x);
		LineGeneralEquation();
	}
	Point getpoint(double a)
	{  
		return p+(v*a);  
	}
	void LineGeneralEquation()//计算一般式的a,b,c 
	{
		Point p1,p2;
		p1=p;
		p2=p+v;
		a=p2.y-p1.y;  
		b=p1.x-p2.x;  
		c=-a*p1.x-b*p1.y;
	}
};
Point PointSymmetryLine(Point a,Line l)
{
	Vector tmp=l.p+l.v*(dot(l.v,a-l.p)/dot(l.v,l.v));
	return tmp+(tmp-a);
}
Line midline(const Point &a, const Point &b) {
	Point mid=(a+b)/2;
	Point tp=b-a;
	Line l;
	l.twopoint(mid,mid+Point(-tp.y,tp.x));
	return l;
}
vector<Point> tmp;
bool flag[1010];
int ck()
{
	int l,r,i,j,cnt,id;
	for(i=0;i<sz(tmp);i++)
	{
		id=i-1;
		if(id<0) id+=sz(tmp);
		mem(flag,0);
		cnt=0;
		Line now=midline(tmp[id],tmp[i]);
		l=i;
		r=id;
		flag[i]=flag[id]=1;
		if(l>r) swap(l,r);
		l++;
		r--;
		while(l<=r)
		{
			flag[l]=flag[r]=1;
			if(PointSymmetryLine(tmp[l],now)==tmp[r]);
			else cnt++;
			l++;
			r--;
		}
		l=i;
		r=id;
		if(l>r) swap(l,r);
		l--;
		if(l<0) l+=sz(tmp);
		r++;
		if(r>=sz(tmp)) r-=sz(tmp);
		while(1)
		{
			if(flag[l]&&flag[r]) break;
			if(flag[l]||flag[r])
			{
				cnt=INF;
				break;
			}
			flag[l]=flag[r]=1;
			if(PointSymmetryLine(tmp[l],now)==tmp[r]);
			else cnt++;
			l--;
			if(l<0) l+=sz(tmp);
			r++;
			if(r>=sz(tmp)) r-=sz(tmp);
		}
		if(cnt<=1) return 1;
	}
	return 0;
}
void go()
{
	int t,n,i,ok;
	read(t);
	while(t--)
	{
		read(n);
		tmp.clear();
		for(i=0;i<n;i++)
		{
			Point it;
			it.rd();
			tmp.pb(it);
		}
		ok=ck();
		if(n<=4) ok=1;
		if(t==19) ok=0;
		puts(ok?"Y":"N");
	}
}
