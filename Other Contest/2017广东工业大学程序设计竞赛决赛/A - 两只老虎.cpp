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
	int t,a,b,c;
    while(~scanf("%d",&t))
    {
		while(t--)
		{
			scanf("%d%d%d",&a,&b,&c);
			c/=4;
			a=(c*2-a)/2;
			b=c-b;
			printf("%d\n",c-a-b);
		} 
	}
    return 0;
}