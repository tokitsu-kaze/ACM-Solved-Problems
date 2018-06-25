////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-07 22:39:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5572
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1808KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const long double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
int sgn(__float128 x)
{  
	if(fabsl(x)<eps) return 0;
	else return x>0?1:-1;  
}
struct Point
{  
	__float128 x,y;
	Point(){}
	Point(__float128 a,__float128 b)
	{
		x=a;
		y=b;
	}
	void input()
	{
		double _x,_y;
		cin>>_x>>_y;
		x=_x;
		y=_y;
	}
};
typedef Point Vector;
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}  
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}  
Vector operator *(Vector a,__float128 p){return Vector(a.x*p,a.y*p);}  
Vector operator /(Vector a,__float128 p){return Vector(a.x/p,a.y/p);}
bool operator ==(Point a,Point b){return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}
__float128 dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
__float128 length(Vector a){return sqrtl(dot(a,a));}
__float128 cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
Vector vecunit(Vector x){return x/length(x);}
struct Line
{  
	Point p;
	Vector v; 
	__float128 ang;
	Line(){}
	Line(Point a,Vector b)
	{
		p=a;
		v=b;
		ang=atan2l(v.y,v.x);
		v=vecunit(v);
	}
	void twopoint(Point a,Point b)
	{
		p=a;
		v=b-a;
		ang=atan2l(v.y,v.x);
		v=vecunit(v);
	}
	Point getpoint(__float128 a)
	{  
		return p+(v*a);  
	}
};
struct Circle  
{  
    Point c;  
    __float128 r;  
    Circle(){}  
    Circle(Point a,__float128 b)
    {
		c=a;
		r=b;
	}
	void input()
	{
		c.input();
		double _r;
		cin>>_r;
		r=_r;
	}
}; 
int getLineCircleInter(Line l,Circle cc,Point *sol)
{ 
	__float128 a,b,c,d,e,f,g,delta,t;
	a=l.v.x;
	b=l.p.x-cc.c.x;
	c=l.v.y;
	d=l.p.y-cc.c.y;
	e=a*a+c*c;
	f=2*(a*b+c*d);
	g=b*b+d*d-cc.r*cc.r;  
	delta=f*f-4*e*g;
	if(sgn(delta)<0) return 0;
	if(sgn(delta)==0)
	{
		t=-f/(2*e);
		sol[0]=l.getpoint(t);
		return 1;
	}  
	else
	{
		t=(-f-sqrtl(delta))/(2*e);
		sol[0]=l.getpoint(t);
		t=(-f+sqrtl(delta))/(2*e);
		sol[1]=l.getpoint(t);
		return 2;
	}
}
__float128 TwoVectorAngle(Vector a,Vector b){return acosl(dot(a,b)/length(a)/length(b));}
bool OnSeg(Point p,Point p1,Point p2)
{  
	return sgn(cross(p1-p,p2-p))==0&&sgn(dot(p1-p,p2-p))<=0;
}
Vector Normal(Vector x){return Point(-x.y,x.x)/length(x);}
Point PointOfLineInter(Line a,Line b)
{
	Vector u=a.p-b.p;
	__float128 t=cross(b.v,u)/cross(a.v,b.v);
	return a.p+a.v*t;
}
int getSegCircleInter(Line l,Circle c,Point *sol)
{  
	Vector nor=Normal(l.v);
	Line l1=Line(c.c,nor);  
	Point p1=PointOfLineInter(l1,l);  
	__float128 d=length(p1-c.c);  
    if(sgn(d-c.r)>0) return 0;
	Point p2=vecunit(l.v)*sqrtl(c.r*c.r-d*d);  
	int res=0;  
	sol[res]=p1+p2;  
    if(OnSeg(sol[res],l.p,l.getpoint(1))) res++;
	sol[res]=p1-p2;
	if(OnSeg(sol[res],l.p,l.getpoint(1))) res++;  
	return res;  
}
//点A在射线L(p,v)上，不含端点
bool onRay(Point A, Line L)
{
	Vector w=A-L.p;
	if(sgn(cross(w,L.v))==0&&sgn(dot(w,L.v))>0) return 1;
	return 0;
}
Point project(Point A, Line L)
{
	return L.p + L.v * (dot(L.v, A - L.p)/dot(L.v, L.v));
}
Point mirrorPoint(Point A, Line L)
{
	Vector D = project(A, L);
	return D + (D - A);
}
int main()
{
	int t,cas=1;
	scanf("%d",&t);
	Line l,tmp,fa;
	Point a,b,sol[5];
	Circle c;
	while(t--)
	{
		c.input();
		a.input();
		b.input();
		l=Line(a,b);
		b.input();
		printf("Case #%d: ",cas++);
		tmp.twopoint(l.p,b);
		if(getSegCircleInter(tmp,c,sol))
		{
			puts("No");
			continue;
		}
		if(getLineCircleInter(l,c,sol)<=1)
		{
			if(onRay(b,l)) puts("Yes");
			else puts("No");
		}
		else
		{
			tmp.twopoint(sol[0],sol[1]);
			if(l.v==tmp.v) a=sol[0];
			else a=sol[1];
			if(OnSeg(b,l.p,a))
			{
				puts("Yes");
				continue;
			}
			fa.twopoint(a,c.c);
			b=mirrorPoint(b,fa);
			l.twopoint(a,l.p);
			if(onRay(b,l)) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
/*
10
0 0 1
0 2 0 -1
0 4
0 0 1
-2 2 1 -1
-3 3
0 0 1
0 2 0 -1
0 -4
*/