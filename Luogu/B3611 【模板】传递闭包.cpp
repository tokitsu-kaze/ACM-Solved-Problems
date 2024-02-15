#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mp[105][105];
int main()
{
	int n,m,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++) scanf("%d",&mp[i][j]);
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				mp[i][j]|=mp[i][k]&mp[k][j];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++) printf("%d%c",mp[i][j]," \n"[j==n]);
	}
	return 0;
}
