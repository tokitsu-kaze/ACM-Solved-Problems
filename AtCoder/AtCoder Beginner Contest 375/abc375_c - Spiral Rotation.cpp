#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3000+10;
char mp[MAX][MAX],ans[MAX][MAX];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	for(j=1;j<=n/2;j++)
	{
		if(j%4==1)
		{
			for(i=j;i<=n-j+1;i++)
			{
				ans[j][i]=mp[n-i+1][j];
				ans[i][n-j+1]=mp[j][i];
				ans[n-j+1][n-i+1]=mp[i][n-j+1];
				ans[n-i+1][j]=mp[n-j+1][n-i+1];
			}
		}
		else if(j%4==2)
		{
			for(i=j;i<=n-j+1;i++)
			{
				ans[j][i]=mp[n-j+1][n-i+1];
				ans[i][n-j+1]=mp[n-i+1][j];
				ans[n-j+1][n-i+1]=mp[j][i];
				ans[n-i+1][j]=mp[i][n-j+1];
			}
		}
		else if(j%4==3)
		{
			for(i=j;i<=n-j+1;i++)
			{
				ans[j][i]=mp[i][n-j+1];
				ans[i][n-j+1]=mp[n-j+1][n-i+1];
				ans[n-j+1][n-i+1]=mp[n-i+1][j];
				ans[n-i+1][j]=mp[j][i];
			}
		}
		else if(j%4==0)
		{
			for(i=j;i<=n-j+1;i++)
			{
				ans[j][i]=mp[j][i];
				ans[i][n-j+1]=mp[i][n-j+1];
				ans[n-j+1][n-i+1]=mp[n-j+1][n-i+1];
				ans[n-i+1][j]=mp[n-i+1][j];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		ans[i][n+1]='\0';
		puts(ans[i]+1);
	}
	return 0;
}
