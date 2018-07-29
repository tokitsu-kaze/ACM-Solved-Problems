#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
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
bool operator <(Point a,Point b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
bool operator ==(Point a,Point b){return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
vector<Point> graham(vector<Point> p)
{  
	int n,m,k,i;
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	n=p.size();
	m=0;
	vector<Point> res(n+1);  
	for(i=0;i<n;i++)
	{  
		while(m>1&&cross(res[m-1]-res[m-2],p[i]-res[m-2])<=0) m--;  
		res[m++]=p[i];  
	}  
	k=m;  
	for(i=n-2;i>=0;i--)
	{  
		while(m>k&&cross(res[m-1]-res[m-2],p[i]-res[m-2])<=0) m--;  
	    res[m++]=p[i];  
	}  
	if(n>1) m--;  
	res.resize(m);
	return res;
}
Point randp()
{
	while(1)
	{
		Point p(rand(),rand());
		if(p.x+p.y<=32766) return p;
	}
	return Point(0,0);
}
void gao()
{
	srand(time(0));
	for(int i=4;i<=10;i++)
	{
		int t=20000000;
		double ans=0;
		while(t--)
		{
			vector<Point> p;
			for(int j=0;j<i;j++) p.pb(randp());
			p=graham(p);
			ans+=sz(p);
		}
		ans/=20000000;
		printf("%.6f,",ans);
	}
	puts("");
}
int main()
{
//	gao();
	double ans[]={0,0,0,3,3.666724,4.166653,4.566743,4.900092,5.185803,5.435999,5.658361};
	int n,i;
	Point p;
	for(i=0;i<3;i++) p.input();
	scanf("%d",&n);
	printf("%.4f\n",ans[n]);
	return 0;
}