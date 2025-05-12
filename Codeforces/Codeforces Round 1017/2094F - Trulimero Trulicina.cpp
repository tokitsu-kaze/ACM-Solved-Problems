#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,m,k,i,j,tot,f;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		vector<vector<int>> mp(n,vector<int>(m,0));
		tot=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				tot++;
				if(tot>k) tot=1;
				mp[i][j]=tot;
			}
		}
		for(i=1;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(mp[i][j]==mp[i-1][j])
				{
					if(j>0) swap(mp[i][j],mp[i][j-1]);
					else swap(mp[i][j],mp[i][j+1]);
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				printf("%d%c",mp[i][j]," \n"[j+1==m]);
			}
		}
	}
	return 0;
}

