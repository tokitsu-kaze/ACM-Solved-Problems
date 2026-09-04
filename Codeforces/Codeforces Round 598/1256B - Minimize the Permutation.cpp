#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,x,a[105],vis[105],pos;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(vis,0,sizeof vis);
		for(x=1;x<=n;x++)
		{
			pos=0;
			for(i=1;i<=n;i++)
			{
				if(a[i]==x) pos=i;
			}
			if(!pos) continue;
			for(i=pos-1;i;i--)
			{
				if(vis[i] || a[i]<x) break;
				swap(a[i],a[i+1]);
				vis[i]=1;
			}
		}
		for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}
/*
从小到大枚举x，每次找到x位置，尽量往前换即可。
O(n^2)。
*/
