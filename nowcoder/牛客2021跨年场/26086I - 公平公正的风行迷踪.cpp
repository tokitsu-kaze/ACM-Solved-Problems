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
		freopen("12.in","r",stdin);
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
#define double long double
int sgn(double x)
{  
	if(fabs(x)<eps) return 0;
	else return x>0?1:-1;  
}
struct Point
{ 
	int id;
	double x,y;
	Point(){}
	Point(double a,double b)
	{
		x=a;
		y=b;
	}
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
Vector vecunit(Vector x){return x/length(x);}//单位向量
struct Line
{  
	Point p,a,b;//直线上任意一点  
	Vector v; 
	double ang;//极角,即从x正半轴旋转到向量v所需要的角（弧度） 
	Line(){}
	Line(Point _a,Vector _b)//点斜式 
	{
		p=_a;
		v=_b;
		ang=atan2(v.y,v.x);
	}
	void twopoint(Point _a,Point _b)//两点式 
	{
		p=_a;
		a=_a;
		b=_b;
		v=_b-_a;
		ang=atan2(v.y,v.x);
	}
	Point getpoint(double a)
	{  
		return p+(v*a);  
	}
}l[5],tmp_line;

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
	Point getpoint(double a) //根据圆心角求点坐标  
	{  
        return Point(c.x+cos(a)*r,c.y+sin(a)*r);  
	}  
}; 
//求两直线交点 
Point PointOfLineInter(Line a,Line b)
{
	Vector u=a.p-b.p;
	double t=cross(b.v,u)/cross(a.v,b.v);
	return a.p+a.v*t;
}
//点p在线段上
//线段包含端点时改成<=  
bool OnSeg(Point p,Point p1,Point p2)
{  
//	debug(cross(p1-p,p2-p))
//	debug(dot(p1-p,p2-p))
	return sgn(cross(p1-p,p2-p))==0&&sgn(dot(p1-p,p2-p))<=0;
}

//点p在直线ab的投影  
Point GetLineProjection(Point p,Point a,Point b)
{  
	Vector v=b-a;  
	return a+v*(dot(v,p-a)/dot(v,v));
}

//线段与圆的交点
int getSegCircleInter(Line l,Circle c,Point *sol)
{  
	Point k=GetLineProjection(c.c,l.a,l.b);
	Point tmp=k-c.c;
	double d=sqr(c.r)-(sqr(tmp.x)+sqr(tmp.y));  
    if(sgn(d)==-1) return 0;
	Point p2=vecunit(l.v)*sqrt(max((double)0.0,d));  
	int res=0;  
	sol[res]=k-p2;
    if(OnSeg(sol[res],l.p,l.getpoint(1))) res++;
	sol[res]=k+p2; 
	if(OnSeg(sol[res],l.p,l.getpoint(1))) res++;  
	return res;  
}
//点A在射线L(p,v)上，不含端点
int onRay(Point a, Line l)
{
	Vector w=a-l.p;
	if(sgn(cross(w,l.v))==0&&sgn(dot(w,l.v))>0) return 1;
	return 0;
}
int JudgeLineInter(Line a,Line b)
{
	if(sgn(cross(a.v,b.v))==0)
	{
		if(sgn(cross(a.p-b.p,b.v))==0) return 0;//重合 
		else return 1;//平行 
	}
	else return 2;//有交点 
}
bool InCircle(Point x,Circle c){return sgn(c.r-length(c.c-x))>=0;}
Point p[1010],res[5],tmp;
int flag[1010];
void go()
{
	int n,r,i,x,y,ok,id,cnt,no_hit;
	while(read(n,r))
	{
		for(i=1;i<=n;i++)
		{
			read(x,y);
			p[i]=Point(x,y);
			p[i].id=i;
		}
		sort(p+1,p+1+n);
		l[0].twopoint(Point(0,0),Point(1e6,0));
		l[1].twopoint(Point(1e6,0),Point(1e6,1e6));
		l[2].twopoint(Point(1e6,1e6),Point(0,1e6));
		l[3].twopoint(Point(0,1e6),Point(0,0));
		Line now_line;
		now_line=l[0];
		VI ans;
		mem(flag,0);
		no_hit=0;
		while(1)
		{
			ok=0;
			debug(now_line.a.x,now_line.a.y,now_line.b.x,now_line.b.y)
			//debug(now_line.a.x,now_line.a.y)
			VI pos;
			vector<Point> pres;
			double dmn;
			for(i=1;i<=n;i++)
			{
				if(flag[i]) continue;
				if(InCircle(now_line.a,Circle(p[i],r)))
				{
					res[0]=now_line.a;
					ok=1;
					id=i;
					pos.clear();
					pres.clear();
					break;
				}
				cnt=getSegCircleInter(now_line,Circle(p[i],r),res);
				if(!cnt) continue;
				if(OnSeg(res[0],now_line.a,now_line.b))
				{
					pos.pb(i);
					pres.pb(res[0]);
				}
				if(cnt==2)
				{
					if(OnSeg(res[1],now_line.a,now_line.b))
					{
						pos.pb(i);
						pres.pb(res[1]);
					}
				}
				
			}
			if(sz(pos))
			{
				assert(!ok);
				assert(sz(pos)==sz(pres));
				dmn=1e18;
				id=-1;
				for(i=0;i<sz(pos);i++)
				{
					if(dist(now_line.p,pres[i])<dmn)
					{
						dmn=dist(now_line.p,pres[i]);
						res[0]=pres[i];
						id=pos[i];
					}
				}
				if(id!=-1) ok=1;
			}
			
			if(!ok || (res[0]==p[id]))
			{
				if(ok&&res[0]==p[id])
				{
					ans.pb(p[id].id);
					flag[id]=1;
				}
				else
				{
					no_hit++;
					if(no_hit>=10) break;
				}
				
				ok=0;
				for(i=0;i<4;i++)
				{
					if(OnSeg(now_line.b,l[i].a,l[i].b))
					{
						if(now_line.b==l[i].b)
						{
							ok=1;
							now_line=l[(i+1)%4];
							break;
						}
						ok=1;
						now_line.twopoint(now_line.b,l[i].b);
						break;
					}
				}
				assert(ok);
				continue;
			}
			ans.pb(p[id].id);
			flag[id]=1;
			debug(p[id].id)
			debug(res[0].x,res[0].y)
		//	debug(p[id].x,p[id].y)
			no_hit=0;
			ok=0;
			for(i=0;i<4;i++)
			{
				tmp_line.twopoint(res[0],p[id]);
				cnt=JudgeLineInter(tmp_line,l[i]);
				if(cnt==0) continue;
				tmp=PointOfLineInter(tmp_line,l[i]);
				if(tmp==res[0]) continue;
				debug(tmp.x,tmp.y)
				debug(l[i].a.x,l[i].a.y)
				debug(l[i].b.x,l[i].b.y)
				if(!OnSeg(tmp,l[i].a,l[i].b)) continue;
				if(onRay(tmp,tmp_line))
				{
					now_line.twopoint(p[id],tmp);
					ok=1;
		//			break;
				}
			}
			assert(ok);
		}
		printf("%d\n",sz(ans));
        println(ans);
	}
}

