#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e4+10;
int main()
{
	int n,i,x,a[105],ok;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&x);
	ok=0;
	for(i=1;i<=n;i++)
	{
		if(x==a[i]) ok=1;
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
