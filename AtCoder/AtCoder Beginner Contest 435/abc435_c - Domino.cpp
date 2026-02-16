#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int a[MAX];
int main()
{
	int n,i,ans,mx;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=1;
	mx=1+a[1]-1;
	for(i=2;i<=n;i++)
	{
		if(i<=mx) ans++;
		else break;
		mx=max(mx,i+a[i]-1);
	}
	printf("%d\n",ans);
	return 0;
}
