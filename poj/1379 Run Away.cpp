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
const double eps=1e-9;
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

double lx,ly;
int check(double x,double y)
{
	if(sgn(x)<0||sgn(y)<0||sgn(x-lx)>0||sgn(y-ly)>0) return 1;
	return 0;
}
double Rand(double r,double l)
{  
	return(rand()%((int)(l-r)*1000))/(1000.0+r);  
}
double getres(Point t,Point p[],int n)
{
	double res=1000000100;
	for(int i=0;i<n;i++)
	{  
		res=min(res,dist(t,p[i]));
	}
	return res;
}
pair<Point,double> SA(Point p[],int n)
{
	const double k=0.75;
	Point q[33];
	double dis[1111];  
	int i,j;
	for(i=1;i<=30;i++)
	{  
		q[i]=Point(Rand(0,lx),Rand(0,ly));
		dis[i]=getres(q[i],p,n);
	}
	double tmax=max(lx,ly);
	double tmin=1e-4;
	while(tmax>tmin)  
	{ 
		for(i=1;i<=30;i++)
		{
			for(j=1;j<=50;j++)
			{
				double ang=Rand(0,2*PI);  
				Point z;
				z.x=q[i].x+cos(ang)*tmax;
				z.y=q[i].y+sin(ang)*tmax;
				if(check(z.x,z.y)) continue;
				double temp=getres(z,p,n);
				if(temp>=dis[i])
				{
					dis[i]=temp;
					q[i]=z;
				}
			}
		}
		tmax*=k;
	}
	int pos=1;
	for(i=2;i<=30;i++)
	{
		if(dis[i]>=dis[pos])
		{
			pos=i;
		}
	}
	pair<Point,double> res;
	res=make_pair(q[pos],dis[pos]);
	return res;
}
int main()
{
	srand(time(0));
	int t,n,i;
	Point p[1111];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%d",&lx,&ly,&n);
		for(i=0;i<n;i++)
		{
			p[i].input();
		}
		pair<Point,double> res=SA(p,n);
//		cout<<res.second<<endl;
		printf("The safest point is (%.1lf, %.1lf).\n",res.first.x,res.first.y);
	}
	return 0;
}
/*
3
10000 10000 1
0 0
*/
