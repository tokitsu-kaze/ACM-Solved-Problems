#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
int a[MAX],ans[MAX];
map<int,int> cnt;
void dfs(int x,int fa,int f)
{
	cnt[a[x]]++;
	if(cnt[a[x]]>1) f=1;
	ans[x]=f;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x,f);
	}
	cnt[a[x]]--;
}
int main()
{
	int n,i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mp[i].clear();
		ans[i]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	cnt.clear();
	dfs(1,0,0);
	for(i=1;i<=n;i++)
	{
		if(ans[i]) puts("Yes");
		else puts("No");
	}
	return 0;
}
