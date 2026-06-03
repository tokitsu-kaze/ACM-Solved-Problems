#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Tree_Diameter
{
	vector<int> nex[MAX];
	int vis[MAX],rt,mx,f,fa;
	void dfs(int x,int pre,int h,vector<int> *mp)
	{
		vis[x]=1;
		for(auto &to:mp[x])
		{
			if(to==pre) continue;
			dfs(to,x,h+1,mp);
		}
		if(h>mx)
		{
			mx=h;
			rt=x;
			fa=f=0;
		}
		if(nex[x].size()>=2 || (nex[x].size()==1 && nex[x][0]!=pre))
		{
			h++;
			if(h>mx)
			{
				mx=h;
				rt=x;
				f=1;
				if(nex[x][0]==pre) fa=nex[x][1];
				else fa=nex[x][0];
			}
		}
	}
	int get_tree_diameter(vector<int> *mp,int _rt)
	{
		rt=_rt;
		mx=f=fa=0;
		dfs(rt,0,0,mp);
		mx=f;
		dfs(rt,fa,f,mp);
		return mx;
	}
}td;
vector<int> mp[MAX];
int a[MAX],b[MAX],cnt[MAX];
int main()
{
	int T,n,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			td.vis[i]=cnt[i]=0;
			mp[i].clear();
			td.nex[i].clear();
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			cnt[a[i]]++;
			cnt[b[i]]++;
		}
		ans=0;
		for(i=1;i<n;i++)
		{
			if(cnt[a[i]]>=4 && cnt[b[i]]>=4)
			{
				mp[a[i]].push_back(b[i]);
				mp[b[i]].push_back(a[i]);
			}
			else if(cnt[a[i]]==3 && cnt[b[i]]>=4) td.nex[b[i]].push_back(a[i]);
			else if(cnt[a[i]]>=4 && cnt[b[i]]==3) td.nex[a[i]].push_back(b[i]);
			else if(cnt[a[i]]==3 && cnt[b[i]]==3) ans=max(ans,2);
		}
		for(i=1;i<=n;i++)
		{
			if(cnt[i]>=2) ans=max(ans,1);
			if(td.vis[i]) continue;
			if(cnt[i]>=4) ans=max(ans,td.get_tree_diameter(mp,i)+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
5
6
1 2
1 3
1 4
2 5
2 6
9
1 2
1 3
1 4
1 5
2 6
2 7
3 8
3 9
8
1 2
1 3
1 4
2 5
2 6
3 7
3 8
3
1 2
2 3
4
1 2
1 3
1 4
*/
