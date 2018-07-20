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
	int n,i,j,t;
	while(~scanf("%d",&n))
	{
		for(i=0;i<=n;i++)
		{
			t=n*2-2*i-1;
			if(t<0) t=0;
			while(t--)
			{
				printf(" ");
			}
			for(j=0;j<=i;j++)
			{
				if(i==n&&!j) printf("%d",j);
				else printf(" %d",j);
			}
			for(j=i-1;j>=0;j--)
			{
				printf(" %d",j);
			}
			puts("");
		}
		for(i=n-1;i>=0;i--)
		{
			t=n*2-2*i-1;
			if(t<0) t=0;
			while(t--)
			{
				printf(" ");
			}
			for(j=0;j<=i;j++)
			{
				if(i==n&&!j) printf("%d",j);
				else printf(" %d",j);
			}
			for(j=i-1;j>=0;j--)
			{
				printf(" %d",j);
			}
			puts("");
		}
	}
    return 0;
}