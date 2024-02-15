#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
vector<int> topsort(int n,vector<int> mp[],int *in)
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(!in[i]) q.push(i);
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
vector<int> mp[MAX];
int in[MAX];
int main()
{
	int t,n,k,i,x,pre;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			in[i]=0;
		}
		while(k--)
		{
			scanf("%d",&x);
			for(i=2;i<=n;i++)
			{
				scanf("%d",&x);
				if(i>2)
				{
					mp[pre].push_back(x);
					in[x]++;
				}
				pre=x;
			}
		}
		if(topsort(n,mp,in).size()==n) puts("YES");
		else puts("NO");
	}
	return 0;
}
