#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,a[12],h,ans;
	n=10;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&h);
	h+=30;
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]<=h) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
