#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll a[MAX],p[MAX],q[MAX];
int main()
{
	int n,i,j,ok;
	ll l,r;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	l=-LLINF;
	r=LLINF;
	ok=1;
	for(i=n;i;i--)
	{
		p[i]=1;
		q[i]=a[i];
		for(j=i+i;j<=n;j+=i)
		{
			p[i]-=p[j];
			q[i]-=q[j];
		}
		if(p[i]>0) l=max(l,(q[i]+p[i]-1)/p[i]);
		else if(p[i]<0) r=min(r,q[i]/p[i]);
		else
		{
			if(q[i]>0) ok=0;
		}
	}
	if(l>r) ok=0;
	if(ok) printf("%lld\n",l-a[1]);
	else puts("-1");
	return 0;
}
/*
还以为是最终变成最大值，然后倒着模拟。
wa了之后发现倒着模拟不可能错，那肯定是最大值这个结论不对。

正解：
设最终要使得所有数均为 k，第 i 个数需要增加 xi 次，列式子：
xn=k-an；
xi=k-ai-sum{xj}, 满足 j 是 i 的倍数。
发现每次减的都是一次函数，最终结果也是一次函数。所以设 xi=pi*k-qi。
倒着做，每一项 pi qi 都能求出来。
然后要满足 xi>=0，于是求出 k>=qi/pi。除过去的时候要根据 pi 做一些判断。
比如 pi 是负的，除过去后会变成<=；pi=0 需要判断是否有解。
*/
