#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
int a[305],vis[MAX];
int main()
{
	int n,i,j,k,w,ans;
	scanf("%d%d",&n,&w);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=0;i<=w;i++) vis[i]=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]<=w) vis[a[i]]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(a[i]+a[j]<=w) vis[a[i]+a[j]]=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			for(k=j+1;k<=n;k++)
			{
				if(a[i]+a[j]+a[k]<=w) vis[a[i]+a[j]+a[k]]=1;
			}
		}
	}
	ans=0;
	for(i=1;i<=w;i++) ans+=vis[i];
	printf("%d\n",ans);
	return 0;
}
