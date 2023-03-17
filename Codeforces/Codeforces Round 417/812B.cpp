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
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=1e4;
int n,m;
char mp[111][111];
int main()
{
	int i,j,dp[25][5],p1,p2,t;
	while(~scanf("%d%d",&n,&m))
	{
		m+=2;
		getchar();
		mem(mp,0);
		t=-1;
		for(i=1;i<=n;i++)
		{
			scanf("%s",mp[i]);
			int flag=0;
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='1') flag=1;
			}
			if(flag&&t==-1) t=i;
		}
		if(t==-1)
		{
			puts("0");
			continue;
		}
		mem(dp,0);
		p1=0;
		for(j=0;j<m;j++)
		{
			if(mp[n][j]=='1')
			{
				p1=j;
			}
		}
		if(n==1)
		{
			printf("%d\n",p1);
			continue;
		}
		else
		{
			dp[n-1][0]=p1*2+1;
			dp[n-1][1]=m;
		}
		for(i=n-1;i>t;i--)
		{
			p1=0;
			p2=0;
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='1')
				{
					p1=j;
					if(!p2) p2=j;
				}
			}
			if(!p2) p2=m-1;
			dp[i-1][0]=min(dp[i][0]+2*p1+1,dp[i][1]+m);
			dp[i-1][1]=min(dp[i][1]+2*(m-1-p2)+1,dp[i][0]+m);
//			cout<<dp[i-1][0]<<" "<<dp[i-1][1]<<endl;
		}
		p1=0;
		p2=0;
		for(j=0;j<m;j++)
		{
			if(mp[t][j]=='1')
			{
				p1=j;
				if(!p2) p2=j;
			}
		}
		int ans=t==n?dp[t][0]+p1:min(dp[t][0]+p1,dp[t][1]+(m-1-p2));
		printf("%d\n",ans);
	}
	return 0;
}