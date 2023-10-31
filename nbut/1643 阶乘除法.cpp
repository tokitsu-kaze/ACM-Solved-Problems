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
typedef __int64 ll;
int main()
{
	ll cas=1,n,i,j,s,flag;
	while(cin>>n)
	{
		flag=0;
		if(n==1) printf("Case %I64d: Impossible\n",cas++);
		else if(n&1)
		{
			printf("Case %I64d: %I64d %I64d\n",cas++,n,n-1);
			continue;
		}
		for(i=1;i<=sqrt(1.0*n);i++)
		{
			for(j=i+1,s=1;;j++)
			{
				s*=j;
				if(s==n)
				{
					flag=1;
					break;
				}
				if(s>n) break;
			}
			if(flag)
			{
				printf("Case %I64d: %I64d %I64d\n",cas++,j,i);
				break;
			}
		}
	}
    return 0;
}