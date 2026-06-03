#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
int main()
{
	int n,m,i,j,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	reverse(a+1,a+1+n);
	reverse(b+1,b+1+m);
	ans=0;
	for(i=1,j=1;i<=n;i++)
	{
		while(j<=m && b[j]>2*a[i]) j++;
		if(j<=m)
		{
			ans++;
			j++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
