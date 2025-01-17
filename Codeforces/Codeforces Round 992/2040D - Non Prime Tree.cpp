#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
vector<int> mp[MAX];
int res[MAX],now;
void dfs(int x,int fa)
{
	int f=0;
	res[x]=now;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		if(!f) now++;
		else now+=2;
		dfs(to,x);
		if(!f) now++;
		f=1;
	}
}
int main()
{
	int T,n,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		now=1;
		dfs(1,0);
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
	return 0;
}

