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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int sgn(int x)
{  
	if(x>0) return 1;
	if(x<0) return -1;
	return 0;
}
struct Point
{  
	int x,y;
	Point(){}
	Point(int a,int b)
	{
		x=a;
		y=b;
	}
	void input()
	{
		scanf("%d%d",&x,&y);
	}
};
typedef Point Vector;
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}  
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}  
Vector operator *(Vector a,double p){return Vector(a.x*p,a.y*p);}  
Vector operator /(Vector a,double p){return Vector(a.x/p,a.y/p);}
int cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
int dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
bool OnSeg(Point p,Point p1,Point p2)
{  
	return sgn(cross(p1-p,p2-p))==0&&sgn(dot(p1-p,p2-p))<=0;
}
int JudgePointInPolygon(Point p,vector<Point> poly)
{
	int cnt,n,k,d1,d2;
	cnt=0;
	n=poly.size();
	for(int i=0;i<n;i++)
	{
		if(OnSeg(p,poly[i],poly[(i+1)%n])) return 1;//在边上 
		k=sgn(cross(poly[(i+1)%n]-poly[i],p-poly[i]));
		d1=sgn(poly[i].y-p.y);
		d2=sgn(poly[(i+1)%n].y-p.y);
		if(k>0&&d1<=0&&d2>0) cnt++;
		if(k<0&&d2<=0&&d1>0) cnt--;
	} 
	if(cnt) return 1;//内部 
	else return 0;//外部 
}
int JudgeSegInter(Point a,Point b,Point c,Point d)
{
	double t1,t2,t3,t4;
	t1=cross(b-a,c-a);
	t2=cross(b-a,d-a);
	t3=cross(d-c,a-c);
	t4=cross(d-c,b-c);
	return sgn(t1)*sgn(t2)<0&&sgn(t3)*sgn(t4)<0;
}
int main()
{
	Point x;
	vector<Point> a,b;
	int i,j,flag=0;
	for(i=0;i<4;i++)
	{
		x.input();
		a.pb(x);
	}
	for(i=0;i<4;i++)
	{
		x.input();
		b.pb(x);
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			flag|=JudgeSegInter(a[i],a[(i+1)%4],b[j],b[(j+1)%4]);
		}
	}
	for(i=0;i<4;i++) flag|=JudgePointInPolygon(a[i],b);
	for(i=0;i<4;i++) flag|=JudgePointInPolygon(b[i],a);
	flag?puts("YES"):puts("NO");
	return 0;
}
