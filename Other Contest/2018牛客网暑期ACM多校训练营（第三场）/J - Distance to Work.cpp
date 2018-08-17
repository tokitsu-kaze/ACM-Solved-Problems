#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e6+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/\
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
bool operator <(Point a,Point b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double length(Vector a){return sqrt(dot(a,a));}
Vector Normal(Vector x){return Point(-x.y,x.x)/length(x);}
Vector vecunit(Vector x){return x/length(x);}
double getangle(Vector v){return atan2(v.y, v.x);}
bool OnSeg(Point p, Point p1, Point p2)
{ 
	return sgn(cross(p1-p,p2-p))==0&&sgn(dot(p1-p,p2-p))<0;
}
struct Line
{ 
	Point p;
	Vector v;
	double ang;
	Line(){}
	Line(Point a,Vector b)
	{
		p=a;
		v=b;
		ang=atan2(v.y,v.x);
	}
	Point getpoint(double a)
	{ 
		return p+(v*a); 
	}
};
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
};
Point PointOfLineInter(Line a,Line b)
{
	Vector u=a.p-b.p;
	double t=cross(b.v,u)/cross(a.v,b.v);
	return a.p+a.v*t;
}
bool InCircle(Point x,Circle c){return sgn(c.r-length(c.c-x))>=0;}
int getSegCircleInter(Line l,Circle c,Point *sol) 
{ 
	Vector nor=Normal(l.v);
	Line l1=Line(c.c,nor); 
	Point p1=PointOfLineInter(l1,l); 
	double d=length(p1-c.c); 
	if(sgn(d-c.r)>0) return 0;
	Point p2=vecunit(l.v)*sqrt(c.r*c.r-d*d); 
	int res=0; 
	sol[res]=p1+p2; 
	if(OnSeg(sol[res],l.p,l.getpoint(1))) res++;
	sol[res]=p1-p2;
	if(OnSeg(sol[res],l.p,l.getpoint(1))) res++; 
	return res; 
}
double SegCircleArea(Circle c,Point a,Point b)
{ 
	double a1=getangle(a-c.c); 
	double a2=getangle(b-c.c); 
	double da=fabs(a1-a2); 
	if (sgn(da-PI)>0) da=PI*2.0-da; 
	return sgn(cross(b-c.c,a-c.c))*da*c.r*c.r/2.0; 
}
double PolyCiclrArea(Circle c,Point *p,int n)
{ 
	double res=0; 
	Point sol[2]; 
	p[n]=p[0]; 
	for(int i=0;i<n;i++)
	{
		double t1,t2; 
		int cnt=getSegCircleInter(Line(p[i],p[i+1]-p[i]),c,sol); 
		if(cnt==0) 
		{ 
			if(!InCircle(p[i],c)||!InCircle(p[i+1],c)) res+=SegCircleArea(c,p[i],p[i+1]); 
			else res+=cross(p[i+1]-c.c,p[i]-c.c)/2.0; 
		} 
		if(cnt==1) 
		{ 
			if(InCircle(p[i],c)&&!InCircle(p[i+1],c))
			{
				res+=cross(sol[0]-c.c,p[i]-c.c)/2.0;
				res+=SegCircleArea(c,sol[0],p[i+1]); 
			}
			else
			{
				res+=SegCircleArea(c,p[i],sol[0]);
				res+=cross(p[i+1]-c.c,sol[0]-c.c)/2.0; 
			}
		} 
		if(cnt==2) 
		{ 
			if((p[i]<p[i+1])^(sol[0]<sol[1])) swap(sol[0],sol[1]); 
			res+=SegCircleArea(c,p[i],sol[0]); 
			res+=cross(sol[1]-c.c,sol[0]-c.c)/2.0; 
			res+=SegCircleArea(c,sol[1],p[i+1]); 
		} 
	} 
	return fabs(res); 
}
double PolygonArea(Point *p,int n)
{
	double res=0;
	for(int i=0;i<n;i++)
	{
		res+=cross(p[i],p[(i+1)%n]); 
	}
	return fabs(res/2); 
}
Point pp[555];
int main()
{
	int n,i,m;
	double p,q,res,l,r,mid,now;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++) pp[i].input();
		res=PolygonArea(pp,n);
		scanf("%d",&m);
		while(m--)
		{
			Point t;
			t.input();
			scanf("%lf%lf",&p,&q);
			p=q-p;
			l=0;
			r=1e6;
			now=res/q*p;
			while(r-l>eps)
			{
				mid=(l+r)/2;
				double tmp=PolyCiclrArea(Circle(t,mid),pp,n);
				if(now<tmp) r=mid;
				else l=mid;
			}
			printf("%.10f\n",l);
		}
	}
	return 0;
}