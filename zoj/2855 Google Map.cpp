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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-12
#define MAX 200+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
typedef long long ll;
int main()
{
//	freopen("in.txt","r",stdin);	
	int lv,k=0;
	double a,b,w,s,e,n,xm,ym;
	char ans[11111];
    while(~scanf("%lf%lf%d",&a,&b,&lv))
    {
		a=a*PI/180;
		b=log(tan(PI/4+(b*PI/180)/2));
		w=-180*PI/180;
		s=log(tan(PI/4+(-85*PI/180)/2));
		e=180*PI/180;
		n=log(tan(PI/4+(85*PI/180)/2));
		mem(ans,0);
		k=0;
		ans[k++]='t';
		while(lv--)
		{
			xm=(w+e)/2;
			ym=(s+n)/2;
			if(xm>a&&ym>b)
			{
				ans[k++]='t';
				e=xm;
				n=ym;
			}
			else if(xm>a&&ym<b)
			{
				ans[k++]='q';
				e=xm;
				s=ym;
			}
			else if(xm<a&&ym>b)
			{
				ans[k++]='s';
				w=xm;
				n=ym;
			}
			else if(xm<a&&ym<b)
			{
				ans[k++]='r';
				w=xm;
				s=ym;
			}
		}
		printf("%s\n",ans);
	}
    return 0;
}