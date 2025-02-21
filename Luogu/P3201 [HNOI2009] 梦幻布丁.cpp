#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int MAX=1e6+10;
set<int> pos[MAX];
int col[MAX];
int main()
{
	int n,m,i,op,x,y,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<MAX;i++) pos[i].clear();
	col[0]=col[n+1]=0;
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&col[i]);
		ans+=(col[i]!=col[i-1]);
		pos[col[i]].insert(i);
	}
	while(m--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&x,&y);
			if(x==y) continue;
			if(pos[x].size()>pos[y].size()) swap(pos[x],pos[y]);
			for(auto &it:pos[x])
			{
				if(it-1>=1) ans-=pos[y].count(it-1);
				if(it+1<=n) ans-=pos[y].count(it+1);
			}
			pos[y].insert(pos[x].begin(),pos[x].end());
			pos[x].clear();
		}
		else printf("%d\n",ans);
	}
	return 0;
}
