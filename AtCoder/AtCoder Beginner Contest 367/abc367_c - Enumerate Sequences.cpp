#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int r[11],n,k,a[11];
void dfs(int x,int sum)
{
	int i;
	if(x==n+1)
	{
		if(sum%k) return;
		for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
		return;
	}
	for(i=1;i<=r[x];i++)
	{
		a[x]=i;
		dfs(x+1,sum+i);
	}
}
int main()
{
	int i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&r[i]);
	dfs(1,0);
	return 0;
}
