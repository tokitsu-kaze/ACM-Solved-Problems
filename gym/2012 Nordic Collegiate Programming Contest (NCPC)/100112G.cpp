#include <bits/stdc++.h>
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
const double eps=1e-6;
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
Vector operator /(Vector a,double p){return Vector(a.x/p,a.y/p);}
struct Line
{  
	Point p;//直线上任意一点  
	Vector v;//极角,即从x正半轴旋转到向量v所需要的角（弧度）  
	ll a,b,c;//直线一般式 
	Line(){}
	Line(Point a,Vector b)//点斜式 
	{
		p=a;
		v=b;
		LineGeneralEquation();
	}
	void twopoint(Point a,Point b)//两点式 
	{
		p=a;
		v=b-a;
		LineGeneralEquation();
	}
	void LineGeneralEquation()//计算一般式的a,b,c 
	{
		Point p1,p2;
		p1=p;
		p2=p+v;
		a=p2.y-p1.y;  
		b=p1.x-p2.x;  
		c=-a*p1.x-b*p1.y;
	}
};
ll cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
ll JudgeLineInter(Line a,Line b)
{
	if(cross(a.v,b.v)==0)
	{
		if(cross(a.p-b.p,b.v)==0) return 0;//重合 
		else return 1;//平行 
	}
	else return 2;//有交点 
}
int main()
{
	ll n,m,i,j,cnt,flag,temp;
	Line l[111];
	while(~scanf("%lld%lld",&n,&m))
	{
		for(i=0;i<m;i++)
		{
			Point a,b;
			a.input();
			b.input();
			l[i].twopoint(a,b);
		}
		cnt=m;
		for(i=0;i<m;i++)
		{
			for(j=i+1;j<m;j++)
			{
				if(JudgeLineInter(l[i],l[j])==0)
				{
					cnt--;
					break;
				}
			}
		}
		flag=1;
		for(i=1;i<m;i++)
		{
			if(JudgeLineInter(l[i],l[0])==2) flag=0;
		}
		m=cnt;
		ll ans=0;
	//	cout<<cnt<<endl;
	//	cout<<flag<<endl;
		if(flag)
	    {
	        ll temp=m+1;
	        if(temp>=n) puts("0");
	        else if((m+1)*2>=n) puts("1");
	        else
	        {
	            temp=(m+1)*2;
	            ll ans=1;
	            while(temp<n)
	            {
	                temp+=2;
	                ans++;
	            }
	            printf("%d\n",ans);
	        }
	    }
	    else
	    {
	        ll temp=m*2;
	        ll ans=0;
	        while(temp<n)
			{
				temp+=2;
				ans++;
			}
			printf("%d\n",ans);
	    }
	}
	return 0;
}
/*
4 3
1 1 2 2
0 -1 1 0
-1 0 0 1
1 3
0 0 1 1
-2 -2 -4 -4
-3 -3 1 1
*/