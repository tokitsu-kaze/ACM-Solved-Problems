#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int n,i,ok;
	ll a[111];
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n==2)
	{
		puts("Yes");
		return 0;
	}
	ok=1;
	for(i=2;i<n;i++)
	{
		if(a[i-1]*a[i+1]!=a[i]*a[i]) ok=0;
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
