#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
const int mod=998244353;
int p[MAX];
int main()
{
	int n,k,i,j,cnt;
	ll ans;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	ans=1;
	for(i=1;i<=n;i++)
	{
		cnt=0;
		for(j=1;j<i;j++) cnt+=(p[j]>p[i]);
		if(cnt==k) ans=ans*(n-i+1)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
题目要求包含每个数的逆序对都要不超过 k。
相邻交换，最少次数。那么说明每次交换逆序对数都要+1。
考虑如果当前逆序对个数<k，说明在原排列中是不会改变的，不用管；
如果=k，说明原排列中是>=k，那么逆序对>=k的方案数是(n-i+1)。
每次操作只会使一个数的逆序对+-1，每个数互不影响，乘起来就行。

为什么方案数是 (n-i+1)，因为，在 i 右边，一定都是比 ai 大的，
所以右边的任意位置都可以是 ai 最初位置。
反证：如果 i 右边存在比 ai 小的 aj，那 ai 左边已经有 k 个比 ai 大的，
ai > aj，那么 aj 左边就有 k+1 个比 aj 大的，这显然不符合题目条件。
*/
