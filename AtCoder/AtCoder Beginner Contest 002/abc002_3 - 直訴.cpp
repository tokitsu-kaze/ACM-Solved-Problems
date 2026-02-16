#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1440+10;
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
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double calarea(Point c,Point b,Point a){return cross(b-a,c-a);}
int main()
{
	Point a,b,c;
	a.input();
	b.input();
	c.input();
	printf("%.10f\n",abs(calarea(a,b,c))/2);
	return 0;
}
