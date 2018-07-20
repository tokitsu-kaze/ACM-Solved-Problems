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
#define MAX 1000000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int n,a,b,flag[6],flag1,i;
	while(~scanf("%d",&n))
	{
		mem(flag,0);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			flag[a]++;
			flag[b]++;
		}
		flag1=0;
		for(i=1;i<=5;i++)
		{
			if(flag[i]>=3||flag[i]<=1)
			{
				flag1=1;
				puts("WIN");
				break;
			}
		}
		if(!flag1) puts("FAIL");
	}
    return 0;
}