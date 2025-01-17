#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
ll a[MAX],ans,res;
int n,k;
void dfs(int x,ll now,int cnt)
{
	if(cnt==k)
	{
		ans=max(ans,now^res);
		return;
	}
	if(x==n) return;
	if(k-cnt>n-x) return;
	dfs(x+1,now^a[x],cnt+1);
	dfs(x+1,now,cnt);
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	res=0;
	if(k>n/2)
	{
		for(i=0;i<n;i++) res^=a[i];
		k=n-k;
	}
	ans=0;
	if(k==1)
	{
		for(i=0;i<n;i++) ans=max(ans,a[i]^res);
	}
	else if(k==2)
	{
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				ans=max(ans,a[i]^a[j]^res);
			}
		}
	}
	else dfs(0,0,0);
	printf("%lld\n",ans);
	return 0;
}
