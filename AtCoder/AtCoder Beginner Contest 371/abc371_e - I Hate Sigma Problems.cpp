#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
vector<int> pos[MAX];
int main()
{
	int n,i,j,x;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		pos[i].clear();
		pos[i].push_back(0);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		pos[x].push_back(i);
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<pos[i].size();j++)
		{
			ans+=1LL*(pos[i][j]-pos[i][j-1])*(n-pos[i][j]+1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}

