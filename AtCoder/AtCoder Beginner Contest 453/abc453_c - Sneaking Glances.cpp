#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int n,a[22],ans;
void dfs(int x,ll now,int cnt)
{
	if(x==n)
	{
		ans=max(ans,cnt);
		return;
	}
	if(now<0 && now+a[x]>0) dfs(x+1,now+a[x],cnt+1);
	else dfs(x+1,now+a[x],cnt);
	if(now>0 && now-a[x]<0) dfs(x+1,now-a[x],cnt+1);
	else dfs(x+1,now-a[x],cnt);
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		a[i]*=2;
	}
	ans=0;
	dfs(0,1,0);
	printf("%d\n",ans);
	return 0;
}
