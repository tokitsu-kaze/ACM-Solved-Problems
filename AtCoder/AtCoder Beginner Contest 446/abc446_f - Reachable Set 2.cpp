#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
vector<int> mp[MAX];
set<int> os,ms;//outset,miss
void dfs(int x,int i)
{
	for(auto &to:mp[x])
	{
		if(to>i) os.insert(to);
		else
		{
			if(ms.count(to))
			{
				ms.erase(to);
				dfs(to,i);
			}
		}
	}
}
int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		if(a==b) continue;
		mp[a].push_back(b);
	}
	os.clear();
	ms.clear();
	for(auto &to:mp[1]) os.insert(to);
	printf("%d\n",(int)os.size());
	for(i=2;i<=n;i++)
	{
		if(os.count(i))
		{
			os.erase(i);
			dfs(i,i);
		}
		else ms.insert(i);
		if(ms.size()==0) printf("%d\n",(int)os.size());
		else puts("-1");
	}
	return 0;
}
