#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
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
	int get_size(int x){return sz[find(x)];}
}dsu[2];
int main()
{
	int n,i,a,b,c;
	ll ans;
	scanf("%d",&n);
	dsu[0].init(n);
	dsu[1].init(n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		dsu[c].merge(a,b);
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		ans+=1LL*dsu[0].get_size(i)*dsu[1].get_size(i)-1;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
两个并查集维护一下 0 和 1 的连通块。
枚举经过哪个点，然后乘一乘就行了。
*/
