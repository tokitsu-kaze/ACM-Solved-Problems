#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=5e5+10;
const ll mod=1e9+7;
/*
ull llrand()
{
	return (
	(((ull)rand()<<24)&0xFF000000ul)|
	(((ull)rand()<<12)&0x00FFF000ul)|
	(((ull)rand()    )&0x00000FFFul));
}
void out(int *x,int *y)
{
	int i,j,flag[2]={-1,1};
	for(i=0;i<3;i++)
	{
		assert(abs(x[i])<=1000);
		assert(abs(y[i])<=1000);
		for(j=i+1;j<3;j++)
		{
			while(x[i]==x[j]&&y[i]==y[j]) x[i]=rand()%1000*flag[rand()%2];
			assert(!(x[i]==x[j]&&y[i]==y[j]));
		}
	}
	for(i=0;i<3;i++) printf("%d %d%c",x[i],y[i]," \n"[i==2]);
}
int main()
{
	srand(time(0));
	freopen("in.txt","w",stdout);
	int t=92,x[5],y[5],i,flag[2]={-1,1},m,mx,k,b;
	printf("%d\n",t);
	while(t>89)
	{
		for(i=0;i<3;i++) x[i]=rand()%1000*flag[rand()%2];
		y[0]=rand()%1000*flag[rand()%2];
		y[1]=y[2]=y[0];
		out(x,y);
		t--;
	}
	while(t>86)
	{
		for(i=0;i<3;i++) y[i]=rand()%1000*flag[rand()%2];
		x[0]=rand()%1000*flag[rand()%2];
		x[1]=x[2]=x[0];
		out(x,y);
		t--;
	}
	while(t>80)
	{
		mx=0;
		for(i=0;i<3;i++) x[i]=rand()%1000*flag[rand()%2],mx=max(mx,abs(x[i]));
		if(mx) m=1000/mx-1;
		while(!m) m=rand()%1000;
		k=(rand()%m+1)*flag[rand()%2];
		b=rand()%(1000-mx*abs(k));
		out(x,y);
		t--;
	}
	while(t--)
	{
		for(i=0;i<3;i++)
		{
			x[i]=rand()%1000*flag[rand()%2];
			y[i]=rand()%1000*flag[rand()%2];
		}
		out(x,y);
	}
	return 0;
}
*/

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
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}  
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}  
Vector operator *(Vector a,double p){return Vector(a.x*p,a.y*p);}  
Vector operator /(Vector a,double p){return Vector(a.x/p,a.y/p);}
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
Point midseg(Point a,Point b){return (a+b)/2;}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double dist(Point a,Point b){return dot(a-b,a-b);}
Point CircumCircle(Point a,Point b,Point c)  
{  
	Point res;   
    double a1=b.x-a.x,b1=b.y-a.y,c1=(a1*a1+b1*b1)/2;  
    double a2=c.x-a.x,b2=c.y-a.y,c2=(a2*a2+b2*b2)/2;  
    double d=a1*b2-a2*b1;  
    return Point(a.x+(c1*b2-c2*b1)/d,a.y+(a1*c2-a2*c1)/d);
}
double PolygonArea(Point *p,int n)
{ 
	double res=0;
	for(int i=0;i<n;i++)
	{
		res+=cross(p[i],p[(i+1)%n]);  
	}
	return fabs(res/2);  
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int t,i,j,k;
	Point p[5],res,temp;
	double ans,mx;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<3;i++) p[i].input();
		ans=1e18;
		for(i=0;i<3;i++)
		{
			for(j=i+1;j<3;j++)
			{
				temp=midseg(p[i],p[j]);
				mx=0;
				for(k=0;k<3;k++)
				{
					mx=max(mx,dist(temp,p[k]));
				}
				if(mx<ans)
				{
					ans=mx;
					res=temp;
				}
			}
		}
		if(sgn(PolygonArea(p,3)))
		{
			temp=CircumCircle(p[0],p[1],p[2]);
			mx=0;
			for(i=0;i<3;i++)
			{
				mx=max(mx,dist(temp,p[i]));
				if(mx<ans)
				{
					ans=mx;
					res=temp;
				}
			}
		}
		printf("%.4lf %.4lf %.4lf\n",res.x,res.y,ans);
	}
	return 0;
}
/*
100
0 0 0 1 0 2
0 0 0 -1 0 1
0 0 0 -1 0 5
1 5 10 32 -1 -1
0 0 0 2 2 0
0 0 -1 2 2 0
0 0 1 1 2 0
0 0 1 2 2 0
*/