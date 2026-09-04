#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=50+10;
char mp[55][55];
int main()
{
	int n,m,i,j,x1,y1,x2,y2;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	x1=y1=INF;
	x2=y2=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='.') continue;
			x1=min(x1,i);
			y1=min(y1,j);
			x2=max(x2,i);
			y2=max(y2,j);
		}
	}
	for(i=x1;i<=x2;i++)
	{
		for(j=y1;j<=y2;j++)
		{
			printf("%c",mp[i][j]);
		}
		puts("");
	}
	return 0;
}
