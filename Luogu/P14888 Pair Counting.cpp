#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int d[MAX],cnt[MAX],a[MAX],b[MAX],to[MAX];
int main()
{
	int T,n,i;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) cnt[i]=d[i]=0;
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			d[a[i]]++;
			d[b[i]]++;
			to[a[i]]=b[i];
			to[b[i]]=a[i];
		}
		for(i=1;i<=n;i++)
		{
			if(d[i]==1) cnt[to[i]]++;
		}
		ans=1LL*n*(n-1)/2-(n-1);
		for(i=1;i<n;i++) ans-=1LL*cnt[a[i]]*cnt[b[i]];
		printf("%lld\n",ans);
	}
	return 0;
}
/*
首先发现距离为偶数一定可行，自然考虑奇数部分。
手玩发现距离>=5奇数一定可行，再考虑=3的情况。
发现=3的情况，如果x,y的度都为1，那么(x,y)不可行。
所以总共有2种情况不可行：
1.距离=1； 
2.距离=3且x,y的度都为1；
实现时可以枚举fa[x]-fa[y]这条边，计算有几对(x,y)。 
*/

