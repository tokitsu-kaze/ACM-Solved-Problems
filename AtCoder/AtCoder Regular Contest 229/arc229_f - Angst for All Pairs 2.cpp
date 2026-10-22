#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll c[MAX],sum[MAX];
int main()
{
	int T,n,i;
	ll now,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%lld",&c[i]);
		sort(c+1,c+1+n);
		if(n==2)
		{
			printf("%lld\n",c[1]*2);
			continue;
		}
		if(n==3)
		{
			printf("%lld\n",c[1]*3+c[2]);
			continue;
		}
		n--;
		sum[0]=0;
		for(i=1;i<=n;i++) sum[i]=sum[i-1]+c[i];
		ans=LLINF;
		for(i=1;i<=n/3;i++)
		{
			now=sum[n]-sum[i];
			now+=(sum[i]-c[1])*2;
			now+=c[1]*(n-3*i+2);
			ans=min(ans,now);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
把卡片看作图上连边，发现：
1.最多只有一个孤立点，那肯定是代价最大的。
2.不存在一个连通块只有两个点一条边。
那也就是说，连通块至少要是一个点连两条边。
贪心地肯定是选择代价最小的，连成菊花。
但样例3过不去，发现是可以分成多个连通块，就能少连点边。
又发现最多只有一个连通块是点数大于3的菊花，其他都是等于3的。
因为如果有多个，不如把多的边全接在代价最小的菊花上，答案肯定变小。
考虑枚举几个等于3的菊花，然后算算答案。

样例2：(1,2), (1,3)
样例3：(1,3), (1,5), (4,6), (4,7)
*/
