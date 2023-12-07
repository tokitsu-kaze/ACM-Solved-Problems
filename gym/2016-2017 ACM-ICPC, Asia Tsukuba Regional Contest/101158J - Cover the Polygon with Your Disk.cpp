#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
double r;
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
bool operator ==(Point a,Point b){return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}//点积
double length(Vector a){return sqrt(dot(a,a));}//向量的模 

double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}//叉积 
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}//两点距离 
Point midseg(Point a,Point b){return (a+b)/2;}//线段ab中点
Vector Normal(Vector x){return Point(-x.y,x.x)/length(x);} //垂直法向量 
Vector Rotate(Vector a, double rad){return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));}
double calarea(Point c,Point b,Point a){return cross(b-a,c-a);}//三个点求三角形面积 
Vector vecunit(Vector x){return x/length(x);}//单位向量
double VectorAngle(Vector v){return atan2(v.y,v.x);}
struct Line
{  
	Point p;//直线上任意一点  
	Vector v;//极角,即从x正半轴旋转到向量v所需要的角（弧度）  
	double ang;
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
bool OnSeg(Point p,Point p1,Point p2)
{  
	return sgn(cross(p1-p,p2-p))==0&&sgn(dot(p1-p,p2-p))<0;
}
Point PointOfLineInter(Line a,Line b)//线段交点
{
	Vector u=a.p-b.p;
	double t=cross(b.v,u)/cross(a.v,b.v);
	return a.p+a.v*t;
}
bool InCircle(Point x,Circle c){return sgn(c.r-length(c.c-x))>=0;}//在圆内(包括圆上) 
int getSegCircleInter(Line l,Circle c,Point *sol)//线段与圆的交点
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
double SegCircleArea(Circle c,Point a,Point b) //线段切割圆  
{  
	double a1=VectorAngle(a-c.c);  
	double a2=VectorAngle(b-c.c);  
	double da=fabs(a1-a2);  
	if (sgn(da-PI)>0) da=PI*2.0-da;  
	return sgn(cross(b-c.c,a-c.c))*da*c.r*c.r/2.0;  
}
double PolyCiclrArea(Circle c,Point *p,int n)//多边形与圆面积交  
{  
	double res=0;  
	Point sol[2];  
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
double getres(Point t,Point *p,int n)
{
	double res=0;
	res=PolyCiclrArea(Circle(t,r),p,n);
	return res;
}
pair<Point,double> SA(Point *p,int n)
{  
	Point s;  
	double T=100,t,ds,dz,ans;  
	int i,j,k,flag,dir[5][2]={0,0,0,1,0,-1,1,0,-1,0};
	s=Point(0,0);
	for(i=0;i<n;i++)
	{  
		s.x+=p[i].x;  
		s.y+=p[i].y;  
	}
	s.x/=n;  
	s.y/=n;  
	ans=0;
	for(k=1;k<=100000;k++)
	{
		t=T/k;
		for(i=0;i<5;i++)  
		{
			Point z;
			z.x=s.x+dir[i][0]*t;  
			z.y=s.y+dir[i][1]*t;  
			dz=getres(z,p,n);
			if(dz>ans)  
			{  
				ans=dz;
				s=z;
			} 
		}
	}
	pair<Point,double> res;
	res=make_pair(s,ans);
	return res;
}
int main()
{
	int n,i;
	Point p[12];
	while(~scanf("%d%lf",&n,&r))
	{
		for(i=0;i<n;i++)
		{
			p[i].input();
		}
		p[n]=p[0];
	//	printf("%.6lf\n",getres(Point(3,3),p,n+1));
		pair<Point,double> ans=SA(p,n);
		printf("%.6lf\n",ans.se);
	}
	return 0;
}