#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int T,n,m,i,j,mp[55][55],now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		now=1;
		for(j=1;j<=m;j+=2)
		{
			mp[1][j]=now;
			now^=1;
			mp[1][j+1]=now;
		}
		for(j=1;j<=m;j++)
		{
			mp[2][j]=mp[1][j]^1;
		}
		for(i=3;i<=n;i+=2)
		{
			for(j=1;j<=m;j++)
			{
				mp[i][j]=mp[i-1][j];
				mp[i+1][j]=mp[i][j]^1;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				printf("%d%c",mp[i][j]," \n"[j==m]);
			}
		}
	}
	return 0;
}

