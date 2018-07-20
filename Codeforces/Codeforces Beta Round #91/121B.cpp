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
char a[MAX];
int main()
{
	int n,k,i;
	while(~scanf("%d%d",&n,&k))
	{
		getchar();
		mem(a,0);
		gets(a);
		for(i=0;i<n-1&&k;i++)
		{
			
			if(a[i]=='4'&&a[i+1]=='7')
			{
				if(i&1)//even
				{
					if(i-1>=0&&a[i-1]=='4') k%=2;
					if(!k) break;
					a[i]='7';
					k--;
					if(k&&i-1>=0&&a[i-1]=='4')
					{
						a[i]='4';
						k--;
					}
					else continue;
				}
				else//odd
				{
					a[i+1]='4';
					k--;
				}
			}
		}
		printf("%s\n",a);
	}
    return 0;
}