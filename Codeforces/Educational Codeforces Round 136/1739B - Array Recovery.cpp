#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,d[105],a[105],ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&d[i]);
		ok=1;
		a[1]=d[1];
		for(i=2;i<=n;i++)
		{
			a[i]=a[i-1]+d[i];
			if(d[i]!=0 && d[i]<=a[i-1]) ok=0;
		}
		if(ok)
		{
			for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
		}
		else puts("-1");
	}
	return 0;
}
