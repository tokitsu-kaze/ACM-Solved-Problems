#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
vector<int> pos[MAX];
int ans[MAX];
int main()
{
	int q,op,x,y,i,n;
	for(i=0;i<MAX;i++) pos[i].clear();
	scanf("%d",&q);
	n=0;
	while(q--)
	{
		scanf("%d%d",&op,&x);
		if(op==1) pos[x].push_back(++n);
		else
		{
			scanf("%d",&y);
			if(x==y) continue;
			if(pos[x].size()>pos[y].size()) swap(pos[x],pos[y]);
			for(auto &it:pos[x]) pos[y].push_back(it);
			pos[x].clear();
		}
	}
	for(i=0;i<MAX;i++)
	{
		for(auto &it:pos[i]) ans[it]=i;
	}
	for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}
