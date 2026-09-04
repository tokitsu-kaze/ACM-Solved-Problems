#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
struct Disjoint_Set_Union
{
	vector<int> pre,sz;
	void init(int n)
	{
		int i;
		pre.resize(n+2);
		sz.resize(n+2);
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(!dir && sz[x]>sz[y]) swap(x,y);
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		return 1;
	}
}dsu;
struct node{int a,b;}a[MAX];
int main()
{
	int n,i,pos;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i].a,&a[i].b);
	sort(a+1,a+1+n,[](node x,node y){
		return x.b>y.b;
	});
	dsu.init(n+1);
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(a[i].a==0) continue;
		pos=dsu.find(a[i].a+1);
		if(pos==n+1) ans+=a[i].b;
		else dsu.merge(pos,pos+1,true);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
有一种按价格考虑的做法。
显然尽可能让b更大的免费。
考虑维护每个人交朋友的顺序，然后b从大到小考虑。
如果当前bi要免费，那应该放在第ai位置后面。
所以后面找个空位放，找不到空位就只能付费。
然后用并查集维护一下下一个空位的位置即可。
*/
