#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int n,i,j,a[105],cnt;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=200;~i;i--)
	{
		cnt=0;
		for(j=1;j<=n;j++) cnt+=(a[j]>=i);
		if(cnt>=i)
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
