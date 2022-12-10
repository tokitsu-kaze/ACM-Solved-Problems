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
const __float128 PI=acosl(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct Point
{  
	__float128 x,y;
	Point(){}
	Point(__float128 a,__float128 b)
	{
		x=a;
		y=b;
	}
	void output()
	{
		printf("%.10lf %.10lf\n",(double)x,(double)y);
	}
}p[MAX];
typedef Point Vector;
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}  
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}  
Vector operator *(Vector a,__float128 p){return Vector(a.x*p,a.y*p);}  
Vector operator /(Vector a,__float128 p){return Vector(a.x/p,a.y/p);}
__float128 cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
__float128 dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
__float128 dist(Point a,Point b){return sqrtl(dot(a-b,a-b));}
__float128 getang(Vector v){return atan2l(v.y,v.x);}
Point bcenter(int n)
{
	int i,j;
	Point t,ans;
	__float128 tp,s,tpx,tpy;
	s=t.x=t.y=0;
	for(i=1;i<=n;i++)
	{
		if(i==n) j=1;
		else j=i+1;
		tp=cross(p[i],p[j]);
		s+=tp/2;
		t=t+(p[i]+p[j])*tp;
	}
	ans=t/(6*s);
	return ans;
}
__float128 ang[MAX],dis[MAX];
int main()
{
	int i,n,q,op,f,t,x,y;
	__float128 a,tmp;
	while(~scanf("%d%d",&n,&q))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			p[i]=Point(x,y);
		}
		Point cen=bcenter(n);
		for(i=1;i<=n;i++)
		{
			dis[i]=dist(cen,p[i]);
			ang[i]=getang(p[i]-cen);
		}
		a=0;
		multiset<int> s;
		multiset<int> ::iterator it;
		s.insert(1);
		s.insert(2);
		while(q--)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d%d",&f,&t);
				it=s.lower_bound(f);
				s.erase(it);
				f=*s.begin();
				tmp=ang[f]+a;
				cen=cen+Point(dis[f]*cosl(tmp),dis[f]*sinl(tmp));
				cen.y-=dis[f];
				a+=PI/2-tmp;
				fmodl(a,PI);
				s.insert(t);
			}
			else
			{
				scanf("%d",&f);
				tmp=ang[f]+a;
				(cen+Point(dis[f]*cosl(tmp),dis[f]*sinl(tmp))).output();
			}
		}
	}
	return 0;
}