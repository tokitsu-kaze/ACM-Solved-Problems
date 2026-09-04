#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX],b[MAX];
int main()
{
	int T,n,i,ok,col,cnt,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ok=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]!=a[1]) ok=1;
		}
		if(!ok)
		{
			puts("-1");
			continue;
		}
		for(i=1;i<=n;i++) b[i]=a[i];
		for(i=2;i<n;i++)
		{
			if(b[i-1]==b[i+1]) b[i]=b[i-1];
		}
		col=b[1];
		for(i=2;i<=n;i++)
		{
			if(b[i]!=col)
			{
				col=-1;
				break;
			}
		}
		if(col==-1)
		{
			puts("0");
			continue;
		}
		ans=INF;
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]==col) cnt++;
			else
			{
				ans=min(ans,cnt);
				cnt=0;
			}
		}
		ans=min(ans,cnt);
		printf("%d\n",ans);
	}
	return 0;
}
/*
最终只能变成一种颜色。
先模拟一下变成哪个。
然后尝试删掉每个连续段。
*/
