////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-07 17:05:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3685
////Problem Title: 
////Run result: Accept
////Run time:202MS
////Run memory:2836KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define  _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-10;
const int MAX=5e4+10;
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
typedef Point Vector;
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}  
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}  
Vector operator *(Vector a,double p){return Vector(a.x*p,a.y*p);}  
Vector operator /(Vector a,double p){return Vector(a.x/p,a.y/p);}
bool operator <(Point a,Point b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
bool operator ==(Point a,Point b){return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double Area(Point A,Point B,Point C)  
{  
    return cross(B-A, C-A)/2.0;  
}  
Point bcenter(Point *p, int n)  
{  
    Point G;  
    double s,sumS=0;  
    G.x=0,G.y=0;  
    for(int i=1; i<n-1; i++)  
    {  
        s=Area(p[0], p[i], p[i+1]);  
        sumS+=s;  
        G.x+=(p[0].x+p[i].x+p[i+1].x)*s;  
        G.y+=(p[0].y+p[i].y+p[i+1].y)*s;  
    }  
    G.x=G.x/sumS/3.0;  
    G.y=G.y/sumS/3.0;  
    return G;  
}  
int graham(Point *p,Point *ch,int n)  
{  
    sort(p,p+n);  
    int m=0;  
    for(int i=0; i<n; i++)  
    {  
        while(m>1&&cross(ch[m-1]-ch[m-2],p[i]-ch[m-1])<=0)  
            m--;  
        ch[m++]=p[i];  
    }  
    int k=m;  
    for(int i=n-2; i>=0; i--)  
    {  
        while(m>k&&cross(ch[m-1]-ch[m-2],p[i]-ch[m-1])<=0)  
            m--;  
        ch[m++]=p[i];  
    }  
    if(n>1) m--;  
    return m;  
}  
double length(Vector a){return sqrt(dot(a,a));}
double DisPointToSeg(Point p,Point a,Point b)
{
	if(a==b) return length(p-a);
	Vector v1,v2,v3;
	v1=b-a;
	v2=p-a;
	v3=p-b;
	if(sgn(dot(v1,v2))<0) return length(v2);
	else if(sgn(dot(v1,v3))>0) return length(v3);
	else return fabs(cross(v1,v2))/length(v1);
}
double DisPointToLine(Point p, Point a, Point b)
{
	Vector v1,v2;
	v1=b-a;
	v2=p-a; 
	return fabs(cross(v1,v2))/length(v1);
}
Point p[MAX],res[MAX];
int main() 
{
	int t,n,i,j,ans;
	scanf("%d",&t);
	while(t--)
	{
		Point temp,zx;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			p[i].input();
		}
		zx=bcenter(p,n);
		n=graham(p,res,n);
		ans=0;
		for(i=0;i<n;i++)
		{
			j=i+1;
			if(j==n) j=0;
			if(sgn(dot(zx-res[i],res[j]-res[i]))==0||sgn(dot(zx-res[j],res[i]-res[j]))==0) continue;
			if(sgn(DisPointToSeg(zx,res[i],res[j])-DisPointToLine(zx,res[i],res[j]))==0) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
