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
#define MAX 100000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	ll n,i,sum,a;
	while(~scanf("%I64d",&n))
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%I64d",&a);
			sum+=i*(a-1);
			sum+=a;
		}
		printf("%I64d\n",sum);
	}
    return 0;
}
/*
2 2 3   12
*/