#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,a[55];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n==1)
		{
			puts("-1");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			if(i&1) a[i]=1;
			else a[i]=-1;
		}
		if(n&1)
		{
			a[n-1]=2;
			a[n]=-3;
		}
		for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}
