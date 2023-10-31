#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
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
Point a,b;
int main()
{
	double k,x,y,z;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		a.input();
		b.input();
		scanf("%lf",&k);
		x=k*k-1;
		y=2*b.y-2*k*k*a.y;
		z=k*k*(a.x*a.x+a.y*a.y)-b.x*b.x-b.y*b.y;
		if(k<1) puts("N");
		else if(k==1)
		{
			if(y||sgn(y)==0&&sgn(z)<=0) puts("N");
			else puts("Y");
		}
		else
		{
			if(sgn(y*y-4*x*z)>=0) puts("N");
			else puts("Y");
		}
	}
	return 0;
}
/*
100
-1 1 -2 1 2
-1 1 -2 1 2.01
*/
