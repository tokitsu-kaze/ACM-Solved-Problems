#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
char mp[12][12];
int main()
{
	int t,n,i,j,ans;
	n=10;
	scanf("%d",&t);
	while(t--)
	{
		for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
		ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(mp[i][j]=='X') ans+=min({i,j,n-i+1,n-j+1});
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
