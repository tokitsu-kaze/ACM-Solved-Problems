#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int MAX=2e5+10;
int main()
{
	int n,m,i,vis[1010],x;
	scanf("%d%d",&n,&m);
	memset(vis,0,sizeof vis);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&x);
		vis[x]=1;
	}
	vector<int> res;
	for(i=1;i<=n;i++)
	{
		if(!vis[i]) res.push_back(i);
	}
	printf("%d\n",res.size());
	for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
	return 0;
}
