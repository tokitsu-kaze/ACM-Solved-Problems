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
#define MAX 200+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
typedef long long ll;
int main()
{
	int n,m,i,j,k,ans[111][111],a,cas=1;
//	freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)&&(n+m))
    {
		mem(ans,0);
		for(i=0;i<3;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<m;k++)
				{
					scanf("%d",&a);
					ans[j][k]+=a;
				}
			}
		}
		printf("Case %d:\n",cas++);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				ans[i][j]/=3;
				if(!j)printf("%d",ans[i][j]);
				else printf(",%d",ans[i][j]);
			}
			puts("");
		}
	}
    return 0;
}