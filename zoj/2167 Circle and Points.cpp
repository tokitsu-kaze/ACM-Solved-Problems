#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=10000;
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
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
double lx=10,ly=10;
double Rand(double r,double l)
{  
	return(rand()%((int)(l-r)*1000))/(1000.0+r);  
}
int check(double x,double y)
{
	if(sgn(x)<0||sgn(y)<0||sgn(x-lx)>0||sgn(y-ly)>0) return 1;
	return 0;
}
int getres(Point t,Point p[],int n)
{
	int res=0;
	for(int i=0;i<n;i++)
	{  
		if(sgn(1.0001-dist(t,p[i]))>=0) res++;
	}
	return res;
}
int SA(Point p[],int n)
{
	srand(time(0));
	const double k=0.75;
	const int c1=20;
	const int c2=20;
	Point q[c1+10];
	int cnt[c1+10];
	int i,j;
	for(i=1;i<=c1;i++)
	{  
		q[i]=Point(Rand(0,lx),Rand(0,ly));
		cnt[i]=getres(q[i],p,n);
	}
	double tmax=max(lx,ly);
	double tmin=1e-3;
	while(tmax>tmin)  
	{
		for(i=1;i<=c1;i++)
		{
			for(j=1;j<=c2;j++)
			{
				double ang=Rand(0,2*PI);  
				Point z;
				z.x=q[i].x+cos(ang)*tmax;
				z.y=q[i].y+sin(ang)*tmax;
				if(check(z.x,z.y)) continue;
				int temp=getres(z,p,n);
				if(temp>cnt[i])
				{
					cnt[i]=temp;
					q[i]=z;
				}
			}
		}
		tmax*=k;
	}
	int pos=1;
	for(i=2;i<=c1;i++)
	{
		if(cnt[i]>cnt[pos])
		{
			pos=i;
		}
	}
	return cnt[pos];
}
int main()
{
	int t,n,i;
	Point p[311];
	while(~scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
		{
			p[i].input();
		}
		if(n==1)
		{
			puts("1"); 
			continue;
		}
		printf("%d\n",SA(p,n));
	}
	return 0;
}