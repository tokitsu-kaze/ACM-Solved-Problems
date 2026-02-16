#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
vector<pair<int,int>> mp[MAX];
vector<int> res,pos[MAX];
int belong[MAX];
void dfs(int x)
{
	sort(mp[x].begin(),mp[x].end());
	vector<int> tmp;
	int pre=-1;
	for(auto &it:mp[x])
	{
		if(it.first!=pre)
		{
			for(auto &to:tmp) dfs(to);
			tmp.clear();
		}
		tmp.push_back(it.second);
		for(auto &it2:pos[it.second]) res.push_back(it2);
		pre=it.first;
	}
	for(auto &to:tmp) dfs(to);
}
int main()
{
	int n,i,a,b,tot;
	scanf("%d",&n);
	for(i=0;i<=n+1;i++)
	{
		mp[i].clear();
		pos[i].clear();
	}
	tot=0;
	belong[0]=++tot;
	map<pair<int,int>,int> vis;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		if(vis.count({belong[a],b})) belong[i]=vis[{belong[a],b}];
		else
		{
			belong[i]=++tot;
			vis[{belong[a],b}]=belong[i];
			mp[belong[a]].push_back({b,belong[i]});
		}
		pos[belong[i]].push_back(i);
//		cout<<belong[a]<<" "<<belong[i]<<endl;
	}
	res.clear();
	dfs(belong[0]);
	for(i=0;i<n;i++) printf("%d%c",res[i]," \n"[i+1==n]);
	return 0;
}
/*
5
0 1
0 1
1 2
3 5
2 2
*/
