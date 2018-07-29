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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
struct point
{
	double x,y;
	point(){}
	double operator ^(const point&b)const
	{
		return x*b.y-b.x*y;
	}
}p[MAX];
point bcenter(point p[],int n)
{
	int i,j;
	point t,ans;
	double tp,s,tpx,tpy;
	s=tpx=tpy=0;
	for(i=0;i<n;i++)
	{
		if(i+1==n) j=0;
		else j=i+1;
		tp=p[i]^p[j];
		s+=tp/2;
		tpx+=(p[i].x+p[j].x)*tp;
		tpy+=(p[i].y+p[j].y)*tp;
	}
	ans.x=tpx/(6*s);
	ans.y=tpy/(6*s);
	return ans;
}
int main()
{
	int t,n,i;
	point ans;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%lf%lf",&p[i].x,&p[i].y);
			}
			ans=bcenter(p,n);
			printf("%.2lf %.2lf\n",ans.x,ans.y);
		}
	}
	return 0;
}