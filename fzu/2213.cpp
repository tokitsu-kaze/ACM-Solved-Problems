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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll; 
int main()
{ 
	int t;
	double x1,y1,x2,y2,r1,r2,d;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>x1>>y1>>r1>>x2>>y2>>r2;
			d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
			if(d==0) puts("-1");
			else if(d>r1+r2) puts("4");
			else if(d<r1+r2&&d>fabs(r1-r2)) puts("2");
			else if(d==r1+r2) puts("3");
			else if(d<fabs(r1-r2)) puts("0");
			else if(d==fabs(r1-r2)) puts("1");
		}
	}
    return 0;
}