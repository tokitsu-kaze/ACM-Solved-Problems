#include <bits/stdc++.h>
using namespace std;
vector<int> topsort(vector<int> &node,vector<int> mp[],int *in)
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
	return toplist;
}
vector<int> mp[105];
int in[105];
int main()
{
	int n,i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		in[i]=0;
		while(~scanf("%d",&x)&&x)
		{
			mp[i].push_back(x);
			in[x]++;
		}
	}
	vector<int> node,res;
	for(i=1;i<=n;i++) node.push_back(i);
	res=topsort(node,mp,in);
	for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
	return 0;
}
