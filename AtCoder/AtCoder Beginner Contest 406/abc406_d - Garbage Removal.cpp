#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> idx[MAX],idy[MAX];
int main()
{
	int n,m,k,i,x,y,op,q,ans;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		idx[x].push_back(y);
		idy[y].push_back(x);
	}
	map<pair<int,int>,int> mp;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			ans=0;
			for(auto &y:idx[x])
			{
				if(!mp.count({x,y})) ans++;
				mp[{x,y}]=1;
			}
			printf("%d\n",ans);
			idx[x].clear();
		}
		else
		{
			ans=0;
			for(auto &y:idy[x])
			{
				if(!mp.count({y,x})) ans++;
				mp[{y,x}]=1;
			}
			printf("%d\n",ans);
			idy[x].clear();
		}
	}
	return 0;
}
