#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int a[MAX],ans[MAX];
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) ans[i]=i;
	for(k=1;k<=100;k++)
	{
		for(j=1;j<=10;j++)
		{
			for(i=1;i<=n;i++) ans[i]=a[ans[i]];
		}
		for(i=1;i<=n;i++) a[i]=ans[i];
	}
	for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}
