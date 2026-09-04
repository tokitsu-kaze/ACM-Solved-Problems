#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
set<int> sx[MAX],sy[MAX];
int main()
{
	int n,m,i,x,y,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		sx[i].clear();
		sy[i].clear();
	}
	while(m--)
	{
		scanf("%d%d",&x,&y);
		vector<int> delx,dely;
		for(auto &it:sx[x]) delx.push_back(it);
		for(auto &it:sy[y]) dely.push_back(it);
		sx[x].clear();
		sy[y].clear();
		for(auto &it:delx) sy[it].erase(x);
		for(auto &it:dely) sx[it].erase(y);
		sx[x].insert(y);
		sy[y].insert(x);
	}
	ans=0;
	for(i=1;i<=n;i++) ans+=sx[i].size();
	printf("%d\n",ans);
	return 0;
}
