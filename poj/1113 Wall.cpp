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
const int MAX=1000+10;
const int EDGE=100000+10;//�ߵ�����
typedef long long ll;
struct point
{
	double x,y;
	point(){}
	void input()
	{
		scanf("%lf%lf",&x,&y);
	}
	point(double a,double b)
	{
		x=a;
		y=b;
	}
	point operator -(const point &b)const
	{
		return point(x-b.x,y-b.y);
	}
	double operator ^(const point &b)const
	{
		return x*b.y-b.x*y;
	}
	double operator *(const point &b)const
	{
		return x*b.x+y*b.y;
	}
}p[MAX],res[MAX];
double dis(point a,point b)
{
	return sqrt((a-b)*(a-b));
}
int sgn(double x)
{
	if(fabs(x)<eps) return 0;
	if(x<0) return -1;
	else return 1;
}
int cmp(point a,point b)
{
	double temp=(a-p[0])^(b-p[0]);
	if(sgn(temp)>0) return 1;
	else if(sgn(temp)==0&&sgn(dis(a,p[0])-dis(b,p[0]))<=0) return 1;
	else return 0;
}
int graham(int n)
{
	int k=0,top=0,i;
	point p0;
	if(n==0) return 0;
	p0=p[0];
	for(i=1;i<n;i++)
	{
		if((p0.y>p[i].y)||(p0.y==p[i].y&&p0.x>p[i].x))
		{
			p0=p[i];
			k=i;
		}
	}
	swap(p[k],p[0]);
	sort(p+1,p+n,cmp);
	res[0]=p[0];
	if(n==1) return 1;
	res[1]=p[1];
	if(n==2) return 2;
	top=2;
	for(i=2;i<n;i++)
	{
		while(top>1&&sgn((res[top-1]-res[top-2])^(p[i]-res[top-2]))<=0)
		{
			top--;
		}
		res[top++]=p[i];
	}
	return top;
}
int main()
{
	int t,n,i,k;
	double sum,r;
	while(~scanf("%d%lf",&n,&r))
	{
		for(i=0;i<n;i++)
		{
			p[i].input();
		}
		k=graham(n);
		sum=0;
		for(i=1;i<k;i++)
		{
			sum+=dis(res[i-1],res[i]);
		}
		if(k>2) sum+=dis(res[k-1],res[0]);
		sum+=2*r*PI;
		printf("%.0f\n",sum);
		if(t) puts("");
	}
	return 0;
}
