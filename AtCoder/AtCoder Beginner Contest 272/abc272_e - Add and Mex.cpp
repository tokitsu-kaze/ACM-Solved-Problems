#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
vector<int> res[MAX];
int main()
{
	int n,m,i,j;
	ll x,now;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) res[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		if(x>=0) now=0;
		else
		{
			now=(0-x+i-1)/i;
			x+=now*i;
		}
		for(j=now;j<=m;j++)
		{
			if(x>n) break;
			res[j].push_back(x);
			x+=i;
		}
	}
	for(i=1;i<=m;i++)
	{
		sort(res[i].begin(),res[i].end());
		res[i].resize(unique(res[i].begin(),res[i].end())-res[i].begin());
		j=0;
		while(j<res[i].size()&&j==res[i][j]) j++;
		printf("%d\n",j);
	}
	return 0;
}
