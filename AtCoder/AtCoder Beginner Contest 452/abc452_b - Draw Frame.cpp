#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
char mp[12][12];
int main()
{
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++) mp[i][j]='.';
	}
	for(i=1;i<=n;i++) mp[i][1]=mp[i][m]='#';
	for(j=1;j<=m;j++) mp[1][j]=mp[n][j]='#';
	for(i=1;i<=n;i++)
	{
		mp[i][m+1]='\0';
		puts(mp[i]+1);
	}
	return 0;
}
