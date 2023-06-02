#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int> mp[1005];
int cnt[1005],flag[1005];
void dfs(int x)
{
	if(flag[x]) return;
	flag[x]=1;
	cnt[x]++;
	for(int i=0;i<mp[x].size();i++) dfs(mp[x][i]);
}
int main()
{
	int n,m,k,i,a,b,ans;
	scanf("%d%d%d",&k,&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		cnt[i]=0;
	}
	vector<int> res(k);
	for(i=0;i<res.size();i++) scanf("%d",&res[i]);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
	}
	for(i=0;i<res.size();i++)
	{
		memset(flag,0,sizeof flag);
		dfs(res[i]);
	}
	ans=0;
	for(i=1;i<=n;i++) ans+=(cnt[i]==k);
	printf("%d\n",ans);
	return 0;
}
