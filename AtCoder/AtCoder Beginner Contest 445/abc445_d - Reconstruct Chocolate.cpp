#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
map<int,vector<pair<int,int>>> mpx,mpy;
pair<int,int> ans[MAX];
int vis[MAX];
void dfs(int lx,int rx,int ly,int ry)
{
	if(lx>rx || ly>ry) return;
	int len;
	len=ry-ly+1;
	while(mpy.count(len))
	{
		auto it=mpy[len].back();
		if(vis[it.second]==0) break;
		mpy[len].pop_back();
		if(mpy[len].size()==0) mpy.erase(len);
	}
	if(mpy.count(len))
	{
		
		auto it=mpy[len].back();
		mpy[len].pop_back();
		if(mpy[len].size()==0) mpy.erase(len);
		ans[it.second]={lx,ly};
		vis[it.second]=1;
		dfs(lx+it.first,rx,ly,ry);
		return;
	}
	len=rx-lx+1;
	while(mpx.count(len))
	{
		auto it=mpx[len].back();
		if(vis[it.second]==0) break;
		mpx[len].pop_back();
		if(mpx[len].size()==0) mpx.erase(len);
	}
	if(mpx.count(len))
	{
		auto it=mpx[len].back();
		mpx[len].pop_back();
		if(mpx[len].size()==0) mpx.erase(len);
		ans[it.second]={lx,ly};
		vis[it.second]=1;
		dfs(lx,rx,ly+it.first,ry);
		return;
	}
	assert(0);
}
int main()
{
	int n,i,x,y,h,w;
	scanf("%d%d%d",&h,&w,&n);
	mpx.clear();
	mpy.clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		mpx[x].push_back({y,i});
		mpy[y].push_back({x,i});
		vis[i]=0;
	}
	dfs(1,h,1,w);
	for(i=1;i<=n;i++) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}
