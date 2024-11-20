#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int mg[11][11],hg[11][11],v[11][11],id[11];
int main()
{
	int n,i,j,m,a,b,ans,res;
	scanf("%d",&n);
	scanf("%d",&m);
	memset(mg,0,sizeof mg);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mg[a][b]=mg[b][a]=1;
	}
	memset(hg,0,sizeof hg);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		hg[a][b]=hg[b][a]=1;
	}
	memset(v,0,sizeof v);
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			scanf("%d",&v[i][j]);
			v[j][i]=v[i][j];
		}
	}
	for(i=1;i<=n;i++) id[i]=i;
	ans=INF;
	do
	{
		res=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(mg[i][j]==hg[id[i]][id[j]]) continue;
				res+=v[id[i]][id[j]];
			}
		}
		ans=min(ans,res);
	}while(next_permutation(id+1,id+1+n));
	printf("%d\n",ans);
	return 0;
}

