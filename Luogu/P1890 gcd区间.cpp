#include <bits/stdc++.h>
using namespace std;
int res[1010][1010],a[1010];
int main()
{
	int n,m,i,j,g,l,r;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		g=0;
		for(j=i;j<=n;j++)
		{
			g=__gcd(g,a[j]);
			res[i][j]=g;
		}
	}
	while(m--)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",res[l][r]);
	}
	return 0;
}
