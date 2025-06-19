#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int res[105][105],vis[105][105],incir[105][105];
int main()
{
	int T,n,i,j,k,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(res,0,sizeof res);
		memset(vis,0,sizeof vis);
		memset(incir,0,sizeof incir);
		for(k=1;k<n;k++)
		{
			for(i=1;i<=k;i++)
			{
				if(vis[i][(i+k)%n==0?n:(i+k)%n]) continue;
				vector<int> tmp;
				tmp.push_back(i);
				x=i;
				while(1)
				{
					x=(x+k)%n;
					if(x==0) x=n;
					if(incir[tmp.back()][x])
					{
						tmp.clear();
						break;
					}
					incir[tmp.back()][x]=incir[x][tmp.back()]=1;
					tmp.push_back(x);
					if(x==i) break;
				}
				if(tmp.size()<=3) continue;
				for(i=0;i+1<tmp.size();i++)
				{
//					cout<<tmp[i]<<" ";
					incir[tmp[i]][tmp[i+1]]=incir[tmp[i+1]][tmp[i]]=0;
					if(tmp[i]<tmp[i+1]) res[tmp[i]][tmp[i+1]]=1;
					else res[tmp[i+1]][tmp[i]]=-1;
					vis[tmp[i]][tmp[i+1]]=vis[tmp[i+1]][tmp[i]]=1;
				}
//				puts("");
			}
		}
		vector<int> ans;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++) ans.push_back(res[i][j]);
		}
		for(i=0;i<ans.size();i++) printf("%d%c",ans[i]," \n"[i+1==ans.size()]);
	}
	return 0;
}

