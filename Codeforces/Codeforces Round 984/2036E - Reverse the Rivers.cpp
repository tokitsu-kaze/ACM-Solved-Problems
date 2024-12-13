#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
vector<int> mp[MAX];
int main()
{
	int n,m,q,k,x,v,i,j,l,r,nowl,nowr;
	char op[2];
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=m;i++) mp[i].clear();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&x);
			mp[j].push_back(x);
		}
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<n;j++)
		{
			mp[i][j]|=mp[i][j-1];
		}
	}
	while(q--)
	{
		scanf("%d",&k);
		l=0;
		r=n-1;
		while(k--)
		{
			scanf("%d%s%d",&x,op,&v);
			if(op[0]=='>')
			{
				nowr=n-1;
				nowl=upper_bound(mp[x].begin(),mp[x].end(),v)-mp[x].begin();
			}
			else
			{
				nowl=0;
				nowr=lower_bound(mp[x].begin(),mp[x].end(),v)-mp[x].begin()-1;
			}
			l=max(l,nowl);
			r=min(r,nowr);
		}
		if(l>r) puts("-1");
		else printf("%d\n",l+1);
	}
	return 0;
}
