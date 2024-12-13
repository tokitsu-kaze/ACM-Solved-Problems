#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e5+10;
const int mod=998244353;
int main()
{
	int n,m,d,i,j,ii,jj,x,y,ans,now;
	char mp[22][22];
	scanf("%d%d%d",&n,&m,&d);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='#') continue;
			for(ii=1;ii<=n;ii++)
			{
				for(jj=1;jj<=m;jj++)
				{
					if(mp[ii][jj]=='#') continue;
					if(ii==i && jj==j) continue;
					now=0;
					for(x=1;x<=n;x++)
					{
						for(y=1;y<=m;y++)
						{
							if(mp[x][y]=='#') continue;
							if(abs(x-i)+abs(y-j)<=d) now++;
							else if(abs(x-ii)+abs(y-jj)<=d) now++;
						}
					}
					ans=max(ans,now);
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
