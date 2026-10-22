#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,d,i,a[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&d);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		if(a[1]+a[2]>d && a[n]>d) puts("NO");
		else puts("YES");
	}
	return 0;
}
