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
	int n,i,j,s[111],r[111],h[111],v[111],ans,temp,flag[111];
	while(~scanf("%d",&n))
	{
		mem(s,0);
		mem(r,0);
		mem(h,0);
		mem(v,0);
		mem(flag,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d%d",&s[i],&r[i],&h[i],&v[i]);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i!=j&&s[i]<s[j]&&r[i]<r[j]&&h[i]<h[j])
				{
					flag[i]=1;
					break;
				}
			}
		}
		ans=0;
		temp=INF;
		for(i=1;i<=n;i++)
		{
			if(!flag[i])
			{
				if(v[i]<temp)
				{
					temp=v[i];
					ans=i;
				}
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}