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
int main()
{
	double a,v,l,d,w;
	while(~scanf("%lf%lf%lf%lf%lf",&a,&v,&l,&d,&w))
	{
		double t1=sqrt(2*d/a);
		double t2=v/a;
		double t=0;
		if(v>=w&&t1*a>w)
		{
			double dd=t2*v/2+(v-w)/a*(v+w)/2;
			if(t2>t1||dd>d) t=sqrt(4*(d+w*w/(2*a))/a)-w/a;
			else t=t2+(v-w)/a+(d-dd)/v;
			l-=d;
			double t3=(v-w)/a;
			double t4=sqrt((w*w/a+2*l)/a)-w/a;
			if(t3<=t4) printf("%.12f\n",t+t3+(l-(v+w)*t3/2)/v);
			else printf("%.12f\n",t+t4);
		}
		else
		{
			double lt=t2*t2*a/2;
			if(lt>l) printf("%.12f\n",sqrt(2*l/a));
			else printf("%.12f\n",t2+(l-lt)/v);
		}
	}
	return 0;
}