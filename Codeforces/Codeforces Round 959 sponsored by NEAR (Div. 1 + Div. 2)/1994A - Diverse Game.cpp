#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,m,i,j,a[12][12];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		if(n==1 && m==1)
		{
			puts("-1");
			continue;
		}
		for(i=1;i<=n;i++)
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				a[i][j]++;
				if(a[i][j]==n*m+1) a[i][j]=1;
				printf("%d%c",a[i][j]," \n"[j==m]);
			}
		}
	}
	return 0;
}
