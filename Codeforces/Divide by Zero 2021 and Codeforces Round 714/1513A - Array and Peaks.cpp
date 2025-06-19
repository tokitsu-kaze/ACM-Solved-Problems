#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,i,k,cnt,a[105],now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) a[i]=0;
		now=n;
		for(i=2;i<n;i+=2)
		{
			if(k==0) break;
			a[i]=now;
			now--;
			k--;
		}
		if(k>0)
		{
			puts("-1");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			if(a[i]==0) a[i]=now--;
		}
		for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}
