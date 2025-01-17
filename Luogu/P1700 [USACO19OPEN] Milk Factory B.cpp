#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=20+10;
vector<int> mp[MAX];
int cnt;
void dfs(int x,int fa)
{
	cnt++;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
	}
}
int main()
{
	int n,i,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[b].push_back(a);
	}
	for(i=1;i<=n;i++)
	{
		cnt=0;
		dfs(i,0);
		if(cnt==n)
		{
			printf("%d\n",i);
			goto end;
		}
	}
	puts("-1");
	end:;
	return 0;
}
