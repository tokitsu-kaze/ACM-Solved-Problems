#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
vector<int> mp[MAX];
int vl[MAX],vr[MAX],mxl[MAX],mnr[MAX],nowl[MAX],nowr[MAX],k,ok;
void dfs(int x)
{
	int l,r;
	l=vl[x];
	r=vr[x];
	mxl[x]=-2e9;
	mnr[x]=2e9;
	for(auto &to:mp[x])
	{
		dfs(to);
		l=max(l,mxl[to]-k);
		r=min(r,mnr[to]+k);
		mxl[x]=max(mxl[x],mxl[to]);
		mnr[x]=min(mnr[x],mnr[to]);
	}
	if(l>r) ok=0;
	mxl[x]=max(mxl[x],l);
	mnr[x]=min(mnr[x],r);
	nowl[x]=l;
	nowr[x]=r;
}
int ck(int x)
{
	k=x;
	ok=1;
	dfs(1);
	return ok;
}
int ans[MAX];
void dfs1(int x,int l)
{
	ans[x]=max(nowl[x],l-k);
	l=max(l,ans[x]);
	for(auto &to:mp[x]) dfs1(to,l);
}
int main()
{
	int T,B,n,i,fa,l,r,mid;
	scanf("%d%d",&T,&B);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=2;i<=n;i++)
		{
			scanf("%d",&fa);
			mp[fa].push_back(i);
		}
		for(i=1;i<=n;i++) scanf("%d%d",&vl[i],&vr[i]);
		l=0;
		r=1e9;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
		if(!B) continue;
		ck(l);
		dfs1(1,0);
		for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	}
	return 0;
}
/*
显然二分答案。
考虑从下往上区间求交，需要维护一下子树中的最值 mxl 和 mnr。
构造的时候，先ck一遍算出每个点的限制 nowl nowr，
再根据限制从上往下搞一下。
*/
