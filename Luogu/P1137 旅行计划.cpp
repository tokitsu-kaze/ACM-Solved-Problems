#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int dp[MAX];
vector<int> topsort(int n,vector<int> mp[],int *in)
{
	queue<int> q;
	for(int it=1;it<=n;it++)
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
			dp[to]=max(dp[to],dp[x]+1);
			if(!in[to]) q.push(to);
		}
	}
	return toplist;
}
vector<int> mp[MAX];
int in[MAX];
int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		in[i]=dp[i]=0;
		mp[i].clear();
	}
	while(m--)
	{
		scanf("%d%d",&a,&b);
		in[b]++;
		mp[a].push_back(b);
	}
	topsort(n,mp,in);
	for(i=1;i<=n;i++) printf("%d\n",dp[i]+1);
	return 0;
}
