#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX];
int main()
{
	int n,i,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=a[n+1]=0;
	ans=0;
	for(i=1;i<=n+1;i++) ans+=abs(a[i]-a[i-1]);
	printf("%d\n",ans/2);
	return 0;
}
