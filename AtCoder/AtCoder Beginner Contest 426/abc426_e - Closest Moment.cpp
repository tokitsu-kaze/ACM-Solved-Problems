#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double eps=1e-9;
const int MAX=2e5+10;
int sgn(double x)
{  
	if(abs(x)<eps) return 0;
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
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}//点积
double length(Vector a){return sqrt(dot(a,a));}//向量的模 
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}//叉积 
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}//两点距离 
Vector vecunit(Vector x){return x/length(x);}//单位向量
double DisPointToSeg(Point p,Point a,Point b)
{
	if(a==b) return length(p-a);
	Vector v1,v2,v3;
	v1=b-a;
	v2=p-a;
	v3=p-b;
	if(sgn(dot(v1,v2))<0) return length(v2);
	else if(sgn(dot(v1,v3))>0) return length(v3);
	else return fabs(cross(v1,v2))/length(v1);
}
int main()
{
	int T,i;
	Point sa,sb,sc,sd,ta,tb,tc,td;
	double tm,ans,l,r,lm,rm,tl,tr;
	scanf("%d",&T);
	while(T--)
	{
		sa.input();
		sb.input();
		ta.input();
		tb.input();
		if(dist(sa,sb)>dist(ta,tb))
		{
			swap(sa,ta);
			swap(sb,tb);
		}
		tm=dist(sa,sb);
		sc=vecunit(sb-sa);
		tc=vecunit(tb-ta);
		ans=dist(sa,ta);
		sd=sa+sc*tm;
		td=ta+tc*tm;
		ans=min(ans,DisPointToSeg(sb,td,tb));
		l=0;
		r=tm;
		for(i=0;i<50;i++)
		{
			rm=(l+r)/2;
			lm=(rm+r)/2;
			tl=dist(sa+sc*lm,ta+tc*lm);
			tr=dist(sa+sc*rm,ta+tc*rm);
			if(tr<=tl) r=lm;
			else l=rm;
		}
		ans=min(ans,dist(sa+sc*l,ta+tc*l));
		printf("%.10f\n",ans);
	}
	return 0;
}
