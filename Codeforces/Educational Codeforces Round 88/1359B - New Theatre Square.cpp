#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,m,x,y,ans,i,j;
	char s[1010];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&x,&y);
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			if(x*2<=y)
			{
				for(j=1;j<=m;j++)
				{
					if(s[j]=='.') ans+=x;
				}
			}
			else
			{
				for(j=2;j<=m;j++)
				{
					if(s[j-1]=='.' && s[j]=='.')
					{
						ans+=y;
						s[j-1]=s[j]='*';
					}
				}
				for(j=1;j<=m;j++)
				{
					if(s[j]=='.') ans+=x;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
