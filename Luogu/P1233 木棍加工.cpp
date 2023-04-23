#include <bits/stdc++.h>
using namespace std;
const int MAX=5000+10;
struct node
{
	int l,w;
}a[MAX];
int dp[MAX];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].w);
	sort(a+1,a+1+n,[&](node x,node y){
		if(x.l==y.l) return x.w>y.w;
		return x.l>y.l;
	});
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++)
	{
		dp[i]=1;
		for(j=1;j<i;j++)
		{
			if(a[j].w<a[i].w) dp[i]=max(dp[i],dp[j]+1);
		}
	}
	printf("%d\n",*max_element(dp+1,dp+1+n));
	return 0;
}

