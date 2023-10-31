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
const int MAX=100+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
double H,h,d;
double fx(double x)
{
	return d-x+H-d*(H-h)/x;
}
int main()
{
	int t;
	double l,r,lm,rm;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%lf%lf%lf",&H,&h,&d);
			l=d-d*h/H;
			r=d;
			while(r-l>eps)
			{
				lm=(2*l+r)/3;
				rm=(l+2*r)/3;
				if(fx(lm)>fx(rm)) r=rm;
				else l=lm;
			}
			printf("%.3lf\n",fx(l));
		}
	}
	return 0;
}