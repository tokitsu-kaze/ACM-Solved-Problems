#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
int main()
{
	int n,m,k,i,vis[12][12],a,b,ok,vis2[12];
	scanf("%d%d%d",&n,&m,&k);
	memset(vis,0,sizeof vis);
	memset(vis2,0,sizeof vis2);
	vector<int> ans;
	while(k--)
	{
		scanf("%d%d",&a,&b);
		vis[a][b]=1;
		if(vis2[a]) continue;
		ok=1;
		for(i=1;i<=m;i++) ok&=vis[a][i];
		if(ok)
		{
			ans.push_back(a);
			vis2[a]=1;
		}
	}
	for(auto &it:ans) printf("%d ",it);
	return 0;
}
