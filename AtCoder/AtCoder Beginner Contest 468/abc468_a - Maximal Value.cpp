#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,a[105],ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=0;
	for(i=2;i<=n-1;i++)
	{
		if(a[i-1]<a[i] && a[i]>a[i+1]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
