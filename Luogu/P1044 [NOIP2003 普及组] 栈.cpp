#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C[42][42];
void init(int n)
{
	int i,j;
	C[0][0]=1;
	for(i=1;i<=n;i++)
	{
		C[i][0]=1;
		for(j=1;j<=n;j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1]);
		}
	} 
}
int main()
{
	init(36);
	int n;
	scanf("%d",&n);
	printf("%lld\n",C[2*n][n]-C[2*n][n+1]);
	return 0;
}
