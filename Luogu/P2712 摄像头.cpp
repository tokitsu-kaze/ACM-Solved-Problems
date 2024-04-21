#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int topsort(vector<int> &node,vector<int> mp[],int *in)
{
	queue<int> q;
	for(auto &it:node)
	{
		if(!in[it]) q.push(it);
	}
	vector<int> toplist;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		toplist.push_back(x);
		for(auto &to:mp[x])
		{
			in[to]--;
			if(!in[to]) q.push(to);
		}
	}
	return toplist.size();
}
vector<int> mp[MAX],tmp[MAX],res;
int in[MAX],vis[MAX],a[MAX];
int main()
{
	int n,m,i,b,ans;
	scanf("%d",&n);
	for(i=1;i<=500;i++)
	{
		in[i]=vis[i]=0;
		mp[i].clear();
		tmp[i].clear();
	}
	res.clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&m);
		vis[a[i]]=1;
		while(m--)
		{
			scanf("%d",&b);
			tmp[a[i]].push_back(b);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(auto &to:tmp[a[i]])
		{
			if(!vis[to]) continue;
			in[to]++;
			mp[a[i]].push_back(to);
		}
	}
	res.clear();
	for(i=1;i<=500;i++)
	{
		if(vis[i]) res.push_back(i);
	}
	ans=topsort(res,mp,in);
	if(ans==n) puts("YES");
	else printf("%d\n",n-ans);
	return 0;
}
