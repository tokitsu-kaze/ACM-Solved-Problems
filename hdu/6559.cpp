#include<bits/stdc++.h>
using namespace std;
double x,y,z,vx,vy,vz,h,r;
const double EPS=1e-8;
const double PI = 4.0 * atan(1.0);
int T;
struct point
{
	double x,y;
	point (double _x = 0,double _y = 0)
	{
		x = _x;
		y = _y;
	}
};
typedef point vect;
struct circle
{
	point c;
	double r;
	circle (point _c=point(0,0),double _r=0)
	{
		c = _c;
		r = _r;
	}
	point getpoint(double rad)
	{
		return point(c.x+cos(rad)*r , c.y+sin(rad)*r);
	}
};
double rad_change(double x)
{
	return x/PI*180;
}
double angle_change(double x)
{
	return x*PI/180;
}
int dcmp(double x)
{
	return x<-EPS?-1:(x>EPS?1:0);
}
bool operator < (const point& a,const point& b)
{
	if(a.x!=b.x)
	return a.x<b.x;
	return a.y<b.y;
}
bool operator == (const point& a,const point& b)
{
	return !dcmp(a.x-b.x)&&!dcmp(a.y-b.y);
}
bool operator != (const point& a,const point& b)
{
	return dcmp(a.x-b.x)||dcmp(a.y-b.y);
}
vect operator + (vect a,vect b)
{
	return vect (a.x+b.x,a.y+b.y);
}
vect operator - (point a,point b)
{
	return vect (a.x-b.x,a.y-b.y);
}
vect operator * (vect a,double b)
{
	return vect(a.x*b,a.y*b);
}
vect operator / (vect a,double b)
{
	return vect(a.x/b,a.y/b);
}
double dot(vect a,vect b)
{
	return a.x*b.x+a.y*b.y;
}
double cross(vect a,vect b)
{
	return a.x*b.y-b.x*a.y;
}
double vect_len(vect a)
{
	return sqrt(dot(a,a));
}
vect vect_rotate(vect a,double rad)
{
	return vect(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
vect vect_normal(vect a)
{
	double L=vect_len(a);
	return vect(-a.y/L,a.x/L);
}
double distance_point_line(point p,point p1,point p2)
{
	vect v1=p2-p1;
	vect v2=p-p1;
	return fabs(cross(v1,v2))/vect_len(v1);
}
double chk(double t)
{
	double newx=x+vx*t;
	double newy=y+vy*t;
	double newr=(h-z-vz*t)/h*r;
	if(dcmp(vect_len(vect(newx,newy))-newr)<=0)return 0;
	else return vect_len(vect(newx,newy))-newr;
}
int main()
{
	scanf("%d",&T);
	for(int cas=1;cas<=T;++cas)
	{
		printf("Case %d: ",cas);
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&r,&h,&x,&y,&z,&vx,&vy,&vz);
		double l=0;
		double r=100;
		while(dcmp(r-l)>0)
		{
			double mid=(l+r)/2,midl=(mid+l)/2,midr=(mid+r)/2;
			if(dcmp(chk(midl)-chk(midr))<=0)r=midr;
			else l=midl;
		}
		printf("%.8lf\n",l);
	}
	return 0;
}

