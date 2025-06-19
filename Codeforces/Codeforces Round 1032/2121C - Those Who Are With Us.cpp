#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
vector<int> mp[MAX],pos[MAX];
int main()
{
	int T,n,m,i,j,mx,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		mx=0;
		for(i=1;i<=n;i++)
		{
			mp[i]=vector<int>(m+1,0);
			for(j=1;j<=m;j++)
			{
				scanf("%d",&mp[i][j]);
				mx=max(mx,mp[i][j]);
			}
		}
		map<int,int> now;
		for(i=1;i<=n;i++)
		{
			pos[i].clear();
			for(j=1;j<=m;j++)
			{
				if(mp[i][j]==mx)
				{
					pos[i].push_back(j);
					now[j]++;
				}
			}
		}
		ans=mx;
		for(i=1;i<=n;i++)
		{
			for(auto &it:pos[i])
			{
				now[it]--;
				if(now[it]==0) now.erase(it);
			}
			if(now.size()<=1) ans=mx-1;
			for(auto &it:pos[i]) now[it]++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
