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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct Point
{  
	ll x,y;
	Point(){}
	Point(ll a,ll b)
	{
		x=a;
		y=b;
	}
	void input()
	{
		scanf("%lld%lld",&x,&y);
	}
};
typedef Point Vector;
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}  
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}  
Vector operator *(Vector a,ll p){return Vector(a.x*p,a.y*p);}  
Vector operator /(Vector a,ll p){return Vector(a.x/p,a.y/p);}

bool operator <(Point a,Point b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
bool operator ==(Point a,Point b){return (a.x-b.x)==0&&(a.y-b.y)==0;}
ll cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
ll dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}

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
ll DisPointToLine(Point p, Point a, Point b)
{
	Vector v1,v2;
	v1=b-a;
	v2=p-a; 
	return cross(v1,v2);
}
int vis[MAX];
int main()
{
	int i,n,j,k,tag,x,y;
	while(~scanf("%d",&n))
	{
		vector<Point> p,res,tmp;
		for(i=0;i<n;i++)
		{
			Point t;
			t.input();
			p.pb(t);
			tmp.pb(t);
		}
		if(n<=4)
		{
			puts("YES");
			continue;
		}
		res=graham(tmp);
		if(sz(res)>4)
		{
			puts("NO");
			continue;
		}
		if(sz(res)<=2)
		{
			puts("YES");
			continue;
		}
		if(sz(res)==4)
		{
			tag=0;
			for(i=0;i<sz(p);i++)
			{
				if((DisPointToLine(p[i],res[0],res[2]))==0);
				else if((DisPointToLine(p[i],res[1],res[3]))==0);
				else tag=1;
			}
			if(!tag)
			{
				puts("YES");
				continue;
			}
			tag=0;
			for(i=0;i<sz(p);i++)
			{
				if((DisPointToLine(p[i],res[0],res[1]))==0);
				else if((DisPointToLine(p[i],res[2],res[3]))==0);
				else tag=1;
			}
			if(!tag)
			{
				puts("YES");
				continue;
			}
			tag=0;
			for(i=0;i<sz(p);i++)
			{
				if((DisPointToLine(p[i],res[0],res[3]))==0);
				else if((DisPointToLine(p[i],res[1],res[2]))==0);
				else tag=1;
			}
			if(!tag)
			{
				puts("YES");
				continue;
			}
			else
			{
				puts("NO");
				continue;
			}
		}
		if(sz(res)==3)
		{
			mem(vis,0);
			tag=0;
			for(i=0;i<sz(p);i++)
			{
				if((DisPointToLine(p[i],res[0],res[1]))==0) vis[i]=1;
			}
			x=-1;
			for(i=0;i<sz(p);i++)
			{
				if(vis[i]) continue;
				if(x==-1)
				{
					if(res[2]==p[i]);
					else x=i;
					continue;
				}
				if((DisPointToLine(p[i],res[2],p[x]))==0);
				else tag=1;
			}
			if(!tag)
			{
				puts("YES");
				continue;
			}
			mem(vis,0);
			tag=0;
			for(i=0;i<sz(p);i++)
			{
				if((DisPointToLine(p[i],res[0],res[2]))==0) vis[i]=1;
			}
			x=-1;
			for(i=0;i<sz(p);i++)
			{
				if(vis[i]) continue;
				if(x==-1)
				{
					if(res[1]==p[i]);
					else x=i;
					continue;
				}
				if((DisPointToLine(p[i],res[1],p[x]))==0);
				else tag=1;
			}
			if(!tag)
			{
				puts("YES");
				continue;
			}
			mem(vis,0);
			tag=0;
			for(i=0;i<sz(p);i++)
			{
				if((DisPointToLine(p[i],res[1],res[2]))==0) vis[i]=1;
			}
			x=-1;
			for(i=0;i<sz(p);i++)
			{
				if(vis[i]) continue;
				if(x==-1)
				{
					if(res[0]==p[i]);
					else x=i;
					continue;
				}
				if((DisPointToLine(p[i],res[0],p[x]))==0);
				else tag=1;
			}
			if(!tag)
			{
				puts("YES");
				continue;
			}
			else puts("NO");
		}
	}
	return 0;
}