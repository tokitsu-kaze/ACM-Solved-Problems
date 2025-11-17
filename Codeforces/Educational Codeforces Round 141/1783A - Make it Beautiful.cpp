#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,a[55],sum,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		reverse(a+1,a+1+n);
		for(i=2;i<=n;i++)
		{
			if(a[i]!=a[1])
			{
				swap(a[i],a[2]);
				break;
			}
		}
		sum=0;
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(sum==a[i]) ok=0;
			sum+=a[i];
		}
		if(ok)
		{
			puts("YES");
			for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
		}
		else puts("NO");
	}
	return 0;
}
