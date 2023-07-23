#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
typedef double db;
const db eps=1e-6;
namespace Geometry
{
	#define type ll
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
int main()
{
	int t,n,m,i,j,k,ok;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
		for(i=1;i<=m;i++) scanf("%lld%lld",&b[i].x,&b[i].y);
		flyd.init(n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j) continue;
				ok=1;
				for(k=1;k<=m;k++)
				{
					if(LinePointRelation(twopoint(a[i],a[j]),b[k])!=-1)
					{
						ok=0;
						break;
					}
				}
				if(ok) flyd.add_edge(i,j,1);
			}
		}
		flyd.work();
		if(flyd.min_circle_3==flyd.inf) puts("-1");
		else printf("%d\n",flyd.min_circle_3);
	}
	return 0;
}
