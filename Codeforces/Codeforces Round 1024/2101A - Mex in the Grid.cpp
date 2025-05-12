#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=505+10;
int mp[MAX][MAX];
int main()
{
	int T,n,i,j,tot;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		tot=n*n-1;
		for(i=1;i<=(n+1)/2;i++)
		{
			for(j=i;j<=n-i+1;j++) mp[i][j]=tot--;
			for(j=i+1;j<=n-i+1;j++) mp[j][n-i+1]=tot--;
			for(j=n-i;j>=i;j--) mp[n-i+1][j]=tot--;
			for(j=n-i;j>i;j--) mp[j][i]=tot--;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%d%c",mp[i][j]," \n"[j==n]);
			}
		}
	}
	return 0;
}
