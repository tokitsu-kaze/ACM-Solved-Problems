#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
vector<int> mp[MAX],bit[MAX];
int n,m;
int ck(int x)
{
	int i,j;
	for(i=0;i<=n;i++) bit[i][0]=0;
	for(i=0;i<=m;i++) bit[0][i]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]>=x) bit[i][j]=0;
			else bit[i][j]=1;
			bit[i][j]+=bit[i-1][j]+bit[i][j-1]-bit[i-1][j-1];
		}
	}
	for(i=x;i<=n;i++)
	{
		for(j=x;j<=m;j++)
		{
			if(bit[i][j]-bit[i-x][j]-bit[i][j-x]+bit[i-x][j-x]==0) return 1;
		}
	}
	return 0;
}
int main()
{
	int T,i,j,l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		bit[0].resize(m+1);
		for(i=1;i<=n;i++)
		{
			mp[i].resize(m+1);
			bit[i].resize(m+1);
			for(j=1;j<=m;j++) scanf("%d",&mp[i][j]);
		}
		l=1;
		r=min(n,m);
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1)) l=mid+1;
			else r=mid;
		}
		printf("%d\n",l);
	}
	return 0;
}
