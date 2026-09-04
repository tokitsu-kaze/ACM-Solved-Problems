#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int f[MAX],vis[MAX],tmp[MAX];
int main()
{
	int n,i,j,tot;
	scanf("%d",&n);
	memset(vis,0,sizeof vis);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		vis[f[i]]=f[i];
	}
	tot=0;
	for(i=1;i<=n;i++)
	{
		if(!vis[i]) tmp[++tot]=i;
	}
	for(i=1,j=1;i<=n;i++)
	{
		if(f[i]!=0) continue;
		if(tmp[j]==i)
		{
			if(j<tot) swap(tmp[j],tmp[j+1]);
			else swap(tmp[j],tmp[1]);
		}
		j++;
	}
	for(i=1,j=1;i<=n;i++)
	{
		if(f[i]==0) f[i]=tmp[j++];
	}
	for(i=1;i<=n;i++) printf("%d%c",f[i]," \n"[i==n]);
	return 0;
}
