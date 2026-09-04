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
}dsupre,dsunow;
int a[MAX];
int main()
{
	int T,n,i,s,x,cnt,now,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		dsunow.init(n);
		now=n;
		ans=0;
		for(s=29;~s;s--)
		{
			dsupre=dsunow;
			x=-1;
			cnt=0;
			for(i=1;i<=n;i++)
			{
				if(!((a[i]>>s)&1)) continue;
				if(x==-1) x=i;
				else cnt+=dsunow.merge(x,i);
			}
			if(x!=-1 && now-cnt>1)
			{
				now-=cnt;
				ans|=(1<<s);
			}
			else dsunow=dsupre;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
从高位到低位贪心。
当前位是1必须分在同一个集合，是0可以不管他。
模拟这个过程，用并查集合并，然后看是否至少有2个集合。
处理下一个位的时候，继承上一次并查集的结果。
*/
