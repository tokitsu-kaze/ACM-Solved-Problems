#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char mp[1010][1010],tmp[1010][1010];
int res[1010][1010],n,m;
void rotate90()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			tmp[i][j]=mp[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			mp[j][i]=tmp[n-i+1][j];
		}
	}
	swap(n,m);
}
ll work()
{
	int i,j,r;
	ll ans;
	for(j=1;j<=m;j++)
	{
		res[n][j]=1;
		for(i=n-1;i;i--)
		{
			if(mp[i+1][j]==mp[i][j]) res[i][j]=res[i+1][j]+1;
			else res[i][j]=1;
		}
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		r=m;
		for(j=m-1;j;j--)
		{
			if(mp[i][j]!=mp[i][j+1])
			{
				r=j;
				continue;
			}
			r=min(r,j+res[i][j]-1);
			ans+=r-j;
		}
	}
	return ans;
}
int main()
{
	int i,j;
	ll ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	ans=0;
	ans+=work();
	rotate90();
	ans+=work();
	rotate90();
	ans+=work();
	rotate90();
	ans+=work();
	printf("%lld\n",ans);
	return 0;
}
