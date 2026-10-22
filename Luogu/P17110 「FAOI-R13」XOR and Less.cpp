#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
const int mod=998244353;
int a[MAX],nex[MAX],mn[MAX];
int main()
{
	int n,i,s,p1,p2;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(mn,0x3f,sizeof mn);
	nex[n+1]=n+1;
	nex[n+2]=n+2;
	ans=0;
	for(s=30;~s;s--)
	{
		for(i=n;i;i--)
		{
			if((a[i]>>s)&1) nex[i]=i;
			else nex[i]=nex[i+1];
			p1=nex[i];
			p2=nex[p1+1];
			ans=(ans+1LL*(n-min(p1,mn[i])+1)*(1<<s))%mod;
			mn[i]=min(mn[i],p2);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
由于可以取到 0，所以可以忽略其他数的影响。
看最高位 x，如果区间中存在1个数最高位为 x，对答案贡献 1<<x；
如果存在2个数为 x，对答案贡献 (1<<(x+1))-1。
拆位，从高到低，然后枚举左端点，计算当前这一位的贡献。
存在2个数最高位为 x 时，往右的低位全部能标成 1，并且这个标记是单调往左的。
所以我们维护 mn[i] 表示：左端点为 i 时，右端点在区间 [mn[i],n] 中当前位的贡献都为 1。
*/
