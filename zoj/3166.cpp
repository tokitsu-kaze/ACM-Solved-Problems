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
#define MAX 10000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int n,c,h[110],i,j,k,m,flyd[110][110],a,b,d,min1,ans;
	while(cin>>n>>c)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				flyd[i][j]=INF;
			}
		}
		for(i=0;i<c;i++)
		{
			scanf("%d",&h[i]);
		}
		cin>>m;
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&d);
			flyd[a][b]=d;
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					flyd[i][j]=min(flyd[i][j],flyd[i][k]+flyd[k][j]);
				}
			}
		}
		min1=INF;
		ans=-1;
		for(i=0;i<c;i++)
		{
			if(flyd[h[i]][h[i]]<min1)
			{
				min1=flyd[h[i]][h[i]];
				ans=h[i];
			}
		}
		if(ans==-1) puts("I will nerver go to that city!");
		else cout<<ans<<endl;
	}
    return 0;
}