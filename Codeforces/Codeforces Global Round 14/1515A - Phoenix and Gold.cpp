#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,x,i,a[105],sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sum=0;
		for(i=1;i<=n;i++)
		{
			if(sum+a[i]==x) swap(a[i],a[n]);
			sum+=a[i];
		}
		if(sum==x) puts("NO");
		else
		{
			puts("YES");
			for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
		}
	}
	return 0;
}
