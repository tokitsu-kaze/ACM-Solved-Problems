#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0) 
using namespace std;
typedef long long ll;
int main()
{
	double t1,t2,res,dis,x1,y1,r1,x2,y2,r2,minr,maxr;
	while(~scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2))
	{
		minr=r1<r2?r1:r2;
		maxr=r1>r2?r1:r2;
		dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		if(dis>=r1+r2) res=0;
		else if(dis+minr<=maxr) res=PI*minr*minr;
		else
		{
			t1=(dis*dis+r1*r1-r2*r2)/(2*r1*dis);
			t2=(dis*dis+r2*r2-r1*r1)/(2*r2*dis);
			res=acos(t1)*r1*r1+acos(t2)*r2*r2-sin(acos(t1))*r1*dis;
		}
		printf("%.3f\n",res);
	}
	return 0;
}