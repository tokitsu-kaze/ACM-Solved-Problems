#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
ll w[MAX];
int main()
{
	int n,i,ok;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	ok=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]>b[i])
		{
			ok=1;
			w[i]=1e18;
		}
		else w[i]=1;
	}
	if(ok)
	{
		puts("Yes");
		for(i=1;i<=n;i++) printf("%lld%c",w[i]," \n"[i==n]);
	}
	else puts("No");
	return 0;
}
