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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
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
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
double length(Vector a){return sqrt(dot(a,a));}
Vector vecunit(Vector x){return x/length(x);}
struct Line
{  
	Point p;
	Vector v; 
	double ang;
	Line(){}
	void twopoint(Point a,Point b)
	{
		p=a;
		v=vecunit(b-a);
		ang=atan2(v.y,v.x);
	}
	Point getpoint(double a)
	{  
		return p+(v*a);  
	}
};
int main()
{
	Point c,p;
	double r,d;
	while(~scanf("%lf",&r))
	{
		c.input();
		p.input();
		d=dist(c,p);
		if(sgn(d-r)>=0) printf("%.10lf %.10lf %.10lf\n",c.x,c.y,r);
		else if(c==p) printf("%.10lf %.10lf %.10lf\n",p.x,p.y+r/2,r/2);
		else
		{
			Line l;
			l.twopoint(p,c);
			Point ans;
			ans=l.getpoint((2*r-(r-d))/2);
			printf("%.10lf %.10lf %.10lf\n",ans.x,ans.y,(2*r-(r-d))/2);
		}
	}
	return 0;
}
/*
5 1 1 1 1
*/