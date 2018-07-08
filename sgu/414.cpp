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
const double eps=1e-4;
const int MAX=2e5+10;
const ll mod=1e9+7;
/***************************************head**********************************************/
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
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double length(Vector a){return sqrt(dot(a,a));}
Vector Rotate(Vector a,double rad){return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));}
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
	void twopoint(Point a,Point b)
	{
		p=a;
		v=b-a;
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
	Point getpoint(double a)
	{
		return Point(c.x+cos(a)*r,c.y+sin(a)*r);
	}
};
Point PointOfLineInter(Line a,Line b)
{
	Vector u=a.p-b.p;
	double t=cross(b.v,u)/cross(a.v,b.v);
	return a.p+a.v*t;
}
int vis[MAX];
Circle cir[MAX];
Point p[MAX];
Line l[MAX];
Line get_line(Circle a,Circle b)//获得正交线
{
	Line AB;
	AB.twopoint(a.c,b.c);
	Point P,Q;
	Vector R;
	double d=length(a.c-b.c);
	double t=(d*d+a.r*a.r-b.r*b.r)/(2*d*d);
	P=AB.getpoint(t);
	R=a.c-b.c;
	Q=Point(-R.y,R.x)+P;
	Line res;
	res.twopoint(P,Q);
	return res;
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
bool judge(Point P,int n)//判点是否在圆内
{
	int i;
	for(i=0;i<n;i++)
		if(sgn(length(cir[i].c-P)-cir[i].r)<=0)return false;
	return true;
}
int cmp(Circle a,Circle b)//排序比较
{
	if(a.c==b.c)return a.r<b.r;
	else if(sgn(a.c.x-b.c.x)==0)return a.c.y<b.c.y;
	else return a.c.x<b.c.x;
}
int Orthogonal_Circle(int n,Circle *cir,Circle &res)
{
	int i,j,k;
	if(n==1) return -2;
	int m=0,t=0;
	sort(cir,cir+n,cmp);//排序，用于查找重合以及同心圆
	//找出所有正交线
	for(i=0;i<n-1;i++)
	{
		if(cir[i].c==cir[i+1].c&&sgn(cir[i].r-cir[i+1].r)==0)continue;//重合的圆可以跳过
		else if(cir[i].c==cir[i+1].c)break;//同心圆（非重合）就输出-1
		l[m++]=get_line(cir[i],cir[i+1]);
	}
	if(i<n-1) return -1;
	//找出所有正交线的交点
	for(i=0;i<m-1;i++)
	{
		int tmp=JudgeLineInter(l[i],l[i+1]);
		//重合无视，平行无解
		if(tmp==0) continue;
		if(tmp==1) return -1;//平行的时候
		p[t++]=PointOfLineInter(l[i],l[i+1]);
	}
	if(t==0) return -2;//全部重合的时候
	int flag=0;
	for(i=0;i<t-1;i++)
	{
		if(p[i]==p[i+1])continue;
		flag=1;//相交点不同
	}
	if(flag) return -1;
	if(!flag)
	{
		if(judge(p[0],n)) //判断点是否在圆内，在圆就是不符合的点
		{
			res=Circle(p[0],sqrt(pow(length(p[0]-cir[0].c),2)-cir[0].r*cir[0].r));
			return 1;
		}
		else return -1;
	}
}
int main()
{
	int n,i;
	double a,b,c;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf",&a,&b,&c);
			cir[i]=Circle(Point(a,b),c);
		}
		Circle ans;
		int res=Orthogonal_Circle(n,cir,ans);
		if(res!=1) printf("%d\n",res);
		else printf("%.10f %.10f %.10f\n",ans.c.x,ans.c.y,ans.r);
	}
	return 0;
}
