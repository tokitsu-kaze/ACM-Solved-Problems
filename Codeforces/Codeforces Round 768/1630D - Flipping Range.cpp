#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
vector<int> res[MAX];
int a[MAX];
int main()
{
	int T,n,m,i,b,g,cnt,mn;
	ll ans1,ans2,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		g=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d",&b);
			g=__gcd(g,b);
		}
		for(i=0;i<g;i++) res[i].clear();
		for(i=1;i<=n;i++) res[i%g].push_back(a[i]);
		ans1=ans2=0;
		for(i=0;i<g;i++)
		{
			cnt=0;
			now=0;
			mn=2e9;
			for(auto &it:res[i])
			{
				if(it<0) cnt++;
				mn=min(mn,abs(it));
				now+=abs(it);
			}
			if(cnt&1)
			{
				ans1+=now-2*mn;
				ans2+=now;
			}
			else
			{
				ans1+=now;
				ans2+=now-2*mn;
			}
		}
		printf("%lld\n",max(ans1,ans2));
	}
	return 0;
}
/*
先裴蜀定理，最小能操作的长度是g=gcd{bi}。
按对g取模的结果分类，每一类分开处理。
由于bi<=n/2，所以每个类至少有2个数。
对于每个类，操作可以转化成，相邻两个数取反。
一类中，如果负数个数是偶数，可以把所有数都变成正数；奇数至少会留一个。
然后你会发现对于第一个长度为g的区间先操作一次，会改变每个类中负数个数的奇偶性。
于是两种情况取max。
*/
