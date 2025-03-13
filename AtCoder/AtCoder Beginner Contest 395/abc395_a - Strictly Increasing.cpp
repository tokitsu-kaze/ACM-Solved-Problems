#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=998244353;
const int MAX=2e5+10;
int main()
{
	int n,i,a[105],ok;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ok=1;
	for(i=2;i<=n;i++)
	{
		if(a[i-1]>=a[i]) ok=0;
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
