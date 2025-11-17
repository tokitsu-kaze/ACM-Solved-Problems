#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int mp[505][505],cnt,n,col;
void dfs(int x,int y)
{
	if(cnt==0) return;
	if(x<1||y<1||x>n||y>x) return;
	if(mp[x][y]) return;
	mp[x][y]=col;
	cnt--;
	dfs(x-1,y);
	dfs(x,y-1);
	dfs(x+1,y);
}
int main()
{
	int i,j,ok,x;
	memset(mp,0,sizeof mp);
	scanf("%d",&n);
	ok=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		col=cnt=x;
		dfs(i,i);
		if(cnt>0) ok=0;
	}
	assert(ok);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d%c",mp[i][j]," \n"[j==i]);
		}
	}
	return 0;
}
