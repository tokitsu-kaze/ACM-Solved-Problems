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
const int MAX=1000000+10;
const ll mod=10000;
int main()
{
	int n,cas;
	double d,t;
	cas=1;
	while(~scanf("%lf%d%lf",&d,&n,&t)&&n)
	{
		double s=n*3.1415927*d/12/5280;
		printf("Trip #%d: %.2lf %.2lf\n",cas++,s,s/(t/3600));
	}
	return 0;
}