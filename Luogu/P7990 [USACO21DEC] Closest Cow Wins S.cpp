#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int p,v;}a[MAX];
int p[MAX];
int main()
{
	int k,m,n,i,j,len,nex,l,r;
	ll ans,sum,now,mx;
	scanf("%d%d%d",&k,&m,&n);
	for(i=1;i<=k;i++) scanf("%d%d",&a[i].p,&a[i].v);
	for(i=1;i<=m;i++) scanf("%d",&p[i]);
	p[++m]=INT_MIN;
	p[++m]=INT_MAX;
	sort(a+1,a+k+1,[](node a,node b){
		return a.p<b.p;
	});
	sort(p+1,p+1+m);
	vector<ll> res;
	for(i=1,j=2;j<=m;j++)
	{
		if(p[j]<a[i].p) continue;
		sum=0;
		nex=i;
		while(nex<=k && a[nex].p<p[j]) sum+=a[nex++].v;
		len=(p[j]-p[j-1]-1)/2;
		now=mx=0;
		for(l=i,r=i;l<nex;l++)
		{
			while(r<nex && a[r].p-a[l].p<len) now+=a[r++].v;
			mx=max(mx,now);
			now-=a[l].v;
		}
		res.push_back(mx);
		res.push_back(sum-mx);
		i=nex;
	}
	sort(res.begin(),res.end());
	reverse(res.begin(),res.end());
	ans=0;
	for(i=0;i<min((int)res.size(),n);i++) ans+=res[i];
	printf("%lld\n",ans);
	return 0;
}
/*
对方m只牛分割成m+1个区间，每个区间最多2只我方牛就能全部覆盖。
考虑放1只牛的最大贡献，放2只牛就拆一下贡献，总的减1只牛的。
然后取完1只牛的贡献后把第2只牛的贡献加入，用堆维护。
但这么做的话，放第2只牛的贡献如果大于放第1只牛的贡献，这个贪心可能会有问题。
因为你先根据第1只牛的贡献比较，可能会出现a1超小a2超大的情况，这样就假了。
但列一下式子可以证明放第1只牛的贡献>=放第2只牛的贡献。
这样的话其实也不需要堆维护，直接排序肯定是对的。
现在考虑最大贡献怎么算。枚举区间中牛的位置，可以生成范围，然后取max即可。
牛的位置可以根据最左边草的位置决定。
发现这个范围固定是区间长度一半，那就好写很多了。
*/
