#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int n,m;
char mp[12][12];
int cnt[12][12];
void gao(int x,int y,int a,int b)
{
	int i,j,ok;
	ok=1;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[x+i-1][y+j-1]!=mp[a+i-1][b+j-1]) ok=0;
		}
	}
	if(ok) cnt[a][b]=0;
}
void ck(int x,int y)
{
	int i,j;
	for(i=1;i+m-1<=n;i++)
	{
		for(j=1;j+m-1<=n;j++)
		{
			if(x==i && y==j) continue;
			gao(x,y,i,j);
		}
	}
}
int main()
{
	int i,j,k,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	for(i=1;i+m-1<=n;i++)
	{
		for(j=1;j+m-1<=n;j++)
		{
			ck(i,j);
			cnt[i][j]=1;
		}
	}
	ans=0;
	for(i=1;i+m-1<=n;i++)
	{
		for(j=1;j+m-1<=n;j++)
		{
			ans+=cnt[i][j];
		}
	}
	printf("%d\n",ans);
	return 0;
}
