#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e4+10;
vector<int> mp[MAX];
int flag[MAX],col[MAX],ra,rb;
void dfs(int x,int c)
{
	if(ra==-1) return;
	if(flag[x]) return;
	flag[x]=1;
	col[x]=c;
	if(c) ra++;
	else rb++;
	for(auto &to:mp[x])
	{
		if(col[to]==-1) dfs(to,c^1);
		else
		{
			if(col[to]==c)
			{
				ra=rb=-1;
				return;
			}
		}
	}
}
int main()
{
	int n,m,i,a,b,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		flag[i]=0;
		col[i]=-1;
	}
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(flag[i]) continue;
		ra=rb=0;
		dfs(i,0);
		if(ra==-1)
		{
			ans=-1;
			break;
		}
		else ans+=min(ra,rb);
	}
	if(ans==-1) puts("Impossible");
	else printf("%d\n",ans);
	return 0;
}
