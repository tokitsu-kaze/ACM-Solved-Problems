#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+30;
int a[MAX],lst[MAX];
int main()
{
	int n,i,mx,now,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		lst[a[i]]=i;
	}
	ans=mx=now=0;
	for(i=1;i<=n;i++)
	{
		mx=max(mx,lst[a[i]]);
		if(i<now) ans++;
		else now=mx;
	}
	printf("%d\n",ans);
	return 0;
}
