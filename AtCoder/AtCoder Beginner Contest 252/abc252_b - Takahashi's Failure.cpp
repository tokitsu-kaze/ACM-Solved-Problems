#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,m,i,j,a[105],b[105],mx,ok;
	scanf("%d%d",&n,&m);
	mx=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
	}
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	ok=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]!=mx) continue;
		for(j=1;j<=m;j++)
		{
			if(b[j]==i) ok=1;
		}
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
