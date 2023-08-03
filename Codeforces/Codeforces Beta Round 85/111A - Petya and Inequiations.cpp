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
#define MAX 100000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
typedef long long ll;
int main()
{
	ll n,x,y,t,r;
	while(~scanf("%I64d%I64d%I64d",&n,&x,&y))
	{
		t=y-n+1;
		if(t*t+n-1<x||t<=0)
		{
			puts("-1");
			continue;
		}
		else
		{
			printf("%I64d\n",t);
			n--;
			while(n--)
			{
				puts("1");
			}
		}
	}
    return 0;
}