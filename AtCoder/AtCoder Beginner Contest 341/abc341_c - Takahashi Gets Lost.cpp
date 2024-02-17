#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int n,m;
char s[505],mp[505][505];
int ck(int x,int y,int k)
{
	int i;
	for(i=1;i<=k;i++)
	{
		if(s[i]=='L') y--;
		else if(s[i]=='R') y++;
		else if(s[i]=='U') x--;
		else x++;
		if(x<1||y<1||x>n||y>m) return 0;
		if(mp[x][y]=='#') return 0;
	}
	return 1;
}
int main()
{
	int k,i,j,ans;
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",s+1);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='#') continue;
			ans+=ck(i,j,k);
		}
	}
	printf("%d\n",ans);
	return 0;
}
