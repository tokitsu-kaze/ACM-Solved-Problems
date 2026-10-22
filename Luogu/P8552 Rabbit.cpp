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
}dsu;
vector<int> mp[MAX];
int main()
{
	int T,n,i,a,b,ans,cnt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			if(a<b) swap(a,b);
			mp[a].push_back(b);
		}
		dsu.init(n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			cnt=0;
			for(auto &to:mp[i])
			{
				cnt+=(dsu.get_size(to)>0);
				dsu.merge(i,to);
			}
			if(cnt>=2)
			{
				ans++;
				dsu.sz[dsu.find(i)]-=3;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
考虑删掉最大值，递归分治下去，但感觉并不是很好写。
考虑倒着做，从最小值开始用并查集合并。
合并时只要看一下能匹配多少对，维护一下能匹配的size。
*/
