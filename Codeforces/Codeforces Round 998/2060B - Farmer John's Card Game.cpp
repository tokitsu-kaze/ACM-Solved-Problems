#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
vector<int> mp[MAX];
int p[MAX];
int main()
{
	int T,n,m,i,j,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			mp[i].resize(m);
			for(j=0;j<m;j++) scanf("%d",&mp[i][j]);
			sort(mp[i].begin(),mp[i].end());
		}
		ok=1;
		for(i=0;i<n;i++)
		{
			if(mp[i][0]>=n)
			{
				ok=0;
				break;
			}
			else p[mp[i][0]]=i;
		}
		if(!ok)
		{
			puts("-1");
			continue;
		}
		for(j=0;j<m;j++)
		{
			for(i=1;i<n;i++)
			{
				if(mp[p[i-1]][j]>mp[p[i]][j]) ok=0;
			}
		}
		if(ok)
		{
			for(i=0;i<n;i++) printf("%d%c",p[i]+1," \n"[i+1==n]);
		}
		else puts("-1");
	}
	return 0;
}
/*
1
2 3
1 2 3
4 5 6
*/
