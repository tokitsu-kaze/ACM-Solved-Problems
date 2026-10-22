#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
vector<int> topsort(int n,vector<int> mp[],int *in)
{
	int i,x;
	priority_queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(!in[i]) q.push(i);
	}
	vector<int> toplist;
	while(!q.empty())
	{
		x=q.top();
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
vector<int> mp[MAX];
int in[MAX];
int main()
{
	int T,n,m,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			in[i]=0;
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[b].push_back(a);
			in[a]++;
		}
		auto res=topsort(n,mp,in);
		if(res.size()!=n)
		{
			puts("Impossible!");
			continue;
		}
		reverse(res.begin(),res.end());
		for(i=0;i<n;i++) printf("%d%c",res[i]," \n"[i+1==n]);
	}
	return 0;
}
/*
字典序最小 -> 正着拓扑，小的先出；
小的数尽可能靠前 -> 倒着拓扑，大的先出。
*/
