#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
ll v[105][105][105],bit[105][105][105];
int main()
{
	int n,q,x1,x2,y1,y2,z1,z2,i,j,k;
	scanf("%d",&n);
	bit[0][0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				scanf("%lld",&v[i][j][k]);
				bit[i][j][k]=v[i][j][k]
				 +bit[i][j][k-1]+bit[i][j-1][k]+bit[i-1][j][k]
				 -bit[i][j-1][k-1]-bit[i-1][j][k-1]-bit[i-1][j-1][k]
				 +bit[i-1][j-1][k-1];
			}
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d%d%d%d",&x1,&x2,&y1,&y2,&z1,&z2);
		printf("%lld\n",bit[x2][y2][z2]
			-bit[x1-1][y2][z2]-bit[x2][y1-1][z2]-bit[x2][y2][z1-1]
			+bit[x1-1][y1-1][z2]+bit[x1-1][y2][z1-1]+bit[x2][y1-1][z1-1]
			-bit[x1-1][y1-1][z1-1]);
	}
	
	return 0;
}
