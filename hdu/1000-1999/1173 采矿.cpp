////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-16 15:55:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1173
////Problem Title: 
////Run result: Accept
////Run time:577MS
////Run memory:5872KB
//////////////////System Comment End//////////////////
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
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=10000+10;
const ll mod=1e6;
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
double dist(Point a,Point b)
{
	return fabs(a.x-b.x)+fabs(a.y-b.y);
}
pair<Point,double> fermat(vector<Point> p)
{  
	Point s;  
	double t=0,ds,dz,ans;  
	int i,j,k,n,flag,dir[4][2]={0,1,0,-1,1,0,-1,0};
	s=Point(0,0);
	n=p.size();
	for(i=0;i<n;i++)
	{  
		t+=fabs(p[i].x)+fabs(p[i].y);  
		s.x+=p[i].x;  
		s.y+=p[i].y;  
	}
	s.x/=n;  
	s.y/=n;  
	flag=0;  
	while(t>eps)  
	{  
		for(k=0;k<10;t/=2,k++)
		{
			for(i=0;i<4;i++)  
			{
				Point z;
				z.x=s.x+dir[i][0]*t;  
				z.y=s.y+dir[i][1]*t;  
				ds=dz=0;  
				for(j=0;j<n;j++)
				{  
					ds+=dist(s,p[j]);
					dz+=dist(z,p[j]);
				}  
				if(ds>dz)  
				{  
					s=z;
					ans=dz;
					flag=1;  
				} 
			}
		}
	}  
	if(!flag) ans=ds;  
	pair<Point,double> res;
	res=make_pair(s,ans);
	return res;
}
int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
		vector<Point> p;
		Point t;
		for(int i=0;i<n;i++)
		{
			t.input();
			p.push_back(t);
		}
		pair<Point,double> res;
		res=fermat(p);
		printf("%.2lf %.2lf\n",res.first.x,res.first.y);
	//	printf("%.2lf\n",res.second);
	}
	return 0;
}