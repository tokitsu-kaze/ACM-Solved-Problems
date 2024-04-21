#include<bits/stdc++.h>
using namespace std;
char mp[33][33];
int main()
{
	int n,m,i,j,x,y,ans,cnt;
	n=m=21;
	for(i=0;i<n;i++) scanf("%s",mp[i]);
	ans=0;
	for(i=0;i+3<n;i++)
	{
		for(j=0;j+3<m;j++)
		{
			cnt=0;
			for(x=0;x<4;x++)
			{
				for(y=0;y<4;y++)
				{
					cnt+=(mp[i+x][j+y]=='1');
				}
			}
			ans=max(ans,cnt);
		}
	}
	printf("%d\n",ans);
	return 0;
}
