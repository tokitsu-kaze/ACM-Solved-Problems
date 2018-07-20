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
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int n,s,q,flag;
	while(~scanf("%d",&n))
	{
		flag=0;
		q=n/7;
		for(s=0;;s++)
		{
			if(q*7+4*s==n)
			{
				flag=1;
				break;
			}
			else if(q*7+4*s>n)
			{
				if(!q) break;
				else q--;
			}
		}
		if(!flag) puts("-1");
		else
		{
			while(s--)
			{
				printf("4");
			}
			while(q--)
			{
				printf("7");
			}
			puts("");
		}
	}
    return 0;
}