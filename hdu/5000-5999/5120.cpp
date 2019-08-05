////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-11 17:04:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5120
////Problem Title: 
////Run result: Accept
////Run time:639MS
////Run memory:1736KB
//////////////////System Comment End//////////////////
#include<bits/stdc++.h>
using namespace std;
const double EPS=1e-8;
const double PI=acos(-1);
struct point
{
    double x,y;
    point(double _x=0,double _y=0)
    {
        x=_x;
        y=_y;
    }
};
struct circle
{
    point c;
    double r;
    circle(){}
    circle(point _c,double _r)
    {
        c=_c;
        r=_r;
    }
};

int sgn(double x)
{
    return x>EPS?1:x<-EPS?-1:0;
}
double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double CircleCircleArea(circle c1,circle c2)
{
    double d=dist(c1.c,c2.c);
    if(sgn(d-(c1.r+c2.r))>=0||sgn(c1.r)==0||sgn(c2.r)==0)return 0;
    else if(sgn(d-fabs(c1.r-c2.r))<=0)
    {
        double r=min(c1.r,c2.r);
        return r*r*PI;
    }
    else
    {
        double a,b,m,n,x,y;
        a=acos((d*d+c1.r*c1.r-c2.r*c2.r)/(2*d*c1.r));
        b=acos((d*d+c2.r*c2.r-c1.r*c1.r)/(2*d*c2.r));
        m=a*c1.r*c1.r;
        n=b*c2.r*c2.r;
        x=c1.r*c1.r*sin(a)*cos(a);
        y=c2.r*c2.r*sin(b)*cos(b);
        return m+n-(x+y);
    }
}
double r,R,X1,X2,Y1,Y2,ans;
circle C1,c1,C2,c2;
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&r,&R,&X1,&Y1,&X2,&Y2);
        C1=circle(point(X1,Y1),R);
        c1=circle(point(X1,Y1),r);
        C2=circle(point(X2,Y2),R);
        c2=circle(point(X2,Y2),r);
        ans=CircleCircleArea(C1,C2)-CircleCircleArea(c1,C2)-CircleCircleArea(C1,c2)+CircleCircleArea(c1,c2);
        printf("Case #%d: %.6lf\n",cas,ans);
    }

    return 0;
}