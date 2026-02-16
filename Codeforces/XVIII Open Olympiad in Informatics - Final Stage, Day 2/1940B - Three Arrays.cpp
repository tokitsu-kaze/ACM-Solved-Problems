#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int d[MAX];
ll sufd[MAX],l[MAX],r[MAX];
int main()
{
	int n,i;
	ll ans,a0,b0,an,bn;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&d[i]);
	for(i=1;i<=n;i++) scanf("%lld",&l[i]);
	for(i=1;i<=n;i++) scanf("%lld",&r[i]);
	scanf("%lld%lld",&a0,&b0);
	sufd[n+1]=0;
	for(i=n;i;i--) sufd[i]=sufd[i+1]+d[i];
	vector<pair<ll,ll>> res;
	for(i=1;i<=n;i++)
	{
		l[i]+=sufd[i+1];
		r[i]+=sufd[i+1];
		res.push_back({l[i],r[i]});
	}
	a0+=sufd[1];
	b0+=sufd[1];
	res.push_back({a0,b0});
	sort(res.begin(),res.end());
	ans=0;
	i=0;
	bn=b0;
	while(i<res.size())
	{
		an=res[i].first;
		if(an>a0) break;
		ans=max(ans,an+bn);
		while(i<res.size() && res[i].first==an)
		{
			bn=min(bn,res[i].second);
			i++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
考虑di=0的做法：
枚举an，大于等于an的直接选，小于an的都不能选
现在bn有一个必选集合，答案是集合中的min。

考虑怎么实现：
把<=a0的li存下来，加上a0，从小到大枚举an。
最初全选a，bn=b0，枚举的时候维护一下bn min。

考虑di!=0的做法：
an=li+sum{di+1..dn}
bn=ri+sum{di+1..dn}
转化成di=0的做法
*/
