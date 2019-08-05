////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-11-11 19:02:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6242
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:3292KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
}p[MAX];
typedef Point Vector;
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}  
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}  
Vector operator *(Vector a,double p){return Vector(a.x*p,a.y*p);}  
Vector operator /(Vector a,double p){return Vector(a.x/p,a.y/p);}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double length(Vector a){return sqrt(dot(a,a));}
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
Point midseg(Point a,Point b){return (a+b)/2;}
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
Circle CircumscribedCircle(Point p1,Point p2,Point p3)
{  
	double bx=p2.x-p1.x,by=p2.y-p1.y;  
	double cx=p3.x-p1.x,cy=p3.y-p1.y;  
	double d=2*(bx*cy-by*cx);  
	double ex=(cy*(bx*bx+by*by)-by*(cx*cx+cy*cy))/d+p1.x;  
	double ey=(bx*(cx*cx+cy*cy)-cx*(bx*bx+by*by))/d+p1.y;  
	Point p=Point(ex,ey);
	return Circle(p,length(p1-p));
}
bool OnCircle(Point x,Circle c){return sgn(c.r-length(c.c-x))==0;}
bool check(Circle c,int n)
{
	int i,res=0,temp=n/2;
	if(n&1) temp++;
	for(i=0;i<n;i++)
	{
		if(OnCircle(p[i],c)) res++;
	}
	if(res>=temp) return 1;
	return 0;
}
ull llrand()
{
	return (
	(((ull)rand()<<24)&0xFF000000ul)|
	(((ull)rand()<<12)&0x00FFF000ul)|
	(((ull)rand()    )&0x00000FFFul));
}
void solve(int n)
{
	int i,j,k;
	Circle c;
	while(1)
	{
		i=llrand()%n;
		j=llrand()%n;
		k=llrand()%n;
		if(i==j||i==k||j==k) continue;
		c=CircumscribedCircle(p[i],p[j],p[k]);
		if(check(c,n))
		{
			if(sgn(fabs(c.c.x))>=0&&sgn(fabs(c.c.x)-mod+7)<=0&&sgn(fabs(c.c.y))>=0&&sgn(fabs(c.c.y)-mod+7)<=0&&sgn(c.r)>=0&&sgn(c.r-mod+7)<=0) break;
		}
	}
	printf("%.4lf %.4lf %.4lf\n",c.c.x,c.c.y,c.r);
}
int main()
{
	srand(time(0));
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++) p[i].input();
		if(n<=4)
		{
			if(n==1) printf("%.4lf %.4lf %.4lf\n",(double)0,(double)0,dist(Point(0,0),p[0]));
			else
			{
				Point pp=midseg(p[0],p[1]);
				printf("%.4lf %.4lf %.4lf\n",pp.x,pp.y,dist(p[0],p[1])/2);
			}
			continue;
		}
		solve(n);
	}
	return 0;
}