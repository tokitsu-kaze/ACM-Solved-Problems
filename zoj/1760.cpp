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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 10000000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int a[1001],i,j,k,count;
    while(~scanf("%d",&a[0]))
    {
		if(a[0]==-1) break;
		for(i=1;;)
		{
			scanf("%d",&a[i++]);
			if(a[i-1]==0) break;
		}
		for(j=0,count=0;j<i-1;j++)
		{
			for(k=0;k<i-1;k++)
			{
				if(a[j]*2==a[k]) count++;
			}
		}
		printf("%d\n",count);
    }
    return 0;
}