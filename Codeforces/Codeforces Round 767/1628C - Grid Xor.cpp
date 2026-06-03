#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int mp[MAX][MAX];
int main()
{
	int T,n,i,j,x,ans,pre;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		ans=0;
		pre=0;
		for(x=1;x<=n;x+=2)
		{
			i=1;
			j=x;
			while(j>=1)
			{
				pre^=mp[i][j];
				i+=2;
				j-=2;
			}
			ans^=pre;
		}
		pre=0;
		for(x=1;x<=n;x+=2)
		{
			i=n;
			j=x;
			while(j>=1)
			{
				pre^=mp[i][j];
				i-=2;
				j-=2;
			}
			ans^=pre;
		}
		pre=0;
		for(x=n;x>=1;x-=2)
		{
			ans^=pre;
			i=1;
			j=x;
			while(j<=n)
			{
				pre^=mp[i][j];
				i+=2;
				j+=2;
			}
		}
		pre=0;
		for(x=n;x>=1;x-=2)
		{
			ans^=pre;
			i=n;
			j=x;
			while(j<=n)
			{
				pre^=mp[i][j];
				i-=2;
				j+=2;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

