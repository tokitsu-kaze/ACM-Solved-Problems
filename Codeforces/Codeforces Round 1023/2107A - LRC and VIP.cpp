#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,a[105],mx,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		mx=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
		}
		ok=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]!=mx) ok=1;
		}
		if(!ok)
		{
			puts("No");
			continue;
		}
		puts("Yes");
		for(i=1;i<=n;i++)
		{
			if(a[i]==mx) printf("1");
			else printf("2");
			if(i==n) puts("");
			else printf(" ");
		}
	}
	return 0;
}
