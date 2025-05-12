#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int x,y,z;};
vector<int> pos[MAX];
int cnt[MAX];
int main()
{
	int T,n,m,i,j,tot,x,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		vector<vector<int>> mp(n,vector<int>(m));
		for(i=0;i<m;i++) pos[i].clear();
		tot=0;
		for(i=0;i<n;i++)
		{
			cnt[i]=0;
			for(j=0;j<m;j++)
			{
				scanf("%d",&mp[i][j]);
				cnt[i]+=mp[i][j];
				if(mp[i][j]) pos[j].push_back(i);
			}
			tot+=cnt[i];
		}
		if(tot%n)
		{
			puts("-1");
			continue;
		}
		tot/=n;
		vector<node> res;
		ok=1;
		for(i=0;i<n;i++)
		{
			if(cnt[i]>=tot) continue;
			for(j=0;j<m;j++)
			{
				if(cnt[i]==tot) break;
				if(mp[i][j]==0)
				{
					while(pos[j].size()>0)
					{
						x=pos[j].back();
						pos[j].pop_back();
						if(cnt[x]>tot)
						{
							cnt[x]--;
							cnt[i]++;
							res.push_back({i,x,j});
							break;
						}
					}
				}
			}
			if(cnt[i]<tot) ok=0;
		}
		if(!ok) puts("-1");
		else
		{
			printf("%d\n",(int)res.size());
			for(auto &it:res) printf("%d %d %d\n",it.x+1,it.y+1,it.z+1);
		}
	}
	return 0;
}

