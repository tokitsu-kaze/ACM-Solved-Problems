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
struct node
{
	char a[11];
	int t;
}a[11],b[11];
int main()
{
	int n,k,i,j,ans,tmax,tmin;
	char temp[11],t[11];
	while(~scanf("%d%d",&n,&k))
	{
		mem(temp,0);
		for(i=0;i<k;i++)
		{
			temp[i]=i+'0';
		}
		for(i=0;i<n;i++)
		{
			mem(a[i].a,0);
			getchar();
			scanf("%s",a[i].a);
		}
		ans=INF;
		do
		{
			for(i=0;i<n;i++)
			{
				mem(t,0);
				for(j=0;j<k;j++)
				{
					t[j]=a[i].a[temp[j]-'0'];
				}
				a[i].t=atoi(t);
			}
			tmax=0;
			tmin=INF;
			for(i=0;i<n;i++)
			{
				tmax=max(tmax,a[i].t);
				tmin=min(tmin,a[i].t);
			}
			ans=min(ans,tmax-tmin);
		}while(next_permutation(temp,temp+k));
		printf("%d\n",ans);
	}
    return 0;
}