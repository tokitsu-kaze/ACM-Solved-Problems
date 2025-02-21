#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=1e9+7;
const int MAX=1.2e6+10;
vector<int> pos[MAX];
int ans[MAX],cnt[MAX];
int vis[MAX];
int main()
{
	int n,k,i,j,now,x;
	scanf("%d%d",&n,&k);
	for(i=1;i<MAX;i++)
	{
		pos[i].clear();
		ans[i]=cnt[i]=vis[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		pos[x].push_back(i);
		cnt[x]++;
	}
	for(i=1000000;i;i--)
	{
		now=0;
		for(j=i;j<=1000000;j+=i)
		{
			now+=cnt[j];
		}
		if(now>=k)
		{
			for(j=i;j<=1000000;j+=i)
			{
				if(vis[j]) continue;
				vis[j]=1;
				for(auto &it:pos[j]) ans[it]=i;
			}
		}
	}
	for(i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
