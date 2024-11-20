#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=500+10;
char mp[MAX][MAX];
int main()
{
	int T,i,j,n,m;
	m=4;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
		for(i=n;i;i--)
		{
			for(j=1;j<=m;j++)
			{
				if(mp[i][j]=='#')
				{
					printf("%d",j);
					if(i==1) puts("");
					else printf(" ");
					break;
				}
			}
		}
	}
	return 0;
}
