////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-07 20:36:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6080
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:2684KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
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
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
int cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
struct Line
{  
	Point p,v;
	Line(){}
	Line(Point a,Point b)
	{
		p=a;
		v=b-a;
	}
};
bool OnLeft(Line l,Point p){return cross(l.v,p-l.p)>0;}
bool OnRight(Line l,Point p){return cross(l.v,p-l.p)<0;}
int mp[510][510],m;
void floyd()
{
	int i,j,k;
	for(k=1;k<=m;k++)
	{
		for(i=1;i<=m;i++)
		{
			if(mp[i][k]!=INF)
			{
				for(j=1;j<=m;j++)
				{
					mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
				}
			}
		}
	}
}
int main()
{
	Point p1[510],p2[510];
	int n,i,j,k,flagl,flagr;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			p1[i].input();
		}
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			p2[i].input();
		}
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=m;j++)
			{
				mp[i][j]=INF;
			}
		}
		for(i=1;i<=m;i++)
		{
			for(j=i+1;j<=m;j++)
			{
				flagl=flagr=0;
				for(k=1;k<=n;k++)
				{
					if(OnLeft(Line(p2[i],p2[j]),p1[k])) flagl++;
					else if(OnRight(Line(p2[i],p2[j]),p1[k])) flagr++;
					if(flagl&&flagr) break;
				}
				if(!flagr) mp[j][i]=1;
				if(!flagl) mp[i][j]=1;
			}
		}
		floyd();
		int ans=INF;
		for(i=1;i<=m;i++)
		{
			ans=min(ans,mp[i][i]);
		}
		if(ans>m) puts("ToT");
		else printf("%d\n",m-ans);
	}
	return 0;
}