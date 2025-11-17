#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int mp[105][105];
int main()
{
	int T,n,m,i,j,k,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		vector<pair<int,int>> tmp;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&x);
				tmp.push_back({x,i});
				mp[i][j]=0;
			}
		}
		sort(tmp.begin(),tmp.end());
		for(k=0;k<m;k++) mp[tmp[k].second][k]=tmp[k].first;
		for(k=m;k<tmp.size();k++)
		{
			for(j=0;j<m;j++)
			{
				if(mp[tmp[k].second][j]==0)
				{
					mp[tmp[k].second][j]=tmp[k].first;
					break;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++) printf("%d%c",mp[i][j]," \n"[j+1==m]);
		}
	}
	return 0;
}
