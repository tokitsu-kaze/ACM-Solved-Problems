#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,a[105],b[105],pos[105],ok;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	for(i=1;i<=n;i++) pos[b[i]]=i;
	ok=1;
	for(i=1;i<=n;i++)
	{
		if(a[i]!=pos[i]) ok=0;
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
