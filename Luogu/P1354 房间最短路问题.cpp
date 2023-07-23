#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
typedef double db;
const db eps=1e-6;
namespace Geometry
{
	#define type db
	int sgn(type x)
	{
		if(abs(x)<eps) return 0;
		else return x>0?1:-1;
	}
	struct Point
	{  
		type x,y;
		Point operator +(const Point &a){return {x+a.x,y+a.y};}
		Point operator -(const Point &a){return {x-a.x,y-a.y};}
		Point operator -(){return {-x,-y};}
		Point operator *(const type k){return {x*k,y*k};}
		Point operator /(const type k){return {x/k,y/k};}
		bool operator <(const Point &a){return sgn(x-a.x)==0?sgn(y-a.y)<0:sgn(x-a.x)<0;}
		bool operator ==(const Point &a){return sgn(x-a.x)==0&&sgn(y-a.y)==0;}
	};
	typedef Point Vector;
	
	type dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;} //点积
	type cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;} //叉积
	db length(Vector a){return sqrtl(dot(a,a));} //向量长度
	type length2(Vector a){return dot(a,a);} //向量长度的平方
	db dist(Point a,Point b){return sqrtl(dot(a-b,a-b));} //两点距离
	type dist2(Point a,Point b){return dot(a-b,a-b);} //两点距离的平方
	Vector normal(Vector a){return Point{-a.y,a.x}/length(a);} //垂直法向量
	Vector vecunit(Vector a){return a/length(a);} //单位向量
	db ang(Vector a,Vector b){return acosl(dot(a,b)/length(a)/length(b));}//两个向量夹角 
	db ang(Vector v){return atan2(v.y,v.x);}
	Vector rotate(Vector a,db rad) //逆时针旋转 
	{
		return {a.x*cos(rad)-a.y*sin(rad),
				a.x*sin(rad)+a.y*cos(rad)};
	}
	
	struct Segment{Point a,b;};
	//线段相交判定
	bool JudgeSegInter(Segment x,Segment y)
	{
		db t1,t2,t3,t4;
		t1=cross(x.b-x.a,y.a-x.a);
		t2=cross(x.b-x.a,y.b-x.a);
		t3=cross(y.b-y.a,x.a-y.a);
		t4=cross(y.b-y.a,x.b-y.a);
		return sgn(t1)*sgn(t2)<0&&sgn(t3)*sgn(t4)<0;
	}
	
	#undef type
}
using namespace Geometry;

struct Floyd
{
	#define type double
	const type inf=INF;
	static const int N=100+10;
	int n;
	type mp[N][N],dis[N][N];
	type min_circle_3;// len(circle)>=3
	type min_circle;  // len(circle)>=1
	void init(int _n)
	{
		int i,j;
		n=_n;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				mp[i][j]=dis[i][j]=inf;
			}
		}
	}
	void add_edge(int x,int y,type w)
	{
		w=min(mp[x][y],w);
		mp[x][y]=dis[x][y]=w;
	}
	void work()
	{
		int i,j,k;
		min_circle_3=inf;
		for(k=1;k<=n;k++)
		{
			for(i=1;i<k;i++)
			{
				if(mp[i][k]==INF) continue;
				for(j=1;j<k;j++)
				{
					if(i==j||mp[k][j]==INF||dis[j][i]==INF) continue;
					min_circle_3=min(min_circle_3,mp[i][k]+mp[k][j]+dis[j][i]);
				}
			}
			for(i=1;i<=n;i++)
			{
				if(dis[i][k]==INF) continue;
				for(j=1;j<=n;j++)
				{
					if(dis[k][j]==INF) continue;
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		min_circle=inf;
		for(i=1;i<=n;i++) min_circle=min(min_circle,dis[i][i]);
	}
	#undef type
}flyd;
/*
flyd.init(n);
flyd.add_edge(x,y,w); x,y [1..n] x->y 
flyd.work();
*/

int main()
{
	int n,i,j,k,ok;
	double x,a,b,c,d;
	Segment tmp;
	scanf("%d",&n);
	vector<Segment> seg;
	vector<Point> p;
	p.push_back({0,5});
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf%lf%lf%lf",&x,&a,&b,&c,&d);
		seg.push_back(Segment{Point{x,0},Point{x,a}});
		seg.push_back(Segment{Point{x,b},Point{x,c}});
		seg.push_back(Segment{Point{x,d},Point{x,10}});
		p.push_back(Point{x,a});
		p.push_back(Point{x,b});
		p.push_back(Point{x,c});
		p.push_back(Point{x,d});
	}
	p.push_back({10,5});
	flyd.init(p.size());
	for(i=0;i<p.size();i++)
	{
		for(j=0;j<p.size();j++)
		{
			if(i==j) continue;
			tmp=Segment{p[i],p[j]};
			ok=1;
			for(k=0;k<seg.size();k++)
			{
				if(JudgeSegInter(seg[k],tmp)) ok=0;
			}
			if(ok) flyd.add_edge(i+1,j+1,dist(p[i],p[j]));
		}
	}
	flyd.work();
	printf("%.2f\n",flyd.dis[1][p.size()]);
	return 0;
}
