#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
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
vector<int> pos[MAX];
int a[MAX],res[MAX];
int main()
{
	int n,i,k,mx,tot,now;
	ll ans;
	scanf("%d",&n);
	mx=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
	}
	for(i=1;i<=mx;i++) pos[i].clear();
	for(i=1;i<=n;i++) pos[a[i]].push_back(i);
	dsu.init(n);
	tot=0;
	now=0;
	for(i=mx;i;i--)
	{
		for(auto &it:pos[i])
		{
			tot++;
			if(it>1 && a[it-1]>=a[it]) now+=dsu.merge(it-1,it);
			if(it<n && a[it+1]>=a[it]) now+=dsu.merge(it+1,it);
		}
		res[i]=tot-now;
	}
	for(k=1;k<=mx;k++)
	{
		ans=0;
		for(i=mx/k*k+1;i>=1;i-=k) ans+=res[i];
		printf("%lld%c",ans," \n"[k==mx]);
	}
	return 0;
}
/*
怪兽死了会分割成若干个连通块。
每次操作完删边。
把值域倒过来遍历，删边变加边。
枚举 k，再枚举每 k 长值域，快速并起来。
而且还需要将每 k 长值域提前并起来。
诶，是不是直接倒着并一遍，记录下结果就行了？
每次贡献就是：当前加入集合的点数-集合数
*/
