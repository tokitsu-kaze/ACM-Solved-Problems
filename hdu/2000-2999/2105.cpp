////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-12-26 11:19:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2105
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1740KB
//////////////////System Comment End//////////////////
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
const int MAX=1e6+10;
const ll mod=1e9+7;
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
Point bcenter(vector<Point> p)
{
	int i,j,n;
	Point t,ans;
	double tp,s,tpx,tpy;
	s=t.x=t.y=0;
	n=p.size();
	for(i=0;i<n;i++)
	{
		if(i+1==n) j=0;
		else j=i+1;
		tp=cross(p[i],p[j]);
		s+=tp/2;
		t=t+(p[i]+p[j])*tp;
	}
	ans=t/(6*s);
	return ans;
}
int main()
{
	int t,i;
	while(~scanf("%d",&t)&&t)
	{
		while(t--)
		{
			vector<Point> p;
			for(i=0;i<3;i++)
			{
				Point t;
				t.input();
				p.pb(t);
			}
			Point res=bcenter(p);
			printf("%.1lf %.1lf\n",res.x,res.y);
		}
	}
	return 0;
}