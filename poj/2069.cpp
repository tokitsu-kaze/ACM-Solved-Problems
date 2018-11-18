#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
using namespace std;
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
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/

struct Point
{  
	double x,y,z;
	Point(){}
	Point(double a,double b,double c):x(a),y(b),z(c){}
	void input(){scanf("%lf%lf%lf",&x,&y,&z);}
};
typedef Point Vector;
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y,a.z+b.z);}
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y,a.z-b.z);}
Vector operator *(Vector a,double p){return Vector(a.x*p,a.y*p,a.z*p);}  
Vector operator /(Vector a,double p){return Vector(a.x/p,a.y/p,a.z/p);}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y+a.z*b.z;}
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
double getres(Point t,Point *p,int n,int &pos)
{
	int i;
	double res=0,d;
	for(i=0;i<n;i++)
	{
		d=dist(t,p[i]);
		if(res<d)
		{
			res=d;
			pos=i;
		}
	}
	return res;
}
pair<Point,double> SA(Point *p,int n)
{  
	Point s;  
	double T=200000,t,ds,dz,ans;
	int i,j,k,flag,pos;
	s=Point(0,0,0);
	for(i=0;i<n;i++)
	{  
		s.x+=p[i].x;
		s.y+=p[i].y;
		s.z+=p[i].z;
	}
	s.x/=n;
	s.y/=n;
	s.z/=n;
	ans=getres(s,p,n,pos);
	while(T>eps)
	{
		double d=getres(s,p,n,pos);
		ans=min(ans,d);
		s=s+(p[pos]-s)/d*T;
		T*=0.99;
	}
	return MP(s,ans);
}
void go()
{
	Point p[111];
	int i,n;
	while(~scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++) p[i].input();
		if(n==1) puts("0.0000000000");
		else if(n==2) printf("%.10f\n",dist(p[0],p[1])/2);
		else printf("%.10f\n",SA(p,n).se);
	}
}