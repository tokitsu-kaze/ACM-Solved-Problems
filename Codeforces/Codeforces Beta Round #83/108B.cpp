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
int a[100010];
int main()
{
	int n,i,flag,t,k;
	while(~scanf("%d",&n))
	{
		map<int,int> m;
		k=0;
		mem(a,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&t);
			if(!m[t])
			{
				m[t]=1;
				a[k++]=t;
			}
			
		}
		sort(a,a+k);
		flag=0;
		for(i=0;i<k-1;i++)
		{
			if(a[i]*2>a[i+1])
			{
				flag=1;
				break;
			}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
    return 0;
}