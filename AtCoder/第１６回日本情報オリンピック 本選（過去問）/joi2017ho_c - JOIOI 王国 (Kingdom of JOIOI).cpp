#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e3+10;
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
int mx,mn;
int ck(int x)
{
	int i,j,r;
	r=m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=r;j++)
		{
			if(a[i][j]+x<mx)
			{
				r=j-1;
				break;
			}
		}
		for(j=r+1;j<=m;j++)
		{
			if(a[i][j]-x>mn) return 0;
		}
	}
	return 1;
}
int work()
{
	int l,r,mid;
	l=0;
	r=mx-mn;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid)) r=mid;
		else l=mid+1;
	}
	return l;
}
int main()
{
	int i,j,ans;
	scanf("%d%d",&n,&m);
	mx=0;
	mn=INF;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			mx=max(mx,a[i][j]);
			mn=min(mn,a[i][j]);
		}
	}
	ans=mx-mn;
	for(i=0;i<4;i++)
	{
		ans=min(ans,work());
		rotate90();
	}
	printf("%d\n",ans);
	return 0;
}
