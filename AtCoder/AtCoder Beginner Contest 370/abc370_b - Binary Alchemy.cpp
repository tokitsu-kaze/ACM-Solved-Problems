#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[105][105];
int main()
{
	int n,i,j,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++) scanf("%d",&a[i][j]);
	}
	x=1;
	for(i=1;i<=n;i++)
	{
		if(x>=i) x=a[x][i];
		else x=a[i][x];
	}
	printf("%d\n",x);
	return 0;
}
