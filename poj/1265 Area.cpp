#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
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
struct Point
{  
	int x,y;
	Point(){}
	Point(int a,int b)
	{
		x=a;
		y=b;
	}
	void input()
	{
		scanf("%d%d",&x,&y);
	}
};
typedef Point Vector;
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);} 
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}  
int cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
int PolygonArea(Point *p,int n)
{ 
	int res=0;
	for(int i=0;i<n-1;i++)
	{
		res+=cross(p[i],p[i+1]);
	}
	return abs(res);  
}
int main()
{
	int t,cas=1,i,s,a,b,n;
	Point p[111];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			p[i].input();
			if(i) p[i]=p[i]+p[i-1];
		}
		s=PolygonArea(p,n);
		a=0;
		for(i=0;i<n;i++)
		{
			Point t=p[i]-p[(i+1)%n];
			a+=__gcd(abs(t.x),abs(t.y));
		}
		printf("Scenario #%d:\n",cas++);
		printf("%d %d %.1f\n",(s-a+2)/2,a,s*0.5);
		puts("");
	}
	return 0;
}