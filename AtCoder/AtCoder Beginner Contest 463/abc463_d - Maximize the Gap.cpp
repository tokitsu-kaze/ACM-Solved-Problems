#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int l,r;}a[MAX];
int n,k,dp[MAX],tmpr[MAX];
int ck(int x)
{
	int i,j,mx,pos;
	mx=0;
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		pos=lower_bound(tmpr+1,tmpr+1+n,a[i].l-x+1)-tmpr-1;
		dp[i]=max(dp[i-1],dp[pos]+1);
//		printf("%d %d\n",i,dp[i]);
	}
	return dp[n]>=k;
}
int main()
{
	int i,l,r,mid;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+1+n,[](node x,node y){
		return x.r<y.r;
	});
	tmpr[0]=0;
	for(i=1;i<=n;i++) tmpr[i]=a[i].r;
	l=1;
	r=1e9;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid+1)) l=mid+1;
		else r=mid;
	}
	if(ck(l)) printf("%d\n",l);
	else puts("-1");
	return 0;
}
