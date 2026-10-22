#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int n,w,a[22],b[22];
ll ans;
void dfs(int x,ll now,ll v)
{
	if(now>w) return;
	ans=max(ans,v);
	if(x==n) return;
	dfs(x+1,now,v);
	dfs(x+1,now+b[x],v+a[x]);
}
int main()
{
	int i;
	scanf("%d%d",&n,&w);
	for(i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]);
	ans=0;
	dfs(0,0,0);
	printf("%lld\n",ans);
	return 0;
}
