#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
typedef double db;
const db eps=1e-7;
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
	struct Line
	{  
		Point p;
		Vector v;
	};
	Line twopoint(Point a,Point b){return Line{a,b-a};} //两点式
	 
	//直线和点的位置关系  -1:左  |  1:右  |  0:在直线上 
	int LinePointRelation(Line l,Point p)
	{
		Point a,b;
		a=l.p;
		b=l.p+l.v;
		return sgn(cross(a-p,b-p));
	}
	
	struct Segment{Point a,b;};
	
	//点p在线段上
	//线段包含端点时改成<=
	bool PointOnSeg(Point p,Segment seg)
	{
		return sgn(cross(seg.a-p,seg.b-p))==0 &&
			   sgn(dot(seg.a-p,seg.b-p))<=0;
	}
	
	#undef type
}
using namespace Geometry;
struct Floyd
{
	#define type int
	const type inf=INF;
	static const int N=505;
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

Point a[505],b[505];
int spj(int n,int m)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(!(a[i]==a[1])) return 0;
	}
	for(i=1;i<=m;i++)
	{
		if(!(b[i]==a[1])) return 0;
	}
	return 1;
}
int main()
{
	int n,m,i,j,k,ok,f;
	db x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&x,&y,&z);
		a[i]={x,y};
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lf%lf%lf",&x,&y,&z);
		b[i]={x,y};
	}
	if(spj(n,m))
	{
		puts("1");
		return 0;
	}
	flyd.init(n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j) continue;
			ok=1;
			for(k=1;k<=m;k++)
			{
				f=LinePointRelation(twopoint(a[i],a[j]),b[k]);
				if(f>0||(f==0&&!PointOnSeg(b[k],Segment{a[i],a[j]})))
				{
					ok=0;
					break;
				}
			}
			if(ok) flyd.add_edge(i,j,1);
		}
	}
	flyd.work();
	if(flyd.min_circle==flyd.inf) puts("-1");
	else printf("%d\n",flyd.min_circle);
	return 0;
}
