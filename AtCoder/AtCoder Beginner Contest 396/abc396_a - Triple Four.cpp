#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
const int mod=998244353;
int main()
{
	int n,i,a[105],ok;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ok=0;
	for(i=2;i<n;i++)
	{
		if(a[i]==a[i-1] && a[i]==a[i+1]) ok=1;
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
