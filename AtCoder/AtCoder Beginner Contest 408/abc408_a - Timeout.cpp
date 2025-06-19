#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,s,i,a[105],ok;
	scanf("%d%d",&n,&s);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=0;
	ok=1;
	for(i=1;i<=n;i++)
	{
		if(a[i]-a[i-1]>s) ok=0;
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
