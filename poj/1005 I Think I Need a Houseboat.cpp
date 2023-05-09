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
#define eps 1e-9
#define MAX 10000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int t,cas;
	double x,y;
	while(~scanf("%d",&t))
	{
		cas=1;
		while(t--)
		{
			scanf("%lf%lf",&x,&y);
			printf("Property %d: This property will begin eroding in year %d.\n",cas++,(int)((x*x+y*y)*3.1415926/100)+1);
		}
		puts("END OF OUTPUT.");
	}
    return 0;
}