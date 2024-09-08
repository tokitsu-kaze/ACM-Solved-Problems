#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=4e5+10;
set<int> px[MAX],py[MAX];
int main()
{
	int n,m,q,x,y,z,i,j,ans;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++) px[i].clear();
	for(i=1;i<=m;i++) py[i].clear();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			px[i].insert(j);
			py[j].insert(i);
		}
	}
	ans=n*m;
	while(q--)
	{
		scanf("%d%d",&x,&y);
		if(px[x].count(y))
		{
			px[x].erase(y);
			py[y].erase(x);
			ans--;
		}
		else
		{
			if(px[x].size()>0)
			{
				auto it=px[x].lower_bound(y);
				if(it!=px[x].end())
				{
					z=*it;
					px[x].erase(z);
					py[z].erase(x);
					ans--;
				}
				it=px[x].lower_bound(y);
				if(it!=px[x].begin())
				{
					it--;
					z=*it;
					px[x].erase(z);
					py[z].erase(x);
					ans--;
				}
			}
			if(py[y].size()>0)
			{
				auto it=py[y].lower_bound(x);
				if(it!=py[y].end())
				{
					z=*it;
					py[y].erase(z);
					px[z].erase(y);
					ans--;
				}
				it=py[y].lower_bound(x);
				if(it!=py[y].begin())
				{
					it--;
					z=*it;
					py[y].erase(z);
					px[z].erase(y);
					ans--;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
