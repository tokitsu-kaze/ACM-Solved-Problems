#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<10)+10;
int mp[MAX][MAX];
void dfs(int x,int y,int len)
{
	if(len==1)
	{
		mp[x][y]=1;
		return;
	}
	dfs(x+len/2,y,len/2);
	dfs(x,y+len/2,len/2);
	dfs(x+len/2,y+len/2,len/2);
}
int main()
{
	int n,i,j;
	memset(mp,0,sizeof mp);
	scanf("%d",&n);
	n=(1<<n);
	dfs(0,0,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d%c",mp[i][j]," \n"[j==n-1]);
		}
	}
	return 0;
}
