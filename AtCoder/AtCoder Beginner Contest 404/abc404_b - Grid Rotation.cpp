#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
int n,m;
char a[MAX][MAX],tmp[MAX][MAX];
void rotate90()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			tmp[i][j]=a[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			a[j][i]=tmp[n-i+1][j];
		}
	}
	swap(n,m);
}
char mp[105][105];
int cal()
{
	int i,j;
	int res=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			res+=(a[i][j]!=mp[i][j]);
		}
	}
	return res;
}
int main()
{
	int i,j,ans;
	scanf("%d",&n);
	m=n;
	for(i=1;i<=n;i++) scanf("%s",a[i]+1);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	ans=cal();
	rotate90();
	ans=min(ans,cal()+1);
	rotate90();
	ans=min(ans,cal()+2);
	rotate90();
	ans=min(ans,cal()+3);
	printf("%d\n",ans);
	return 0;
}
