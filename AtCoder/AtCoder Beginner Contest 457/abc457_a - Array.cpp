#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,a[105],i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&x);
	printf("%d\n",a[x]);
	return 0;
}
