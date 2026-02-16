#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int mp[105][105];
int main()
{
	int n,m,k,i,j,x,y;
	scanf("%d%d%d",&n,&m,&k);
	if(k&1)
	{
		puts("2");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++) mp[i][j]=((i+j)&1);
		}
	}
	else
	{
		puts("4");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				x=i+j;
				y=i-j+m;
				mp[i][j]=x/k%2*2+y/k%2;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++) printf("%d%c",mp[i][j]," \n"[j==m]);
	}
	return 0;
}
