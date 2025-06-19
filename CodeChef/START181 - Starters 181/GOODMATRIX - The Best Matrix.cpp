#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
int n,m,a[MAX][MAX],tmp[MAX][MAX];
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
int main()
{
	int T,i,j,k,ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++) scanf("%d",&a[i][j]);
		}
		ans=0;
		for(k=0;k<4;k++)
		{
			map<int,int> mp;
			for(i=1;i<=n;i++)
			{
				now=i;
				for(j=1;j<=m;j++)
				{
					mp[a[i][j]-now]++;
					now++;
				}
			}
			for(auto &it:mp) ans=max(ans,it.second);
			rotate90();
		}
		printf("%d\n",n*m-ans);
	}
	return 0;
}
/*
1 2 3
2 3 4
3 4 5
*/
