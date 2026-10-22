#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int d[MAX][MAX],r[MAX][MAX];
char s[MAX][MAX];
int main()
{
	int n,m,i,j,k,mn,len,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(i=n;i;i--)
	{
		for(j=m;j;j--)
		{
			d[i][j]=r[i][j]=1;
			if(i<n && s[i][j]==s[i+1][j]) d[i][j]+=d[i+1][j];
			if(j<m && s[i][j]==s[i][j+1]) r[i][j]+=r[i][j+1];
		}
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			len=d[i][j];
			if(!(i+len<=n && d[i+len][j]==len)) continue;
			if(!(i+2*len<=n && d[i+2*len][j]>=len)) continue;
			mn=r[i][j];
			for(k=i;k<=i+3*len-1;k++) mn=min(mn,r[k][j]);
			ans+=mn;
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
维护每个点往下和往右相同颜色的最长长度 d[i][j] 和 r[i][j]。
枚举左上角 (i,j)，去确认 d[i+d[i][j]] 和 d[i+2*d[i][j]]。
如果可行就暴力求 min{r[i..i+3*d[i][j]][j]}。
发现一旦 (i,j) 可行，(i+1..i+d[i][j], j) 都不可行，可以直接跳过。
这么做，同一个颜色段中的每个格子，只会分别作为上中下的时候各遍历一遍。
所以复杂度是 3nm。
*/
