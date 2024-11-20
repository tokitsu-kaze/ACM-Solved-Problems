#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e4+10;
struct Node_Biconnected_Component
{
	int low[MAX],dfn[MAX],tot;
	vector<int> *mp,cut_node;
	bool cut_vis[MAX];
	void dfs(int x,int fa)
	{
		int i,cnt;
		low[x]=dfn[x]=++tot;
		cnt=0;
		for(auto &to:mp[x])
		{
			if(!dfn[to])
			{
				cnt++;
				dfs(to,x);
				low[x]=min(low[x],low[to]);
				if(x!=fa && low[to]>=dfn[x]) cut_vis[x]=1;
			}
			else if(to!=fa) low[x]=min(low[x],dfn[to]);
		}
		if(x==fa && cnt>1) cut_vis[x]=1;
		if(cut_vis[x]) cut_node.push_back(x);
	}
	void work(int n,vector<int> *_mp)
	{
		int i;
		mp=_mp;
		cut_node.clear();
		for(i=0;i<=n;i++) low[i]=dfn[i]=cut_vis[i]=0;
		tot=0;
		for(i=1;i<=n;i++)
		{
			if(!dfn[i]) dfs(i,i);
		}
	}
}bcc;
/*
bcc.work(n,mp);
*/
vector<int> mp[MAX];
int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	bcc.work(n,mp);
	printf("%d\n",bcc.cut_node.size());
	sort(bcc.cut_node.begin(),bcc.cut_node.end());
	for(i=0;i<bcc.cut_node.size();i++)
	{
		printf("%d",bcc.cut_node[i]);
		if(i+1==bcc.cut_node.size()) puts("");
		else printf(" ");
	}
	return 0;
}
