#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+11;
int main()
{
	int n,m,i,sum,a[105],ok;
	scanf("%d%d",&n,&m);
	sum=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	ok=0;
	for(i=1;i<=n;i++)
	{
		if(sum-a[i]==m) ok=1;
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
