#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e4+10;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX];
	ll cnt[MAX];
	void init(int n)
	{
		int i;
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
		cnt[y]+=cnt[x];
		return 1;
	}
}dsu;
struct node{int l,r,b,t;};
int ck(node a,node b)
{
	if(a.r==b.l-1 || b.r==a.l-1) return min(a.t,b.t)>=max(a.b,b.b);
	if(a.t==b.b-1 || b.t==a.b-1) return min(a.r,b.r)>=max(a.l,b.l);
	return 0; 
}
int main()
{
	int n,x,y,a,b,i,j;
	char ch[2];
	scanf("%d%d%d",&n,&x,&y);
	vector<node> res;
	res.push_back({0,x-1,0,y-1});
	while(n--)
	{
		scanf("%s%d%d",ch,&a,&b);
		vector<node> tmp;
		for(auto &it:res)
		{
			if(ch[0]=='X')
			{
				if(it.r<a) tmp.push_back({it.l,it.r,it.b-b,it.t-b});
				else if(it.l>=a) tmp.push_back({it.l,it.r,it.b+b,it.t+b});
				else
				{
					tmp.push_back({it.l,a-1,it.b-b,it.t-b});
					tmp.push_back({a,it.r,it.b+b,it.t+b});
				}
			}
			else
			{
				if(it.t<a) tmp.push_back({it.l-b,it.r-b,it.b,it.t});
				else if(it.b>=a) tmp.push_back({it.l+b,it.r+b,it.b,it.t});
				else
				{
					tmp.push_back({it.l-b,it.r-b,it.b,a-1});
					tmp.push_back({it.l+b,it.r+b,a,it.t});
				}
			}
		}
		swap(res,tmp);
	}
	n=res.size();
	dsu.init(n);
	for(i=1;i<=res.size();i++)
	{
		dsu.cnt[i]=1LL*(res[i-1].r-res[i-1].l+1)*(res[i-1].t-res[i-1].b+1);
	}
	for(i=1;i<=res.size();i++)
	{
		for(j=i+1;j<=res.size();j++)
		{
			if(ck(res[i-1],res[j-1])) dsu.merge(i,j);
		}
	}
	vector<ll> ans;
	for(i=1;i<=res.size();i++)
	{
		if(dsu.find(i)==i) ans.push_back(dsu.cnt[i]);
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",(int)ans.size());
	for(i=0;i<ans.size();i++) printf("%lld%c",ans[i]," \n"[i+1==ans.size()]);
	return 0;
}
